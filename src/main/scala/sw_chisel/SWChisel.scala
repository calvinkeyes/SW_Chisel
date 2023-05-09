// See README.md for license details.
package SWChisel

import chisel3._
import chisel3.util._
import chisel3.stage.ChiselStage
import scala.math._

case class SWParams(val alpha: Int, val beta: Int, val similarity: Int, val dataSize: Int,
  val r_len: Int, val q_len: Int) {

  // values for populating arrays
  val e_len = q_len + 1
  val f_len = r_len + 1
  val v_len = e_len
  
}

class SWIO(p: SWParams) extends Bundle {

  // set bitwidth of input base pairs
  val q = Input(UInt(2.W))
  val r = Input(UInt(2.W))
}

class SWCellIO(p: SWParams) extends SWIO(p: SWParams) {

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
}

class SWCell(p: SWParams) extends Module {
  val io = IO(new SWCellIO(p))

  val e_max = WireInit(0.S)
  val f_max = WireInit(0.S)
  val v_max = WireInit(0.S)
  val ef_temp = WireInit(0.S)
  val v_temp = WireInit(0.S)

  io.e_o := e_max
  io.f_o := f_max
  io.v_o := v_max

  // find e score
  when (io.ve_i - p.alpha.S > io.e_i - p.beta.S) {
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

  // find v score
  when (e_max > f_max) {
    ef_temp := e_max
  } .otherwise {
    ef_temp := f_max
  }

  when (io.q === io.r) {
    v_temp := io.vv_i + p.similarity.S
  } .otherwise {
    v_temp := io.vv_i - p.similarity.S
  }

  when (v_temp > ef_temp) {
    v_max := v_temp
  } .otherwise {
    v_max := ef_temp
  }

}

class SW(p: SWParams) extends Module {
  val io = IO(new SWCellIO(p))

  val cell = Module(new SWCell(p))
  io <> cell.io
  
  printf("In SW\n")
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
