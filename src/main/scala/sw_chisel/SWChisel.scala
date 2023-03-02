// See README.md for license details.

package SWChisel

import chisel3._
import chisel3.util._
import chisel3.stage.ChiselStage

class SWCell extends Module {
  val io = IO(new Bundle {
    val in = Input(Bool())
    val out = Output(Bool())
  })

  printf("Hello World\n")
  io.out := !io.in
}

import chisel3.stage.ChiselStage

object SWCellDriver extends App {
  (new ChiselStage).emitVerilog(new SWCell, args)
}


// class MajorityCircuit extends Module {
//     val io = IO(new Bundle {
//         val a = Input(Bool())
//         val b = Input(Bool())
//         val c = Input(Bool())
//         val out = Output(Bool())
//     })
//     io.out := (io.a & io.b) | (io.a & io.c) | (io.b & io.c)
// }
