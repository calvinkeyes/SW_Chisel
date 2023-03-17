// See README.md for license details.
package SWChisel

import chisel3._
import chisel3.util._
import chisel3.stage.ChiselStage

class SWIO extends Bundle {
  val q = Input(UInt(2.W))
  val r = Input(UInt(2.W))

  val top = Input(UInt(8.W))
  val diag = Input(UInt(8.W))
  val left = Input(UInt(8.W))

  val result = Output(UInt(8.W))
}


class SWCell(gap: Int, sub: Int) extends Module {
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
  when (gap.U >= io.top) {
    topWire := 0.U
  } .otherwise {
    topWire := io.top - gap.U
  }
  // check for underflow
  when (gap.U >= io.left) {
    leftWire := 0.U
  } .otherwise {
    leftWire := io.left - gap.U
  }
  // check for overflow and underflow
  when (io.q === io.r ) {
    when (io.diag +& sub.U > 255.U) {
      diagWire := 255.U
    } .otherwise {
      diagWire := io.diag + sub.U
    }
  } .otherwise {
    when (sub.U >= io.diag) {
      diagWire := 0.U
    } .otherwise {
      diagWire := io.diag - sub.U
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

class SW(gap: Int, sub: Int) extends Module {
  val io = IO(new SWIO)

  val cell = Module(new SWCell(gap,sub))
  io <> cell.io

  printf("In SW\n")
}

object SWDriver extends App {
  (new ChiselStage).emitVerilog(new SW(2,3), args)
}
