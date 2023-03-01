// See README.md for license details.

package sw_chisel

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class HW1Tester extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "RiscvITypeDecoder"
  it should  "correctly decode instructions" in {
    test(new RiscvITypeDecoder) { c =>
      c.io.instWord.poke("h_dead_beef".U)
      c.io.opcode.expect("b_110_1111".U)
      c.io.funct3.expect("b_011".U)
      c.io.rs1.expect("b_11011".U)
      c.io.rd.expect("b_11101".U)
      c.io.immSignExtended.expect("h_ffff_fdea".U)
    }
  }

  // See src/test/scala/hw1/MajorityCircuitTester.scala for Problem2

  behavior of "PolyEval"
  it should "correctly calculate out" in {
    val c0 = 3
    val c1 = 2
    val c2 = 1
    test(new PolyEval(c0, c1, c2)) { dut =>
      dut.io.enable.poke(true.B)
      dut.io.x.poke(1.U)
      dut.io.out.expect(6.U)

      dut.io.enable.poke(false.B)
      dut.io.out.expect(0.U)

      dut.io.enable.poke(true.B)
      dut.io.x.poke(32.U)
      dut.io.out.expect(1091.U)

    }
  }

  behavior of "ComplexALU"
  it should "correctly calculate realOut onlyAdd=true" in {
    test(new ComplexALU(onlyAdder=true)) { dut =>
      dut.io.doAdd.poke(true.B)
      dut.io.real0.poke(15.S)
      dut.io.real1.poke(15.S)
      dut.io.realOut.expect(30.S)

      dut.io.doAdd.poke(false.B)
      dut.io.real1.poke(14.S)
      dut.io.realOut.expect(29.S)
    }
  }
  it should "correctly calculate realOut onlyAdd=false" in {
    test(new ComplexALU(onlyAdder = false)) { dut =>
      dut.io.doAdd.poke(true.B)
      dut.io.real0.poke(15.S)
      dut.io.real1.poke(3.S)
      dut.io.realOut.expect(18.S)

      dut.io.doAdd.poke(false.B)
      dut.io.realOut.expect(12.S)
    }
  }
  it should "correctly calculate imagOut onlyAdd=true" in {
    test(new ComplexALU(onlyAdder = true)) { dut =>
      dut.io.doAdd.poke(true.B)
      dut.io.imag0.poke(13.S)
      dut.io.imag1.poke(4.S)
      dut.io.imagOut.expect(17.S)

      dut.io.doAdd.poke(false.B)
      dut.io.imagOut.expect(17.S)
    }
  }
  it should "correctly calculate imagOut onlyAdd=false" in {
    test(new ComplexALU(onlyAdder = false)) { dut =>
      dut.io.doAdd.poke(true.B)
      dut.io.imag0.poke(13.S)
      dut.io.imag1.poke(5.S)
      dut.io.imagOut.expect(18.S)

      dut.io.doAdd.poke(false.B)
      dut.io.imagOut.expect(8.S)
    }
  }
}
