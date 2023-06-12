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
    val debug = true
    val alpha = 2
    val beta = 1
    val similarity = 2
    val dataSize = 16
    val r_len = 10
    val q_len = 6
    val p = new SWParams(debug,alpha,beta,similarity,dataSize,r_len,q_len)
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
      val debug = true
      val alpha = 2
      val beta = 1
      val similarity = 2
      val dataSize = 16
      val r_len = 10
      val q_len = 6
      val p = new SWParams(debug,alpha,beta,similarity,dataSize,r_len,q_len)
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
  it should "test a known smith waterman array" in {
    val debug = true
    val alpha = 2
    val beta = 1
    val similarity = 2
    val dataSize = 16
    val r_len = 10
    val q_len = 6
    val ref = "agtactgcga"
    val query = "actgac"
    val p = new SWParams(debug,alpha,beta,similarity,dataSize,r_len,q_len)
    val s = new SWModel(query, ref, p)
    test(new SW(p)).withAnnotations(Seq(WriteVcdAnnotation)) { dut => 

      // compute model results
      s.compute_mat()
      
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

      dut.clock.step()
      dut.io.start.poke(true.B)
      dut.clock.step()
      dut.clock.step()

      var count = 1

      // ramp-up testing
      for (j <- 1 to q_len) {

        // check the ramp up registers
        for (i <- 0 until j) {
          dut.io.v1_out.get(i+1).expect(s.v(i+1)(j-i))
          dut.io.e_out.get(i).expect(s.e(i+1)(j-i))
          dut.io.f_out.get(i+1).expect(s.f(i+1)(j-i))
        }
        count = count + 1
        dut.clock.step()
      }

      // Test when pipeline is full
      for (j <- q_len+1 to r_len) {

        // check pipeline full registers
        for (i <- 0 until q_len) {
          dut.io.v1_out.get(i+1).expect(s.v(i+1)(j-i))
          dut.io.e_out.get(i).expect(s.e(i+1)(j-i))
          dut.io.f_out.get(i+1).expect(s.f(i+1)(j-i))
        }

        count = count + 1
        dut.clock.step()
      }

      // Test when emptying pipeline
      for (j <- r_len+1 until q_len+r_len) {

        // check ramp down registers
        var k = 0
        for (i <- q_len+r_len-j until 0 by -1) {
          dut.io.v1_out.get(q_len-i+1).expect(s.v(q_len-i+1)(r_len-k))
          dut.io.e_out.get(q_len-i).expect(s.e(q_len-i+1)(r_len-k))
          dut.io.f_out.get(q_len-i+1).expect(s.f(q_len-i+1)(r_len-k))
          k = k + 1
        }
        count = count + 1
        dut.clock.step()

      }
      dut.io.done.expect(true)
    }
  }

  it should "test a randomly generated smith waterman array" in {
    val debug = true
    val alpha = 2
    val beta = 1
    val similarity = 2
    val r_len = 10
    val q_len = 6
    val dataSize =  16//ceil(log(q_len*2)/log(2)).toInt + 1 //log2Ceil(q_len*2) + 1

    // generate random query
    val rand = scala.util.Random
    var query : String = ""
    for (i <- 0 until q_len) {
      val num = rand.nextInt(3)
      if (num == 0) {
        query = query.concat("a")
      } else if (num == 1) {
        query = query.concat("c")
      } else if (num == 2) {
        query = query.concat("t")
      } else if (num == 3) {
        query = query.concat("g")
      } else {
        println("ERROR STOP")
      }
    }

    // generate random ref
    var ref : String = ""
    for (i <- 0 until r_len) {
      val num = rand.nextInt(3)
      if (num == 0) {
        ref = ref.concat("a")
      } else if (num == 1) {
        ref = ref.concat("c")
      } else if (num == 2) {
        ref = ref.concat("t")
      } else if (num == 3) {
        ref = ref.concat("g")
      } else {
        println("ERROR STOP")
      }
    }

    val p = new SWParams(debug,alpha,beta,similarity,dataSize,r_len,q_len)
    val s = new SWModel(query, ref, p)
    test(new SW(p)).withAnnotations(Seq(WriteVcdAnnotation)) { dut => 

      // compute results
      s.compute_mat()
      
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

      dut.clock.step()
      dut.io.start.poke(true.B)
      dut.clock.step()
      dut.clock.step()

      var count = 1

      // ramp-up testing
      for (j <- 1 to q_len) {
        for (i <- 0 until j) {
          dut.io.v1_out.get(i+1).expect(s.v(i+1)(j-i))
          dut.io.e_out.get(i).expect(s.e(i+1)(j-i))
          dut.io.f_out.get(i+1).expect(s.f(i+1)(j-i))
        }
        count = count + 1
        dut.clock.step()
      }

      // Test when pipeline is full
      for (j <- q_len+1 to r_len) {

        // check pipeline full registers
        for (i <- 0 until q_len) {
          dut.io.v1_out.get(i+1).expect(s.v(i+1)(j-i))
          dut.io.e_out.get(i).expect(s.e(i+1)(j-i))
          dut.io.f_out.get(i+1).expect(s.f(i+1)(j-i))
        }

        count = count + 1
        dut.clock.step()
      }

      // Test when emptying pipeline
      for (j <- r_len+1 until q_len+r_len) {
        var k = 0
        for (i <- q_len+r_len-j until 0 by -1) {
          dut.io.v1_out.get(q_len-i+1).expect(s.v(q_len-i+1)(r_len-k))
          dut.io.e_out.get(q_len-i).expect(s.e(q_len-i+1)(r_len-k))
          dut.io.f_out.get(q_len-i+1).expect(s.f(q_len-i+1)(r_len-k))
          k = k + 1
        }
        count = count + 1
        dut.clock.step()

      }
      dut.io.done.expect(true)
      println("Smith-Waterman Scala Model Test Passed!")
    }
  }


}
