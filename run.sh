sbt compile
sbt "run --target-dir verilator"
cd verilator
rm *.fir *.anno.json
make