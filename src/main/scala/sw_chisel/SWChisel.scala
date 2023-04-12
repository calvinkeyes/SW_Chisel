// See README.md for license details.
package SWChisel

import chisel3._
import chisel3.util._
import chisel3.stage.ChiselStage
import scala.math._

case class SWParams(val gap: Int, val sub: Int, val dataSize: Int, val fourBit: Boolean,
                    val fourArray: Boolean) {
  // used to check for overflow
  val max = pow(2,dataSize).toInt - 1
}

class SWIO(p: SWParams) extends Bundle {

  // set bitwidth of input base pairs
  val q = Input(UInt(2.W))
  val r = Input(UInt(2.W))
  if (p.fourBit) {
    val q = Input(UInt(4.W))
    val r = Input(UInt(4.W))
  }
}

class SWCellIO(p: SWParams) extends SWIO(p: SWParams) {
  // set scoring bitwidth
  val top = Input(UInt(p.dataSize.W))
  val diag = Input(UInt(p.dataSize.W))
  val left = Input(UInt(p.dataSize.W))

  // set result bitwidth
  val result = Output(UInt(p.dataSize.W))
}

class SWCell(p: SWParams) extends Module {
  val io = IO(new SWCellIO(p))

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
  when (if(p.fourBit) (io.q & io.r).asBools.reduce{_ | _} else io.q === io.r ) {
    when (io.diag +& p.sub.U > p.max.U) {
      diagWire := p.max.U
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
  val io = IO(new SWIO(p))

  val cell0 = Module(new SWCell(p))
  io <> cell0.io

  if (p.fourArray) {
    val cell1 = Module(new SWCell(p))
    val cell2 = Module(new SWCell(p))
    val cell3 = Module(new SWCell(p))
  }


  printf("In SW\n")
}

object SWDriver extends App {
  val gap = 2
  val sub = 3
  val dataSize = 8
  val fourBit = false
  val fourArray = false
  val p = new SWParams(gap,sub,dataSize,fourBit,fourArray)
  (new ChiselStage).emitVerilog(new SW(p), args)
}
