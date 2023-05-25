package SWChisel

import chiseltest._
import scala.math._
import scala.util._
import org.scalatest.flatspec.AnyFlatSpec

class SWCellModelTester extends AnyFlatSpec with ChiselScalatestTester {
    behavior of "SWCellModel" 
    it should "Check score (dataSize = 16)" in {
        val debug = true
        val alpha = 2
        val beta = 1
        val similarity = 2
        val dataSize = 16
        val r_len = 10
        val q_len = 6
        val p = new SWParams(debug,alpha,beta,similarity,dataSize,r_len,q_len)
        val s = new SWCellModel(p)
        val ve_i = Seq(-2,  2, -3, 0,  0, -4, -1,  0, -1, -5,  2, -2, -2, -2, -6,  0,  0,  2,  1, -3, -7)
        val e_i = Seq( -2, -3, -3, 0, -4, -4, -1, -2, -5, -5, -3, -2, -3, -6, -6,  0, -3, -4, -4, -7, -7)
        val vf_i = Seq( 0,  0,  2, 0,  0, -2,  0, -1,  0, -1,  0,  2, -2, -2, -2,  0,  0,  0,  2,  1, -3)
        val f_i = Seq(  0,  0, -1, 0, -1,  0,  0, -1, -2, -1,  0, -1, -2, -2, -2,  0, -1,  0, -3, -4, -3)
        val vv_i = Seq( 0,  0, -2, 0,  2,  0,  0,  0,  0, -4,  0, -1,  0, -1, -5,  0,  2, -2, -2, -2, -6)
        val q = Seq(    0,  0,  0, 0,  1,  2,  0,  1,  2,  3,  0,  1,  2,  3,  0,  0,  1,  2,  3,  0,  1)
        val r = Seq(    0,  3,  1, 2,  3,  0,  0,  2,  3,  0,  1,  0,  2,  3,  0,  2,  1,  0,  2,  3,  0)
        val res = Seq((-3,-1,2),(0,-1,0),(-4,0,0),(-1,-1,-1),(-2,-2,0),(-5,-1,-1),(-2,-1,2),(-2,-2,-2),(-3,-2,-2),(-6,-2,-2),
                (0,-1,0),(-3,0,0),(-4,-3,2),(-4,-3,1),(-7,-3,-3),(-1,-1,-1),(-2,-2,4),(0,-1,0),(-1,0,0),(-5,-1,-1),(-8,-4,-4))
        val num_tests = 21
        for (i <- 0 until num_tests) {
            val result = s.computeCell(q(i),r(i),e_i(i),f_i(i),ve_i(i),vf_i(i),vv_i(i))
            assert(result == res(i))
            var pf = ""
            if (result == res(i))
                pf = "passed"
            else 
                pf = "failed"
            // print("test "+i+" out of "+num_tests+": "+pf+"\n")
            // print("\texpected: "+res(i)+" computed:"+result+"\n")
        }
    }


}