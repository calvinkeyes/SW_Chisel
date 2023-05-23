package SWChisel


import chiseltest._
import scala.math._
import scala.util._
import org.scalatest.flatspec.AnyFlatSpec

class SWModelTester extends AnyFlatSpec with ChiselScalatestTester {
    behavior of "SWModel" 
    it should "Check score (dataSize = 16)" in {
        val alpha = 2
        val beta = 1
        val similarity = 2
        val dataSize = 16
        val r_len = 10
        val q_len = 6
        val p = new SWParams(alpha,beta,similarity,dataSize,r_len,q_len)
        val s = new SWModel("actgac","agtactgcga",p)
        val num_tests = 21
        s.print_state()
        s.compute_mat()
        s.print_state()
        println("max: "+s.find_max().toString())
    }

    it should "get values from internal matrices" in {
        val alpha = 2
        val beta = 1
        val similarity = 2
        val dataSize = 16
        val r_len = 10
        val q_len = 6
        val p = new SWParams(alpha,beta,similarity,dataSize,r_len,q_len)
        val s = new SWModel("actgac","agtactgcga",p)
        s.compute_mat()
        println(s.v(1)(1))
    }
}
