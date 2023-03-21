# sw_chisel
Smith-Waterman Accelerator written in Chisel

The Smith-Waterman algorithm is a dynamic programming algorithm used for genomic sequence alignment. The algorithm works by comparing two sequences and identifiying regions of similarity between them. To find the optimal alignment, it calculates a score for every possible alignment and choosing the alignment with the highest possible score. The algorithm is particularly useful for identifying small regions of similarity that may be overlooked by other sequence alignment methods. It is widely in bioinformatics for sequence database searches, genome assembly, and protein structure prediction.

Dependencies
- Verilator and SBT (Scala Build Tool)

Running the project
- Use "bash setup.sh" to compile chisel code to verilog
- Use "bash clean.sh" to clean the repo

Parameters
- Gap Score - this parameter can be modified to affect the accuracy of chosen smith-waterman algorithm
- Substitution Score - this parameter can be modified to affect the accuracy of chosen smith-waterman algorithm
- Data Size - this parameter can be modified to affect the accuracy of chosen smith-waterman algorithm
  - 12-bits should be accurate enough for most applications
- Data Type (Signed vs. Unsigned) - this parameter allows the user to explore similar sequence alignment algorithms (e.g. Needleman-Wunsch)
- 4bit vs 2bit Base Pair Encoding - there is a gate speed vs. wire routing complexity tradeoff

Project Details
There are four main chisel files and one C++ file in this project. Below is a description of each:

- SWModel.scala - this is a scala model of a single cell in the smith-waterman systolic array.
- SWModelTest.scala - this file verifies the functionality of the scala model.
- SWChisel.scala - this file contains code to generate a smith-waterman systolic array. (Currently, the main SW class is a wrapper for a 1x1 systolic array (i.e. one cell)). This file emits a verilog model of the design.
- SWChiselTest.scala - This file verifies the functionality of the chisel module against the scala smith-waterman model.
- sim_main.cpp - this file is used to verify the complete smith-waterman system. It uses a cpp model of the algorithm to verify the verilog that is emitted by SWChisel.scala.

Completed
- Connected Chisel workflow to verilator workflow
- VCD of testbench is generated during the running of the tools. It is found in 'sw_chisel/verilator/logs/dump.vcd'
- The current Chisel module is just a wire that connects the input to the output. The function of the wire is tested in verilator in sim_main.cpp
- Testing of a 1x1 systolic array

In progress
- Need to parameterize data types
- Need to connect Smith-Waterman cpp model to the test bench to be able to poke values into generated verilog
- Need to parameterize SW Cell for number of cells in systolic array

Note: Although this class is over, I will still be adding to this project
