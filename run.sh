sbt compile
sbt "run -e verilog --target-dir verilator"
cd verilator
rm *.fir *.anno.json
python3 add_vcd.py SW.v
make