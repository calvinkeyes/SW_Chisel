# script to generate c test bench
import argparse

# get user input for length of ref and query
parser = argparse.ArgumentParser(
    prog = 'generate_swhpp'
)
parser.add_argument("-r","--r_len")
parser.add_argument("-q","--q_len")
args = parser.parse_args()
r_len = int(args.r_len)
q_len = int(args.q_len)

filename = "verilator/smith_waterman.hpp"

# starting files
f1 = open("scripts/sw1.txt", "r")
f2 = open("scripts/sw2.txt", "r")

# strings for printing
ref = "\n#define REF_LENGTH "+str(r_len+1)+"\n"
read = "#define READ_LENGTH "+str(q_len+1)+"\n"

f = open(filename,"w")
f.write(f1.read())
f.write(ref)
f.write(read)
f.write(f2.read())
f.close()
f1.close()
f2.close()