package SWChisel


class SWModel(query: String, ref: String, p: SWParams) {

    // need to define 2D array based on 
    val cell: SWCellModel = new SWCellModel(p)

    // define 2D arrays
    val v: Array[Array[Int]] = Array.ofDim[Int](p.q_len+1, p.r_len+1)
    val e: Array[Array[Int]] = Array.ofDim[Int](p.q_len+1, p.r_len+1)
    val f: Array[Array[Int]] = Array.ofDim[Int](p.q_len+1, p.r_len+1)

    // Initialize arrays
    for (j <- 0 to p.r_len) {
        v(0)(j) = 0
        e(0)(j) = 0
        f(0)(j) = 0
    }
    for (i <- 1 to p.q_len) {
        e(i)(0) = (-1*p.alpha) - ((i - 1) * p.beta)
        f(i)(0) = (-1*p.alpha) - ((i - 1) * p.beta)
        v(i)(0) = (-1*p.alpha) - ((i - 1) * p.beta)
    }

    def print_mat(in: Array[Array[Int]]): Unit =  {
        // Print Ref String
        for (j <- 0 to p.r_len) {
            if (j == 0) print("  -") else print("  "+ref(j-1))
            // if (j == 0) print("%3c".format("-")) else print("%3c".format(ref.charAt(j)))
        }
        println()

        // Print Scores and Query String
        for (i <- 0 to p.q_len) {
            for (j <- 0 to p.r_len) {
                if (j == 0 && i ==0) {
                    print("-")
                } else if (j == 0) {
                    print(query(i-1))
                }
                print("%3d".format(in(i)(j)))
            }
            print("\n")
        }
    }

    def print_state(): Unit = {
        print("E")
        print_mat(e)
        print("\nF")
        print_mat(f)
        print("\nV")
        print_mat(v)
        println()
    }

    def compute_mat(): Unit = {

        // loop through whole array to fill values
        for (i <- 1 until p.q_len+1){
            for (j <- 1 until p.r_len+1) {
                val (e_o,f_o,v_o) = cell.computeCell(query(i-1),ref(j-1),e(i)(j-1),f(i-1)(j),v(i)(j-1),v(i-1)(j),v(i-1)(j-1))
                e(i)(j) = e_o
                f(i)(j) = f_o
                v(i)(j) = v_o
            }
        }
    }

    def find_max(): Int = {
        var max = -32000
        for (j <- 1 to p.r_len){
            if (v(p.q_len)(j) > max) {
                max = v(p.q_len)(j)
            }
        }
        return max
    }

}

object SWModel {
    def apply(query: String, ref: String, p: SWParams): SWModel = {
        new SWModel(query,ref,p)
    }
}