// See README.md for license details.

package SWChisel

import chisel3._
import chiseltest._
import scala.math._
import scala.util._
import org.scalatest.flatspec.AnyFlatSpec

class SWChiselTester extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "SWCell"
  it should "do a simple test" in {
    val alpha = 2
    val beta = 1
    val similarity = 2
    val dataSize = 16
    val r_len = 10
    val q_len = 6
    val p = new SWParams(alpha,beta,similarity,dataSize,r_len,q_len)
    val s = new SWCellModel(p)
    test(new SWCell(p)).withAnnotations(Seq(WriteVcdAnnotation)) { dut => 
      val (res0,res1,res2) = s.computeCell(0,0,-2,0,-2,0,0)
      dut.io.q.poke(1.U)
      dut.io.r.poke(1.U)
      dut.io.e_i.poke(-2.S)
      dut.io.f_i.poke(0.S)
      dut.io.ve_i.poke(-2.S)
      dut.io.vf_i.poke(0.S)
      dut.io.vv_i.poke(0.S)
      dut.clock.step()
      dut.io.e_o.expect(res0)
      dut.io.f_o.expect(res1)
      dut.io.v_o.expect(res2)
    }
  }
  
  // behavior of "SWCell"
  it should "do a more extensive test (dataSize = 16)" in {
      val alpha = 2
      val beta = 1
      val similarity = 2
      val dataSize = 16
      val r_len = 10
      val q_len = 6
      val p = new SWParams(alpha,beta,similarity,dataSize,r_len,q_len)
      val s = new SWCellModel(p)
      test(new SWCell(p)).withAnnotations(Seq(WriteVcdAnnotation)) { dut => 
        val ve_i = Seq(-2,  2, -3, 0,  0, -4, -1,  0, -1, -5,  2, -2, -2, -2, -6,  0,  0,  2,  1, -3, -7)
        val e_i = Seq( -2, -3, -3, 0, -4, -4, -1, -2, -5, -5, -3, -2, -3, -6, -6,  0, -3, -4, -4, -7, -7)
        val vf_i = Seq( 0,  0,  2, 0,  0, -2,  0, -1,  0, -1,  0,  2, -2, -2, -2,  0,  0,  0,  2,  1, -3)
        val f_i = Seq(  0,  0, -1, 0, -1,  0,  0, -1, -2, -1,  0, -1, -2, -2, -2,  0, -1,  0, -3, -4, -3)
        val vv_i = Seq( 0,  0, -2, 0,  2,  0,  0,  0,  0, -4,  0, -1,  0, -1, -5,  0,  2, -2, -2, -2, -6)
        val q = Seq(    0,  0,  0, 0,  1,  2,  0,  1,  2,  3,  0,  1,  2,  3,  0,  0,  1,  2,  3,  0,  1)
        val r = Seq(    0,  3,  1, 2,  3,  0,  0,  2,  3,  0,  1,  0,  2,  3,  0,  2,  1,  0,  2,  3,  0)
        val num_tests = 21
        for (i <- 0 until num_tests) {
          val (res0,res1,res2) = s.computeCell(q(i),r(i),e_i(i),f_i(i),ve_i(i),vf_i(i),vv_i(i))
          dut.io.q.poke(q(i).U)
          dut.io.r.poke(r(i).U)
          dut.io.e_i.poke(e_i(i).S)
          dut.io.f_i.poke(f_i(i).S)
          dut.io.ve_i.poke(ve_i(i).S)
          dut.io.vf_i.poke(vf_i(i).S)
          dut.io.vv_i.poke(vv_i(i).S)
          dut.clock.step()
          dut.io.e_o.expect(res0.S)
          dut.io.f_o.expect(res1.S)
          dut.io.v_o.expect(res2.S)

        }
      }   
  }

  behavior of "SWChisel"
  it should "print out the state at every cycle" in {
    val alpha = 2
    val beta = 1
    val similarity = 2
    val dataSize = 16
    val r_len = 10
    val q_len = 6
    val p = new SWParams(alpha,beta,similarity,dataSize,r_len,q_len)
    val s = new SWCellModel(p)
    val ref = "agtactgcga"
    val query = "actgac"
    test(new SW(p)).withAnnotations(Seq(WriteVcdAnnotation)) { dut => 
      // assign r values
      for (i <- 0 until r_len){
        if (ref(i) == 'a') {
          dut.io.r(i).b.poke(0.U)
        } else if (ref(i) == 'c') {
          dut.io.r(i).b.poke(1.U)
        } else if (ref(i) == 't') {
          dut.io.r(i).b.poke(2.U)
        } else {
          dut.io.r(i).b.poke(3.U)
        }
      }
      // assign q values
      for (i <- 0 until q_len){
        if (query(i) == 'a') {
          dut.io.q(i).b.poke(0.U)
        } else if (query(i) == 'c') {
          dut.io.q(i).b.poke(1.U)
        } else if (query(i) == 't') {
          dut.io.q(i).b.poke(2.U)
        } else {
          dut.io.q(i).b.poke(3.U)
        }
      }

      // print out all of the values from the 
      println()
      println()
      println("testing SWChisel")
      println()

      dut.clock.step()
      dut.io.start.poke(true.B)
      dut.clock.step()

      // print array
      for (j <- 0 to r_len + q_len){

        if ( j >= r_len) {
          dut.io.start.poke(false.B)
        }

        // print clock cycle
        println(s"cycle $j")
        println("")
      
        // print v1
        println("V1")
        println(dut.io.v_max.peek())
        println(dut.io.e_max_o.peek())
        println(dut.io.f_max_o.peek())
        println(dut.io.v_temp.peek())
        println()
        for (i <- 0 until p.v_len) {
          println(dut.io.v1_out(i).peek())
        }
        // print v2
        println("V2")
        for (i <- 0 until p.v_len) {
          println(dut.io.v2_out(i).peek())
        }
        // print e
        println("E")
        println(dut.io.e_max.peek())
        println(dut.io.e_i_out.peek())
        println(dut.io.ve_i_out.peek())
        println()
        for (i <- 0 until p.e_len) {
          println(dut.io.e_out(i).peek())
        }
        // print f
        println("F")
        for (i <- 0 until p.f_len) {
          println(dut.io.f_out(i).peek())
        }
        println()
        dut.clock.step()
      
      }


      
      println(dut.io.done.peek())
      println(dut.io.result.peek())
      // for  (i <- 0 until 30) {
      //   println(i)
      //   println(dut.io.done.peek())
      //   dut.clock.step()
      // }
      // println(dut.io.done.peek())










    }
  }

}
