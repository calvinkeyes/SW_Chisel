// See README.md for license details.
package SWChisel

import chisel3._
import chisel3.util._
import chisel3.stage.ChiselStage

class SWIO extends Bundle {
  val in = Input(Bool())
  val out = Output(Bool())
}


class SWCell extends Module {
  val io = IO(new SWIO)

  printf("Hello World - in SWCell\n")
  io.out := !io.in
}

class SW extends Module {
  val io = IO(new SWIO)

  val cell = Module(new SWCell)
  io <> cell.io

  printf("In SW\n")
}

object SWDriver extends App {
  (new ChiselStage).emitVerilog(new SW, args)
}
