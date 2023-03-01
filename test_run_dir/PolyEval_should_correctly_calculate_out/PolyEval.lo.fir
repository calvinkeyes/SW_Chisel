FIRRTL version 1.1.0
circuit PolyEval :
  module PolyEval :
    input clock : Clock
    input reset : UInt<1>
    input io_enable : UInt<1>
    input io_x : UInt<6>
    output io_out : UInt<14>

    node _c1_wire_T = mul(UInt<2>("h2"), io_x) @[sw_chisel.scala 70:21]
    node _c2_wire_T = mul(UInt<1>("h1"), io_x) @[sw_chisel.scala 71:21]
    node _c2_wire_T_1 = mul(_c2_wire_T, io_x) @[sw_chisel.scala 71:28]
    node c1_wire = _c1_wire_T @[sw_chisel.scala 67:23 70:13]
    node _io_out_T = add(UInt<2>("h3"), c1_wire) @[sw_chisel.scala 74:22]
    node c2_wire = _c2_wire_T_1 @[sw_chisel.scala 68:23 71:13]
    node _io_out_T_1 = add(_io_out_T, c2_wire) @[sw_chisel.scala 74:33]
    node _GEN_0 = mux(io_enable, _io_out_T_1, UInt<1>("h0")) @[sw_chisel.scala 73:22 74:14 76:14]
    io_out <= _GEN_0
