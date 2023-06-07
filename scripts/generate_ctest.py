# script to generate c test files
import argparse
import os

# get user input for length of ref and query
parser = argparse.ArgumentParser(
    prog = 'generate_ctest'
)
parser.add_argument("-r","--r_len")
parser.add_argument("-q","--q_len")
args = parser.parse_args()
r_len = int(args.r_len)
q_len = int(args.q_len)

# create new files
os.system("python3 scripts/generate_sim.py -r "+str(r_len)+" -q "+str(q_len))
os.system("python3 scripts/generate_swhpp.py -r "+str(r_len)+" -q "+str(q_len))
os.system("python3 scripts/generate_swv.py -f verilator/SW.v")