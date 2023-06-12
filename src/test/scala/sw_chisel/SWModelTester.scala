package SWChisel


import chiseltest._
import scala.math._
import scala.util._
import org.scalatest.flatspec.AnyFlatSpec

class SWModelTester extends AnyFlatSpec with ChiselScalatestTester {
    behavior of "SWModel" 
    it should "Check score (dataSize = 16)" in {
        val debug = true
        val alpha = 2
        val beta = 1
        val similarity = 2
        val dataSize = 16
        val r_len = 10
        val q_len = 6
        val p = new SWParams(debug,alpha,beta,similarity,dataSize,r_len,q_len)
        val s = new SWModel("agtcat","acagtcgatc",p)
        val num_tests = 21
        s.compute_mat()
        s.print_state()
    }

    it should "find the maximum value we could have" in {
        val debug = true
        val alpha = 2
        val beta = 1
        val similarity = 2
        val dataSize = 16
        val r_len = 10
        val q_len = 6

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
        val num = rand.nextInt(4)
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
        val s = new SWModel(query,ref,p)
        s.compute_mat()
        // s.print_state()
    }
}
