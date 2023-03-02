circuit SWCell :
  module SWCell :
    input clock : Clock
    input reset : UInt<1>
    output io : { flip in : UInt<1>, out : UInt<1>}

    node _T = bits(reset, 0, 0) @[SWChisel.scala 15:9]
    node _T_1 = eq(_T, UInt<1>("h0")) @[SWChisel.scala 15:9]
    when _T_1 : @[SWChisel.scala 15:9]
      printf(clock, UInt<1>("h1"), "Hello World\n") : printf @[SWChisel.scala 15:9]
    node _io_out_T = eq(io.in, UInt<1>("h0")) @[SWChisel.scala 16:13]
    io.out <= _io_out_T @[SWChisel.scala 16:10]

