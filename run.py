# Run Scala testing on Chisel Model and C testing on Verilog Model
# Enter reference length and query length
import argparse
import os

# Get q_len and r_len
parser = argparse.ArgumentParser(
    prog = 'run'
)
parser.add_argument("-r","--r_len")
parser.add_argument("-q","--q_len")
args = parser.parse_args()
r_len = int(args.r_len)
q_len = int(args.q_len)

# Generate Chisel and Test it in Scala
os.system("python3 scripts/generate_chisel.py -r "+str(r_len)+" -q "+str(q_len))
os.system("sbt compile")
os.system("sbt test")
os.system("sbt \"run -e verilog --target-dir verilator\"")
os.system("cd verilator; rm *.fir *.anno.json")
os.system("python3 scripts/generate_ctest.py -r "+str(r_len)+" -q "+str(q_len))
os.system("cd verilator; make")