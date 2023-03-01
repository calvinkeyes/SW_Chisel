FIRRTL version 1.1.0
circuit ComplexALU :
  module ComplexALU :
    input clock : Clock
    input reset : UInt<1>
    input io_doAdd : UInt<1>
    input io_real0 : SInt<5>
    input io_imag0 : SInt<5>
    input io_real1 : SInt<5>
    input io_imag1 : SInt<5>
    output io_realOut : SInt<6>
    output io_imagOut : SInt<6>

    node _io_realOut_T = add(io_real0, io_real1) @[sw_chisel.scala 107:30]
    node _io_imagOut_T = add(io_imag0, io_imag1) @[sw_chisel.scala 108:30]
    node _io_realOut_T_1 = sub(io_real0, io_real1) @[sw_chisel.scala 110:30]
    node _io_imagOut_T_1 = sub(io_imag0, io_imag1) @[sw_chisel.scala 111:30]
    node _GEN_0 = mux(io_doAdd, _io_realOut_T, _io_realOut_T_1) @[sw_chisel.scala 106:21 107:18 110:18]
    node _GEN_1 = mux(io_doAdd, _io_imagOut_T, _io_imagOut_T_1) @[sw_chisel.scala 106:21 108:18 111:18]
    io_realOut <= _GEN_0
    io_imagOut <= _GEN_1
