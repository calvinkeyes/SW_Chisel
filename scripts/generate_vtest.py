import os
import argparse

# parser to get sweep amount
parser = argparse.ArgumentParser(
    prog = 'generate_test.py'
)
parser.add_argument("-r","--r_len")
args = parser.parse_args()
r_len = int(args.r_len)

i = 100
j = 0
while (i < r_len):
    if (i < 500):
        j = 100
    else:
        j = 250

    os.system("python3 sweep.py -r "+str(i))
    i = i + j