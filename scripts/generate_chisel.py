# script to run tests
import argparse

# get user input for length of ref and query
parser = argparse.ArgumentParser(
    prog = 'create_test'
)
parser.add_argument("-r","--r_len")
parser.add_argument("-q","--q_len")
args = parser.parse_args()
r_len = args.r_len
q_len = args.q_len

filename = "src/main/scala/sw_chisel/SWChisel.scala"

f1 = open("scripts/swchisel.txt","r")

driver = """
 \n\nobject SWDriver extends App {
  val debug = true
  val alpha = 2
  val beta = 1
  val similarity = 2
  val r_len = """+str(r_len)+"""
  val q_len = """+str(q_len)+"""
  val dataSize = 16 
  val p = new SWParams(debug,alpha,beta,similarity,dataSize,r_len,q_len)
  (new ChiselStage).emitVerilog(new SW(p), args)
}
"""

f = open(filename,"w")
f.write(f1.read())
f.write(driver)
f.close()
