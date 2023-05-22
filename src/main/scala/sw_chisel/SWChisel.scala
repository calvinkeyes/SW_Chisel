// See README.md for license details.
package SWChisel

import chisel3._
import chisel3.util._
import chisel3.stage.ChiselStage
import scala.math._

case class SWParams(val alpha: Int, val beta: Int, val similarity: Int, val dataSize: Int,
  val r_len: Int, val q_len: Int) {

  // values for populating arrays
  val e_len = q_len
  val f_len = q_len + 1
  val v_len = q_len + 1
  
}

class SWBaseIO extends Bundle {
  val b = Input(UInt(2.W))
}

class SWIO(p: SWParams) extends Bundle {

  // set bitwidth of input base pairs
  val q = Vec(p.q_len, new SWBaseIO)
  val r = Vec(p.r_len, new SWBaseIO)

  // start
  val start = Input(Bool())

  // result
  val result = Output(SInt(p.dataSize.W))
  val done = Output(Bool())

  // Debugging output
  val v1_out = Vec(p.v_len, Output(SInt(p.dataSize.W)))
  val v2_out = Vec(p.v_len, Output(SInt(p.dataSize.W)))
  val e_out = Vec(p.e_len, Output(SInt(p.dataSize.W)))
  val f_out = Vec(p.f_len, Output(SInt(p.dataSize.W)))
  val e_max = Output(SInt(p.dataSize.W))
  val e_i_out = Output(SInt(p.dataSize.W))
  val ve_i_out = Output(SInt(p.dataSize.W))
  val v_max = Output(SInt(p.dataSize.W))
  val f_max_o = Output(SInt(p.dataSize.W))
  val e_max_o = Output(SInt(p.dataSize.W))
  val v_temp = Output(SInt(p.dataSize.W))
}

class SWCellIO(p: SWParams) extends Bundle {

  // base bair inputs
  val q = Input(UInt(2.W))
  val r = Input(UInt(2.W))

  // set input bitwidth
  val e_i = Input(SInt(p.dataSize.W))
  val f_i = Input(SInt(p.dataSize.W))
  val ve_i = Input(SInt(p.dataSize.W))
  val vf_i = Input(SInt(p.dataSize.W))
  val vv_i = Input(SInt(p.dataSize.W))

  // set result bitwidth
  val e_o = Output(SInt(p.dataSize.W))
  val f_o = Output(SInt(p.dataSize.W))
  val v_o = Output(SInt(p.dataSize.W))

  // debugging v
  val f_max_o = Output(SInt(p.dataSize.W))
  val e_max_o = Output(SInt(p.dataSize.W))
  val v_temp = Output(SInt(p.dataSize.W))
}

class SWCell(p: SWParams) extends Module {
  val io = IO(new SWCellIO(p))

  // instantiate temporary wires
  val e_max = WireInit(0.S(p.dataSize.W))
  val f_max = WireInit(0.S(p.dataSize.W))
  val v_max = WireInit(0.S(p.dataSize.W))
  val ef_temp = WireInit(0.S(p.dataSize.W))
  val v_temp = WireInit(0.S(p.dataSize.W))

  // assign outputs
  io.e_o := e_max
  io.f_o := f_max
  io.v_o := v_max

  // debugging outputs
  io.e_max_o := e_max
  io.f_max_o := f_max
  io.v_temp := v_temp

  // find e score
  when (io.ve_i - p.alpha.S >= io.e_i - p.beta.S) {
    e_max := io.ve_i - p.alpha.S
  } .otherwise {
    e_max := io.e_i - p.beta.S
  }

  // find f score
  when (io.vf_i - p.alpha.S > io.f_i - p.beta.S) {
    f_max := io.vf_i - p.alpha.S
  } .otherwise {
    f_max := io.f_i - p.beta.S
  }

  // compare e and f scores
  when (e_max > f_max) {
    ef_temp := e_max
  } .otherwise {
    ef_temp := f_max
  }

  // compare bases
  when (io.q === io.r) {
    v_temp := io.vv_i + p.similarity.S
  } .otherwise {
    v_temp := io.vv_i - p.similarity.S
  }

  // find v score
  when (v_temp > ef_temp) {
    v_max := v_temp
  } .otherwise {
    v_max := ef_temp
  }

}

class MAX(p: SWParams) extends Module {
  val io = IO(new Bundle {
    val start = Input(Bool())
    val in = Input(SInt(p.dataSize.W))
    val done = Output(Bool())
    val out = Output(SInt(p.dataSize.W))
  })

  val max = RegInit((-1*pow(2,p.dataSize-1).toInt).S(p.dataSize.W))
  io.out := max

  // calculate max value
  when (io.in > max) { 
    max := io.in 
  } .otherwise {
    max := max
  }

  // counter to calculate done
  val counter = RegInit(p.r_len.U)
  when (io.start) {
    counter := counter - 1.U
  } .otherwise {
    counter := counter
  }
  
  // calculate done
  when (counter === 0.U) {
    io.done := true.B
    counter := 0.U
  } .otherwise {
    io.done := false.B
  }

}

class MyCounter(maxVal: Int) extends Module {
    val io = IO(new Bundle {
        val en  = Input(Bool())
        val out = Output(UInt(log2Ceil(maxVal+1).W))
    })
    io.out := RegEnable(Mux(io.out < maxVal.U, io.out + 1.U, 0.U), 0.U, io.en)
}

class SW(p: SWParams) extends Module {
  val io = IO(new SWIO(p))

  // create and initialize arrays
  val E = RegInit(VecInit(Seq.tabulate(p.e_len)( i => ((-1*p.alpha)-((i)*p.beta)).S(p.dataSize.W) )))
  val F = RegInit(VecInit(Seq.fill(p.f_len)(0.S(p.dataSize.W))))
  val V1 = RegInit(VecInit(Seq.tabulate(p.v_len)( i => ((-1*p.alpha)-((i-1)*p.beta)).S(p.dataSize.W))))
  V1(0) := 0.S
  val V2 = RegInit(VecInit(Seq.fill(p.v_len)(0.S(p.dataSize.W))))
  val start_reg = RegInit(VecInit(Seq.fill(p.q_len)(false.B)))

  // create array of SW units
  val array = Seq.fill(p.q_len)(Module(new SWCell(p)))
  val r_count = Seq.fill(p.q_len)(Module(new MyCounter(p.q_len)))

  // create one max unit
  val max = Module(new MAX(p))

  // connect max io
  max.io.in := V1(p.q_len)
  max.io.start := start_reg(p.q_len-1)

  // assign io.output
  io.result := max.io.out
  io.done := max.io.done

  // assign e debugging
  io.e_max := array(0).io.e_o
  io.e_i_out := E(0)
  io.ve_i_out := V1(1)

  // assign e debugging
  io.v_max := array(0).io.v_o
  io.e_max_o := array(0).io.e_max_o
  io.f_max_o := array(0).io.f_max_o
  io.v_temp := array(0).io.v_temp

  // shift over start bit value
  start_reg(0) := io.start
  for (i <- 1 until start_reg.length) {
    start_reg(i) := start_reg(i-1)
  }

  // initialize r_count
  r_count(0).io.en := io.start
  for (i <- 1 until r_count.length) {
    r_count(i).io.en := start_reg(i-1)
  }
  
  // initialize array of SW units
  for (i <- 0 until p.q_len) {
    array(i).io.q := io.q(i).b
    array(i).io.r := io.r(r_count(i).io.out).b
  }
  printf(p"q(0): ${io.q(0).b} r(0): ${io.r(r_count(0).io.out).b}\n")

  for (i <- 0 until p.q_len){     // SW Cell 0 computes row 1. 
    array(i).io.e_i := E(i)     // Gather E from the same row from 1 cycle ago
    array(i).io.ve_i := V1(i+1)   // Gather V from the same row from 1 cycle ago
    array(i).io.f_i := F(i)       // Gather F from the row above from 1 cycle ago
    array(i).io.vf_i := V1(i)     // Gather V from the row above from 1 cycle ago
    array(i).io.vv_i := V2(i)     // Gather V from the row above from 2 cycles ago
    array(i).io.q := 0.U          // initialize q
    array(i).io.r := 0.U          // initialize r
  }

  // let registers start writing when the start bit is high
  for (i <- 0 until p.q_len) {
    when (start_reg(i)) {
      E(i) := array(i).io.e_o
      F(i+1) := array(i).io.f_o
      V1(i+1) := array(i).io.v_o
    } .otherwise {
      E(i) := E(i)
      F(i+1) := F(i+1)
      V1(i+1) := V1(i+1)
    }
  }

  // connect outputs
  for (i <- 0 until p.e_len) {
    io.e_out(i) := E(i)
  }

  for (i <- 0 until p.v_len) {
    io.f_out(i) := F(i)
    io.v1_out(i) := V1(i)
    io.v2_out(i) := V2(i)
  }

  // Shift over the bits from V1 to V2
  for (i <- 0 until p.v_len) {
    V2(i) := V1(i)
  }

}

object SWDriver extends App {
  val alpha = 2
  val beta = 1
  val similarity = 2
  val dataSize = 16
  val r_len = 10
  val q_len = 6
  val p = new SWParams(alpha,beta,similarity,dataSize,r_len,q_len)
  (new ChiselStage).emitVerilog(new SW(p), args)
}
