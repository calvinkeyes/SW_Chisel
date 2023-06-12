# sw_chisel
### Smith-Waterman Accelerator written in Chisel

The Smith-Waterman algorithm is a dynamic programming algorithm used for genomic sequence alignment. The algorithm works by comparing two sequences and identifiying regions of similarity between them. To find the optimal alignment, it calculates a score for every possible alignment and choosing the alignment with the highest possible score. The algorithm is particularly useful for identifying small regions of similarity that may be overlooked by other sequence alignment methods. It is widely in bioinformatics for sequence database searches, genome assembly, and protein structure prediction.

### Dependencies
- Verilator, Python, C++, and SBT (Scala Build Tool)

### Running the project
- Use "python3 run.py -r x -q y" to compile chisel code to verilog and run verification on both models
  - x = length of the reference string
  - y = length of the query (read) string
- Use "bash clean.sh" to clean the working environment of generated files

### Parameters
The parameters are set inside of the Chisel file "SWChisel.scala"

- Alpha - Gap-open penalty, can be modified to affect the accuracy of chosen smith-waterman algorithm
  - Default = 2
- Beta - Gap-continuation penalty, can be modified to affect the accuracy of chosen smith-waterman algorithm
  - Default = 1
- Similarity Score - can be modified to affect the accuracy of chosen smith-waterman algorithm
  - Default = 2
- Data Size - can be modified to affect the accuracy of chosen smith-waterman algorithm
  - Default = 16 (should be accurate enough for most applications without overflowing)
- Reference Length - used to modify the size of the design
- Query (Read) Length - used to modify the size of the design
- Debug mode - when set to true, extra IO ports are set in the design to make it easy to check the internal state of the registers

### Project Details
There are six main Scala files and one C++ file in this project. Below is a description of each:

- SWCellModel.scala - this is a scala model of a single smith-waterman compute unit (cell).
- SWCellTester.scala - this file verifies the scala model of a single compute unit.
- SWModel.scala - this is a scala model of the whole smith-waterman system.
- SWModelTest.scala - this file verifies the functionality of the scala model of the system.
- SWChisel.scala - this file contains the Chisel model of the system. This file emits a verilog model of the design.
- SWChiselTest.scala - This file verifies the functionality of the Chisel model against the Scala smith-waterman model.
- sim_main.cpp - this file is used to verify the complete smith-waterman system. It uses a cpp model of the algorithm to verify the verilog that is emitted by SWChisel.scala.

There are also a few special folders:

- Verilator - contains all of the verilator runtime files.
- Scripts - contains all of the scripts used to dynamically generate the Chisel and Verilog models.
- Tests - contains generated Verilog models sorted by reference sequence length.
