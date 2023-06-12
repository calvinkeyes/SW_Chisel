module SWCell(
  input  [1:0]  io_q,
  input  [1:0]  io_r,
  input  [15:0] io_e_i,
  input  [15:0] io_f_i,
  input  [15:0] io_ve_i,
  input  [15:0] io_vf_i,
  input  [15:0] io_vv_i,
  output [15:0] io_e_o,
  output [15:0] io_f_o,
  output [15:0] io_v_o
);
  wire [15:0] _T_2 = $signed(io_ve_i) - 16'sh2; // @[SWChisel.scala 78:17]
  wire [15:0] _T_5 = $signed(io_e_i) - 16'sh1; // @[SWChisel.scala 78:39]
  wire [15:0] e_max = $signed(_T_2) >= $signed(_T_5) ? $signed(_T_2) : $signed(_T_5); // @[SWChisel.scala 78:51 79:11 81:11]
  wire [15:0] _T_9 = $signed(io_vf_i) - 16'sh2; // @[SWChisel.scala 85:17]
  wire [15:0] _T_12 = $signed(io_f_i) - 16'sh1; // @[SWChisel.scala 85:38]
  wire [15:0] f_max = $signed(_T_9) > $signed(_T_12) ? $signed(_T_9) : $signed(_T_12); // @[SWChisel.scala 85:50 86:11 88:11]
  wire [15:0] ef_temp = $signed(e_max) > $signed(f_max) ? $signed(e_max) : $signed(f_max); // @[SWChisel.scala 92:24 93:13 95:13]
  wire [15:0] _v_temp_T_2 = $signed(io_vv_i) + 16'sh2; // @[SWChisel.scala 100:23]
  wire [15:0] _v_temp_T_5 = $signed(io_vv_i) - 16'sh2; // @[SWChisel.scala 102:23]
  wire [15:0] v_temp = io_q == io_r ? $signed(_v_temp_T_2) : $signed(_v_temp_T_5); // @[SWChisel.scala 100:12 102:12 99:24]
  assign io_e_o = $signed(_T_2) >= $signed(_T_5) ? $signed(_T_2) : $signed(_T_5); // @[SWChisel.scala 78:51 79:11 81:11]
  assign io_f_o = $signed(_T_9) > $signed(_T_12) ? $signed(_T_9) : $signed(_T_12); // @[SWChisel.scala 85:50 86:11 88:11]
  assign io_v_o = $signed(v_temp) > $signed(ef_temp) ? $signed(v_temp) : $signed(ef_temp); // @[SWChisel.scala 106:27 107:11 109:11]
endmodule
