rm verilator/*.v
rm -rf target test_run_dir .bsp .bloops .metals 
rm -rf project/project project/target
cd verilator
make clean
cd ..