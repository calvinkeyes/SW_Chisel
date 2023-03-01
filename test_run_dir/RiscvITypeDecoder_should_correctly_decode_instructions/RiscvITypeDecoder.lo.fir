FIRRTL version 1.1.0
circuit RiscvITypeDecoder :
  module RiscvITypeDecoder :
    input clock : Clock
    input reset : UInt<1>
    input io_instWord : UInt<32>
    output io_opcode : UInt<7>
    output io_funct3 : UInt<3>
    output io_rs1 : UInt<5>
    output io_rd : UInt<5>
    output io_immSignExtended : UInt<32>

    node _io_opcode_T = bits(io_instWord, 6, 0) @[sw_chisel.scala 28:29]
    node _io_funct3_T = bits(io_instWord, 14, 12) @[sw_chisel.scala 29:29]
    node _io_rs1_T = bits(io_instWord, 19, 15) @[sw_chisel.scala 30:26]
    node _io_rd_T = bits(io_instWord, 11, 7) @[sw_chisel.scala 31:25]
    node signBit = bits(io_instWord, 31, 31) @[sw_chisel.scala 32:30]
    node _extension_T = bits(signBit, 0, 0) @[Bitwise.scala 77:15]
    node extension = mux(_extension_T, UInt<20>("hfffff"), UInt<20>("h0")) @[Bitwise.scala 77:12]
    node _io_immSignExtended_T = bits(io_instWord, 31, 20) @[sw_chisel.scala 34:53]
    node _io_immSignExtended_T_1 = cat(extension, _io_immSignExtended_T) @[Cat.scala 33:92]
    io_opcode <= _io_opcode_T @[sw_chisel.scala 28:15]
    io_funct3 <= _io_funct3_T @[sw_chisel.scala 29:15]
    io_rs1 <= _io_rs1_T @[sw_chisel.scala 30:12]
    io_rd <= _io_rd_T @[sw_chisel.scala 31:11]
    io_immSignExtended <= _io_immSignExtended_T_1 @[sw_chisel.scala 34:24]
