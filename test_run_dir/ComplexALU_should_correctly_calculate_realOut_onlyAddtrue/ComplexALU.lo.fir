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

    node _io_realOut_T = add(io_real0, io_real1) @[sw_chisel.scala 103:30]
    node _io_imagOut_T = add(io_imag0, io_imag1) @[sw_chisel.scala 104:30]
    io_realOut <= _io_realOut_T @[sw_chisel.scala 103:18]
    io_imagOut <= _io_imagOut_T @[sw_chisel.scala 104:18]
