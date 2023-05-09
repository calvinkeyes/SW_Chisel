package SWChisel

import scala.math._

class SWCellModel(p: SWParams) {

    def computeCell(q: Int, r: Int, e_i: Int, f_i: Int, ve_i: Int, vf_i: Int, vv_i: Int): (Int,Int,Int) = {

        // generate values for e, f, and v
        val e_o = (ve_i - p.alpha).max(e_i - p.beta)
        // print("ve_i: "+ve_i+" p.alpha: "+p.alpha+"\n")
        val f_o = (vf_i - p.alpha).max(f_i - p.beta)
        val ef_temp = (e_o).max(f_o)
        val v_temp = if (q==r) vv_i + p.similarity else vv_i - p.similarity
        val v_o = (ef_temp).max(v_temp)
        return (e_o,f_o,v_o)

    }
}

object SWCellModel {
    def apply(p: SWParams): SWCellModel = {
        new SWCellModel(p)
    }
}