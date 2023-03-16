# sw_chisel
Smith-Waterman Accelerator written in Chisel

Running the project
- Use "bash setup.sh" to compile chisel code to verilog
- Use "bash clean.sh" to clean the repo

Completed
- Connected Chisel workflow to verilator workflow
- VCD of testbench is generated during the running of the tools. It is found in 'sw_chisel/verilator/logs/dump.vcd'
- The current Chisel module is just a wire that connects the input to the output. The function of the wire is tested in verilator in sim_main.cpp

In progress
- Need to connect Smith-Waterman cpp model to the test bench to be able to poke values into generated verilog
- Need to come up with reusable interface for the SW module
- Need to wrap SW Cell into a higher level SW Module and adapt testbench to match new module name
- Need to parameterize SW Cell for number of cells in systolic array, number of bits used for encoding, number of bits used to store data in the array
- Need to write Chisel testbench to test the functionality of a single SW cell
