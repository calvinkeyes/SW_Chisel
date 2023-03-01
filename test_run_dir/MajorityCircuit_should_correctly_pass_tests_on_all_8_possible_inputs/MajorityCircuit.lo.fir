FIRRTL version 1.1.0
circuit MajorityCircuit :
  module MajorityCircuit :
    input clock : Clock
    input reset : UInt<1>
    input io_a : UInt<1>
    input io_b : UInt<1>
    input io_c : UInt<1>
    output io_out : UInt<1>

    node _io_out_T = and(io_a, io_b) @[sw_chisel.scala 45:21]
    node _io_out_T_1 = and(io_a, io_c) @[sw_chisel.scala 45:37]
    node _io_out_T_2 = or(_io_out_T, _io_out_T_1) @[sw_chisel.scala 45:29]
    node _io_out_T_3 = and(io_b, io_c) @[sw_chisel.scala 45:53]
    node _io_out_T_4 = or(_io_out_T_2, _io_out_T_3) @[sw_chisel.scala 45:45]
    io_out <= _io_out_T_4 @[sw_chisel.scala 45:12]
