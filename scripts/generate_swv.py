# file to add a VCD trace of the verilog module
import re
import argparse
import sys

# get command line arguments
parser = argparse.ArgumentParser(
    prog = 'generate_swv'
)
parser.add_argument("-f","--file")
args = parser.parse_args()
file = args.file

# open file
f = open(file, "r")
sw = f.read()
f.close()

# write new contents to file
f = open("verilator/SW.v", "w")
f.write("/* verilator lint_off DECLFILENAME */\n")
f.write("/* verilator lint_off UNUSEDSIGNAL */\n\n")
f.write(sw)
f.close()

# write to MAX.v
f = open("verilator/MAX.v", "r")
max = f.read()
f.close()
f = open("verilator/MAX.v","w")
f.write("/* verilator lint_off VARHIDDEN */\n\n")
f.write(max)
f.close()
