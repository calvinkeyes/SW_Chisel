// See README.md for license details.

package SWChisel

import chisel3._
import chiseltest._
import scala.math._
import scala.util._
import org.scalatest.flatspec.AnyFlatSpec

class SWChisel extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "SWCell"
  it should  "print hello world" in {
    val p = new SWParams(2,3,8,false)
    test(new SWCell(p)) { dut =>
      dut.io.q.poke(1.U)
	  }
  }

  it should "Do a simple test" in {
    val gap = 2
    val sub = 3
    val dataSize = 8
    val fourBit = false
    val p = new SWParams(gap,sub,dataSize,fourBit)
    val s = SWModel(p)
    test(new SWCell(p)).withAnnotations(Seq(WriteVcdAnnotation)) { dut => 
      val result = s.computeCell(1,1,3,3,3)
      dut.io.q.poke(1.U)
      dut.io.r.poke(1.U)
      dut.io.top.poke(3.U)
      dut.io.diag.poke(3.U)
      dut.io.left.poke(3.U)
      dut.clock.step()
      dut.io.result.expect(result)
      // print(result)
    }
  }

  it should "test underflow conditions" in {
    val gap = 2
    val sub = 3
    val dataSize = 8
    val fourBit = false
    val p = new SWParams(gap,sub,dataSize,fourBit)
    val s = SWModel(p)
    test(new SWCell(p)).withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
      val result = s.computeCell(2,1,0,0,0)
      dut.io.q.poke(2.U)
      dut.io.r.poke(1.U)
      dut.io.top.poke(0.U)
      dut.io.diag.poke(0.U)
      dut.io.left.poke(0.U)
      dut.clock.step()
      dut.io.result.expect(result)
      // print(result)
    }
  }

  it should "test overflow conditions" in {
    val gap = 2
    val sub = 3
    val dataSize = 8
    val fourBit = false
    val p = new SWParams(gap,sub,dataSize,fourBit)
    val s = SWModel(p)
    test(new SWCell(p)).withAnnotations(Seq(WriteVcdAnnotation)) { dut => 
      val result = s.computeCell(3,3,255,255,255) 
      dut.io.q.poke(3.U)
      dut.io.r.poke(3.U)
      dut.io.top.poke(255.U)
      dut.io.diag.poke(255.U)
      dut.io.left.poke(255.U)
      dut.clock.step()
      dut.io.result.expect(result)
      // print(result)
    }
  }
    
  it should "exhaustively test SWCell (without running out of data)" in {
      // parameters
      val gap = 2
      val sub = 3
      val dataSize = 8
      val fourBit = false
      // Models
      val p = new SWParams(gap,sub,dataSize,fourBit)
      val s = SWModel(p)
      test(new SWCell(p)).withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
          // Test Variables
          val top = Seq.tabulate((pow(2,5)).toInt)(n => n*8)
          val diag = Seq.tabulate((pow(2,5)).toInt)(n => n*8)
          val left = Seq.tabulate((pow(2,5)).toInt)(n => n*8)
          val rand = scala.util.Random
          for (i <- 0 until top.length) {
            for (j <- 0 until diag.length) {
              for (k <- 0 until left.length) {
                val q = rand.nextInt(4)
                val r = rand.nextInt(4)
                // calculate model result
                val result = s.computeCell(q,r,top(i),diag(j),left(k))
                // poke SWCell
                dut.io.q.poke(q.U)
                dut.io.r.poke(r.U)
                dut.io.top.poke(top(i).U)
                dut.io.diag.poke(diag(j).U)
                dut.io.left.poke(left(k).U)
                dut.clock.step()
                // print("Test: "+i+" "+j+" "+k+" "+q+" "+r+" "+result+"\n")
                dut.io.result.expect(result)
              }
            }
          }
      }
  }

  // it should "randomly test SWCell" in { }




}
