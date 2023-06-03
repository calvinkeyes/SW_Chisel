import argparse
import os

# parser to get sweep amount
parser = argparse.ArgumentParser(
    prog = 'sweep'
)
parser.add_argument("-r","--r_len")
args = parser.parse_args()
r_len = int(args.r_len)

# make test directory
test_dir = "tests/r"+str(r_len)+"_test/"
os.system("mkdir "+test_dir)

# sweep the q values
i = 10
j = 0

while (i <= r_len):
    if (i < 100):
        j = 10
    else:
        j = 50

    os.system("python3 create_test.py -r "+str(r_len)+" -q "+str(i))
    os.system("sbt compile")
    os.system("sbt run")
    os.system("mv SW.v "+test_dir+"sw_"+str(i)+".v")
    i = i + j


