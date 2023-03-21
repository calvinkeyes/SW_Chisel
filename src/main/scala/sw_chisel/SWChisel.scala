// See README.md for license details.
package SWChisel

import chisel3._
import chisel3.util._
import chisel3.stage.ChiselStage

case class SWParams(val gap: Int, val sub: Int, val dataSize: Int) {
  // don't modify parameters
  // case class is just used as a struct to hold parameter values
}

class SWIO extends Bundle {
  val q = Input(UInt(2.W))
  val r = Input(UInt(2.W))

  val top = Input(UInt(8.W))
  val diag = Input(UInt(8.W))
  val left = Input(UInt(8.W))

  val result = Output(UInt(8.W))
}


class SWCell(p: SWParams) extends Module {
  val io = IO(new SWIO)

  // declare temporary value wires
  val topWire = WireInit(0.U)
  val leftWire = WireInit(0.U)
  val diagWire = WireInit(0.U)
  val topLeftWire = WireInit(0.U)
  val result = RegInit(0.U)

  // set output
  io.result := result

  // check for underflow
  when (p.gap.U >= io.top) {
    topWire := 0.U
  } .otherwise {
    topWire := io.top - p.gap.U
  }
  // check for underflow
  when (p.gap.U >= io.left) {
    leftWire := 0.U
  } .otherwise {
    leftWire := io.left - p.gap.U
  }
  // check for overflow and underflow
  when (io.q === io.r ) {
    when (io.diag +& p.sub.U > 255.U) {
      diagWire := 255.U
    } .otherwise {
      diagWire := io.diag + p.sub.U
    }
  } .otherwise {
    when (p.sub.U >= io.diag) {
      diagWire := 0.U
    } .otherwise {
      diagWire := io.diag - p.sub.U
    }
  }

  // set result value
  when (topWire > leftWire) {
    topLeftWire := topWire
  } .otherwise {
    topLeftWire := leftWire
  }

  when (diagWire > topLeftWire) {
    result := diagWire
  } .otherwise {
    result := topLeftWire
  }

  // printf("Hello World - in SWCell\n")

}

class SW(p: SWParams) extends Module {
  val io = IO(new SWIO)

  val cell = Module(new SWCell(p))
  io <> cell.io

  printf("In SW\n")
}

object SWDriver extends App {
  val p = new SWParams(2,3,8)
  (new ChiselStage).emitVerilog(new SW(p), args)
}
