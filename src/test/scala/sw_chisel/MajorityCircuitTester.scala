// See README.md for license details.

package sw_chisel

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class MajorityCircuitTester extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "MajorityCircuit"
  it should "correctly pass tests on all 8 possible inputs" in {
    test(new MajorityCircuit) { dut =>
      
      for (i <- Seq(true, false)) {
        for (j <- Seq(true, false)) {
          for (k <- Seq(true, false)) {
            dut.io.a.poke(i.B)
            dut.io.b.poke(j.B)
            dut.io.c.poke(k.B)
            dut.io.out.expect(((i&&j)||(i&&k)||(j&&k)).B)
          }
        }
      }
    }
  }
}
