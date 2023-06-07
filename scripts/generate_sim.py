# script to generate argparse
import argparse

# get user input for length of ref and query
parser = argparse.ArgumentParser(
    prog = 'generate_sim'
)
parser.add_argument("-r","--r_len")
parser.add_argument("-q","--q_len")
args = parser.parse_args()
r_len = int(args.r_len)
q_len = int(args.q_len)

# name of output file
filename = "verilator/sim_main.cpp"

# open big chunks of sim_main that don't change
f1 = open("scripts/sim_main1.txt","r")
f2 = open("scripts/sim_main2.txt","r")
f3 = open("scripts/sim_main3.txt","r")
f4 = open("scripts/sim_main4.txt","r")

# open new file for writing
f = open(filename,"w")

# write the first half of the array
f.write(f1.read())
f.write("\n")

# loop through length of q_len to generate signals

# connect q inputs
for i in range(0,q_len):
    temp = "\tSW->io_q_"+str(i)+"_b = send_to_hw(read["+str(i+1)+"]);\n"
    f.write(temp)
f.write("\n")

# connect r inputs
for i in range (0,r_len):
    temp = "\tSW->io_r_"+str(i)+"_b = send_to_hw(ref["+str(i+1)+"]);\n"
    f.write(temp)
f.write("\n")

#write a portion of the test file
f.write(f2.read())
f.write("\n")

# generate case statements
            # case(1):
            #     printf("%hd\n", SW->io_v1_out_1);
            #     assert(soln[i+1][j-i].v == (char)SW->io_v1_out_1);
            #     break;
for i in range (0,q_len):
    f.write("\t\t\t\tcase("+str(i+1)+"):\n")
    f.write("\t\t\t\t\t//printf(\"%hd\\n\", SW->io_v1_out_"+str(i+1)+");\n")
    f.write("\t\t\t\t\tassert(soln[i+1][j-i].v == (char)SW->io_v1_out_"+str(i+1)+");\n")
    f.write("\t\t\t\t\tbreak;\n")

f.write("\t\t\t\tdefault:\n")
f.write("\t\t\t\t\tbreak;\n")

# write a portion of the test file
f.write(f3.read())
f.write("\n")

# generate more case statements
for i in range (0,q_len):
    f.write("\t\t\t\tcase("+str(i+1)+"):\n")
    f.write("\t\t\t\t\t//printf(\"%hd\\n\", SW->io_v1_out_"+str(i+1)+");\n")
    f.write("\t\t\t\t\tassert(soln[i+1][j-i].v == (char)SW->io_v1_out_"+str(i+1)+");\n")
    f.write("\t\t\t\t\tbreak;\n")

f.write("\t\t\t\tdefault:\n")
f.write("\t\t\t\t\tbreak;\n")

# write the rest of the test file
f.write(f4.read())
f.write("\n")

# close files
f1.close()
f2.close()
f3.close()
f4.close()
f.close()
