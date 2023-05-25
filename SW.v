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
module MyCounter(
  input        clock,
  input        reset,
  input        io_en,
  output [3:0] io_out
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_REG_INIT
  wire [3:0] _io_out_T_2 = io_out + 4'h1; // @[SWChisel.scala 155:55]
  reg [3:0] io_out_r; // @[Reg.scala 35:20]
  assign io_out = io_out_r; // @[SWChisel.scala 155:12]
  always @(posedge clock) begin
    if (reset) begin // @[Reg.scala 35:20]
      io_out_r <= 4'h0; // @[Reg.scala 35:20]
    end else if (io_en) begin // @[Reg.scala 36:18]
      if (io_out < 4'ha) begin // @[SWChisel.scala 155:28]
        io_out_r <= _io_out_T_2;
      end else begin
        io_out_r <= 4'h0;
      end
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  io_out_r = _RAND_0[3:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module MAX(
  input         clock,
  input         reset,
  input         io_start,
  input  [15:0] io_in,
  output        io_done,
  output [15:0] io_out
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
`endif // RANDOMIZE_REG_INIT
  reg [15:0] max; // @[SWChisel.scala 122:20]
  reg [3:0] counter; // @[SWChisel.scala 133:24]
  wire [3:0] _counter_T_1 = counter - 4'h1; // @[SWChisel.scala 135:24]
  assign io_done = counter == 4'h0; // @[SWChisel.scala 141:17]
  assign io_out = max; // @[SWChisel.scala 123:10]
  always @(posedge clock) begin
    if (reset) begin // @[SWChisel.scala 122:20]
      max <= 16'sh8000; // @[SWChisel.scala 122:20]
    end else if ($signed(io_in) > $signed(max)) begin // @[SWChisel.scala 126:22]
      max <= io_in; // @[SWChisel.scala 127:9]
    end
    if (reset) begin // @[SWChisel.scala 133:24]
      counter <= 4'hb; // @[SWChisel.scala 133:24]
    end else if (counter == 4'h0) begin // @[SWChisel.scala 141:26]
      counter <= 4'h0; // @[SWChisel.scala 143:13]
    end else if (io_start) begin // @[SWChisel.scala 134:19]
      counter <= _counter_T_1; // @[SWChisel.scala 135:13]
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  max = _RAND_0[15:0];
  _RAND_1 = {1{`RANDOM}};
  counter = _RAND_1[3:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module SW(
  input         clock,
  input         reset,
  input  [1:0]  io_q_0_b,
  input  [1:0]  io_q_1_b,
  input  [1:0]  io_q_2_b,
  input  [1:0]  io_q_3_b,
  input  [1:0]  io_q_4_b,
  input  [1:0]  io_q_5_b,
  input  [1:0]  io_r_0_b,
  input  [1:0]  io_r_1_b,
  input  [1:0]  io_r_2_b,
  input  [1:0]  io_r_3_b,
  input  [1:0]  io_r_4_b,
  input  [1:0]  io_r_5_b,
  input  [1:0]  io_r_6_b,
  input  [1:0]  io_r_7_b,
  input  [1:0]  io_r_8_b,
  input  [1:0]  io_r_9_b,
  input         io_start,
  output [15:0] io_result,
  output        io_done
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
  reg [31:0] _RAND_7;
  reg [31:0] _RAND_8;
  reg [31:0] _RAND_9;
  reg [31:0] _RAND_10;
  reg [31:0] _RAND_11;
  reg [31:0] _RAND_12;
  reg [31:0] _RAND_13;
  reg [31:0] _RAND_14;
  reg [31:0] _RAND_15;
  reg [31:0] _RAND_16;
  reg [31:0] _RAND_17;
  reg [31:0] _RAND_18;
  reg [31:0] _RAND_19;
  reg [31:0] _RAND_20;
  reg [31:0] _RAND_21;
  reg [31:0] _RAND_22;
  reg [31:0] _RAND_23;
  reg [31:0] _RAND_24;
  reg [31:0] _RAND_25;
  reg [31:0] _RAND_26;
  reg [31:0] _RAND_27;
  reg [31:0] _RAND_28;
  reg [31:0] _RAND_29;
`endif // RANDOMIZE_REG_INIT
  wire [1:0] array_0_io_q; // @[SWChisel.scala 170:39]
  wire [1:0] array_0_io_r; // @[SWChisel.scala 170:39]
  wire [15:0] array_0_io_e_i; // @[SWChisel.scala 170:39]
  wire [15:0] array_0_io_f_i; // @[SWChisel.scala 170:39]
  wire [15:0] array_0_io_ve_i; // @[SWChisel.scala 170:39]
  wire [15:0] array_0_io_vf_i; // @[SWChisel.scala 170:39]
  wire [15:0] array_0_io_vv_i; // @[SWChisel.scala 170:39]
  wire [15:0] array_0_io_e_o; // @[SWChisel.scala 170:39]
  wire [15:0] array_0_io_f_o; // @[SWChisel.scala 170:39]
  wire [15:0] array_0_io_v_o; // @[SWChisel.scala 170:39]
  wire [1:0] array_1_io_q; // @[SWChisel.scala 170:39]
  wire [1:0] array_1_io_r; // @[SWChisel.scala 170:39]
  wire [15:0] array_1_io_e_i; // @[SWChisel.scala 170:39]
  wire [15:0] array_1_io_f_i; // @[SWChisel.scala 170:39]
  wire [15:0] array_1_io_ve_i; // @[SWChisel.scala 170:39]
  wire [15:0] array_1_io_vf_i; // @[SWChisel.scala 170:39]
  wire [15:0] array_1_io_vv_i; // @[SWChisel.scala 170:39]
  wire [15:0] array_1_io_e_o; // @[SWChisel.scala 170:39]
  wire [15:0] array_1_io_f_o; // @[SWChisel.scala 170:39]
  wire [15:0] array_1_io_v_o; // @[SWChisel.scala 170:39]
  wire [1:0] array_2_io_q; // @[SWChisel.scala 170:39]
  wire [1:0] array_2_io_r; // @[SWChisel.scala 170:39]
  wire [15:0] array_2_io_e_i; // @[SWChisel.scala 170:39]
  wire [15:0] array_2_io_f_i; // @[SWChisel.scala 170:39]
  wire [15:0] array_2_io_ve_i; // @[SWChisel.scala 170:39]
  wire [15:0] array_2_io_vf_i; // @[SWChisel.scala 170:39]
  wire [15:0] array_2_io_vv_i; // @[SWChisel.scala 170:39]
  wire [15:0] array_2_io_e_o; // @[SWChisel.scala 170:39]
  wire [15:0] array_2_io_f_o; // @[SWChisel.scala 170:39]
  wire [15:0] array_2_io_v_o; // @[SWChisel.scala 170:39]
  wire [1:0] array_3_io_q; // @[SWChisel.scala 170:39]
  wire [1:0] array_3_io_r; // @[SWChisel.scala 170:39]
  wire [15:0] array_3_io_e_i; // @[SWChisel.scala 170:39]
  wire [15:0] array_3_io_f_i; // @[SWChisel.scala 170:39]
  wire [15:0] array_3_io_ve_i; // @[SWChisel.scala 170:39]
  wire [15:0] array_3_io_vf_i; // @[SWChisel.scala 170:39]
  wire [15:0] array_3_io_vv_i; // @[SWChisel.scala 170:39]
  wire [15:0] array_3_io_e_o; // @[SWChisel.scala 170:39]
  wire [15:0] array_3_io_f_o; // @[SWChisel.scala 170:39]
  wire [15:0] array_3_io_v_o; // @[SWChisel.scala 170:39]
  wire [1:0] array_4_io_q; // @[SWChisel.scala 170:39]
  wire [1:0] array_4_io_r; // @[SWChisel.scala 170:39]
  wire [15:0] array_4_io_e_i; // @[SWChisel.scala 170:39]
  wire [15:0] array_4_io_f_i; // @[SWChisel.scala 170:39]
  wire [15:0] array_4_io_ve_i; // @[SWChisel.scala 170:39]
  wire [15:0] array_4_io_vf_i; // @[SWChisel.scala 170:39]
  wire [15:0] array_4_io_vv_i; // @[SWChisel.scala 170:39]
  wire [15:0] array_4_io_e_o; // @[SWChisel.scala 170:39]
  wire [15:0] array_4_io_f_o; // @[SWChisel.scala 170:39]
  wire [15:0] array_4_io_v_o; // @[SWChisel.scala 170:39]
  wire [1:0] array_5_io_q; // @[SWChisel.scala 170:39]
  wire [1:0] array_5_io_r; // @[SWChisel.scala 170:39]
  wire [15:0] array_5_io_e_i; // @[SWChisel.scala 170:39]
  wire [15:0] array_5_io_f_i; // @[SWChisel.scala 170:39]
  wire [15:0] array_5_io_ve_i; // @[SWChisel.scala 170:39]
  wire [15:0] array_5_io_vf_i; // @[SWChisel.scala 170:39]
  wire [15:0] array_5_io_vv_i; // @[SWChisel.scala 170:39]
  wire [15:0] array_5_io_e_o; // @[SWChisel.scala 170:39]
  wire [15:0] array_5_io_f_o; // @[SWChisel.scala 170:39]
  wire [15:0] array_5_io_v_o; // @[SWChisel.scala 170:39]
  wire  r_count_0_clock; // @[SWChisel.scala 171:41]
  wire  r_count_0_reset; // @[SWChisel.scala 171:41]
  wire  r_count_0_io_en; // @[SWChisel.scala 171:41]
  wire [3:0] r_count_0_io_out; // @[SWChisel.scala 171:41]
  wire  r_count_1_clock; // @[SWChisel.scala 171:41]
  wire  r_count_1_reset; // @[SWChisel.scala 171:41]
  wire  r_count_1_io_en; // @[SWChisel.scala 171:41]
  wire [3:0] r_count_1_io_out; // @[SWChisel.scala 171:41]
  wire  r_count_2_clock; // @[SWChisel.scala 171:41]
  wire  r_count_2_reset; // @[SWChisel.scala 171:41]
  wire  r_count_2_io_en; // @[SWChisel.scala 171:41]
  wire [3:0] r_count_2_io_out; // @[SWChisel.scala 171:41]
  wire  r_count_3_clock; // @[SWChisel.scala 171:41]
  wire  r_count_3_reset; // @[SWChisel.scala 171:41]
  wire  r_count_3_io_en; // @[SWChisel.scala 171:41]
  wire [3:0] r_count_3_io_out; // @[SWChisel.scala 171:41]
  wire  r_count_4_clock; // @[SWChisel.scala 171:41]
  wire  r_count_4_reset; // @[SWChisel.scala 171:41]
  wire  r_count_4_io_en; // @[SWChisel.scala 171:41]
  wire [3:0] r_count_4_io_out; // @[SWChisel.scala 171:41]
  wire  r_count_5_clock; // @[SWChisel.scala 171:41]
  wire  r_count_5_reset; // @[SWChisel.scala 171:41]
  wire  r_count_5_io_en; // @[SWChisel.scala 171:41]
  wire [3:0] r_count_5_io_out; // @[SWChisel.scala 171:41]
  wire  max_clock; // @[SWChisel.scala 174:19]
  wire  max_reset; // @[SWChisel.scala 174:19]
  wire  max_io_start; // @[SWChisel.scala 174:19]
  wire [15:0] max_io_in; // @[SWChisel.scala 174:19]
  wire  max_io_done; // @[SWChisel.scala 174:19]
  wire [15:0] max_io_out; // @[SWChisel.scala 174:19]
  reg [15:0] E_0; // @[SWChisel.scala 162:18]
  reg [15:0] E_1; // @[SWChisel.scala 162:18]
  reg [15:0] E_2; // @[SWChisel.scala 162:18]
  reg [15:0] E_3; // @[SWChisel.scala 162:18]
  reg [15:0] E_4; // @[SWChisel.scala 162:18]
  reg [15:0] E_5; // @[SWChisel.scala 162:18]
  reg [15:0] F_1; // @[SWChisel.scala 163:18]
  reg [15:0] F_2; // @[SWChisel.scala 163:18]
  reg [15:0] F_3; // @[SWChisel.scala 163:18]
  reg [15:0] F_4; // @[SWChisel.scala 163:18]
  reg [15:0] F_5; // @[SWChisel.scala 163:18]
  reg [15:0] V1_0; // @[SWChisel.scala 164:19]
  reg [15:0] V1_1; // @[SWChisel.scala 164:19]
  reg [15:0] V1_2; // @[SWChisel.scala 164:19]
  reg [15:0] V1_3; // @[SWChisel.scala 164:19]
  reg [15:0] V1_4; // @[SWChisel.scala 164:19]
  reg [15:0] V1_5; // @[SWChisel.scala 164:19]
  reg [15:0] V1_6; // @[SWChisel.scala 164:19]
  reg [15:0] V2_0; // @[SWChisel.scala 166:19]
  reg [15:0] V2_1; // @[SWChisel.scala 166:19]
  reg [15:0] V2_2; // @[SWChisel.scala 166:19]
  reg [15:0] V2_3; // @[SWChisel.scala 166:19]
  reg [15:0] V2_4; // @[SWChisel.scala 166:19]
  reg [15:0] V2_5; // @[SWChisel.scala 166:19]
  reg  start_reg_0; // @[SWChisel.scala 167:26]
  reg  start_reg_1; // @[SWChisel.scala 167:26]
  reg  start_reg_2; // @[SWChisel.scala 167:26]
  reg  start_reg_3; // @[SWChisel.scala 167:26]
  reg  start_reg_4; // @[SWChisel.scala 167:26]
  reg  start_reg_5; // @[SWChisel.scala 167:26]
  wire [1:0] _GEN_19 = 4'h1 == r_count_0_io_out ? io_r_1_b : io_r_0_b; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_20 = 4'h2 == r_count_0_io_out ? io_r_2_b : _GEN_19; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_21 = 4'h3 == r_count_0_io_out ? io_r_3_b : _GEN_20; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_22 = 4'h4 == r_count_0_io_out ? io_r_4_b : _GEN_21; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_23 = 4'h5 == r_count_0_io_out ? io_r_5_b : _GEN_22; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_24 = 4'h6 == r_count_0_io_out ? io_r_6_b : _GEN_23; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_25 = 4'h7 == r_count_0_io_out ? io_r_7_b : _GEN_24; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_26 = 4'h8 == r_count_0_io_out ? io_r_8_b : _GEN_25; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_29 = 4'h1 == r_count_1_io_out ? io_r_1_b : io_r_0_b; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_30 = 4'h2 == r_count_1_io_out ? io_r_2_b : _GEN_29; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_31 = 4'h3 == r_count_1_io_out ? io_r_3_b : _GEN_30; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_32 = 4'h4 == r_count_1_io_out ? io_r_4_b : _GEN_31; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_33 = 4'h5 == r_count_1_io_out ? io_r_5_b : _GEN_32; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_34 = 4'h6 == r_count_1_io_out ? io_r_6_b : _GEN_33; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_35 = 4'h7 == r_count_1_io_out ? io_r_7_b : _GEN_34; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_36 = 4'h8 == r_count_1_io_out ? io_r_8_b : _GEN_35; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_39 = 4'h1 == r_count_2_io_out ? io_r_1_b : io_r_0_b; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_40 = 4'h2 == r_count_2_io_out ? io_r_2_b : _GEN_39; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_41 = 4'h3 == r_count_2_io_out ? io_r_3_b : _GEN_40; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_42 = 4'h4 == r_count_2_io_out ? io_r_4_b : _GEN_41; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_43 = 4'h5 == r_count_2_io_out ? io_r_5_b : _GEN_42; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_44 = 4'h6 == r_count_2_io_out ? io_r_6_b : _GEN_43; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_45 = 4'h7 == r_count_2_io_out ? io_r_7_b : _GEN_44; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_46 = 4'h8 == r_count_2_io_out ? io_r_8_b : _GEN_45; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_49 = 4'h1 == r_count_3_io_out ? io_r_1_b : io_r_0_b; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_50 = 4'h2 == r_count_3_io_out ? io_r_2_b : _GEN_49; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_51 = 4'h3 == r_count_3_io_out ? io_r_3_b : _GEN_50; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_52 = 4'h4 == r_count_3_io_out ? io_r_4_b : _GEN_51; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_53 = 4'h5 == r_count_3_io_out ? io_r_5_b : _GEN_52; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_54 = 4'h6 == r_count_3_io_out ? io_r_6_b : _GEN_53; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_55 = 4'h7 == r_count_3_io_out ? io_r_7_b : _GEN_54; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_56 = 4'h8 == r_count_3_io_out ? io_r_8_b : _GEN_55; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_59 = 4'h1 == r_count_4_io_out ? io_r_1_b : io_r_0_b; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_60 = 4'h2 == r_count_4_io_out ? io_r_2_b : _GEN_59; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_61 = 4'h3 == r_count_4_io_out ? io_r_3_b : _GEN_60; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_62 = 4'h4 == r_count_4_io_out ? io_r_4_b : _GEN_61; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_63 = 4'h5 == r_count_4_io_out ? io_r_5_b : _GEN_62; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_64 = 4'h6 == r_count_4_io_out ? io_r_6_b : _GEN_63; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_65 = 4'h7 == r_count_4_io_out ? io_r_7_b : _GEN_64; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_66 = 4'h8 == r_count_4_io_out ? io_r_8_b : _GEN_65; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_69 = 4'h1 == r_count_5_io_out ? io_r_1_b : io_r_0_b; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_70 = 4'h2 == r_count_5_io_out ? io_r_2_b : _GEN_69; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_71 = 4'h3 == r_count_5_io_out ? io_r_3_b : _GEN_70; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_72 = 4'h4 == r_count_5_io_out ? io_r_4_b : _GEN_71; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_73 = 4'h5 == r_count_5_io_out ? io_r_5_b : _GEN_72; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_74 = 4'h6 == r_count_5_io_out ? io_r_6_b : _GEN_73; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_75 = 4'h7 == r_count_5_io_out ? io_r_7_b : _GEN_74; // @[SWChisel.scala 221:{19,19}]
  wire [1:0] _GEN_76 = 4'h8 == r_count_5_io_out ? io_r_8_b : _GEN_75; // @[SWChisel.scala 221:{19,19}]
  SWCell array_0 ( // @[SWChisel.scala 170:39]
    .io_q(array_0_io_q),
    .io_r(array_0_io_r),
    .io_e_i(array_0_io_e_i),
    .io_f_i(array_0_io_f_i),
    .io_ve_i(array_0_io_ve_i),
    .io_vf_i(array_0_io_vf_i),
    .io_vv_i(array_0_io_vv_i),
    .io_e_o(array_0_io_e_o),
    .io_f_o(array_0_io_f_o),
    .io_v_o(array_0_io_v_o)
  );
  SWCell array_1 ( // @[SWChisel.scala 170:39]
    .io_q(array_1_io_q),
    .io_r(array_1_io_r),
    .io_e_i(array_1_io_e_i),
    .io_f_i(array_1_io_f_i),
    .io_ve_i(array_1_io_ve_i),
    .io_vf_i(array_1_io_vf_i),
    .io_vv_i(array_1_io_vv_i),
    .io_e_o(array_1_io_e_o),
    .io_f_o(array_1_io_f_o),
    .io_v_o(array_1_io_v_o)
  );
  SWCell array_2 ( // @[SWChisel.scala 170:39]
    .io_q(array_2_io_q),
    .io_r(array_2_io_r),
    .io_e_i(array_2_io_e_i),
    .io_f_i(array_2_io_f_i),
    .io_ve_i(array_2_io_ve_i),
    .io_vf_i(array_2_io_vf_i),
    .io_vv_i(array_2_io_vv_i),
    .io_e_o(array_2_io_e_o),
    .io_f_o(array_2_io_f_o),
    .io_v_o(array_2_io_v_o)
  );
  SWCell array_3 ( // @[SWChisel.scala 170:39]
    .io_q(array_3_io_q),
    .io_r(array_3_io_r),
    .io_e_i(array_3_io_e_i),
    .io_f_i(array_3_io_f_i),
    .io_ve_i(array_3_io_ve_i),
    .io_vf_i(array_3_io_vf_i),
    .io_vv_i(array_3_io_vv_i),
    .io_e_o(array_3_io_e_o),
    .io_f_o(array_3_io_f_o),
    .io_v_o(array_3_io_v_o)
  );
  SWCell array_4 ( // @[SWChisel.scala 170:39]
    .io_q(array_4_io_q),
    .io_r(array_4_io_r),
    .io_e_i(array_4_io_e_i),
    .io_f_i(array_4_io_f_i),
    .io_ve_i(array_4_io_ve_i),
    .io_vf_i(array_4_io_vf_i),
    .io_vv_i(array_4_io_vv_i),
    .io_e_o(array_4_io_e_o),
    .io_f_o(array_4_io_f_o),
    .io_v_o(array_4_io_v_o)
  );
  SWCell array_5 ( // @[SWChisel.scala 170:39]
    .io_q(array_5_io_q),
    .io_r(array_5_io_r),
    .io_e_i(array_5_io_e_i),
    .io_f_i(array_5_io_f_i),
    .io_ve_i(array_5_io_ve_i),
    .io_vf_i(array_5_io_vf_i),
    .io_vv_i(array_5_io_vv_i),
    .io_e_o(array_5_io_e_o),
    .io_f_o(array_5_io_f_o),
    .io_v_o(array_5_io_v_o)
  );
  MyCounter r_count_0 ( // @[SWChisel.scala 171:41]
    .clock(r_count_0_clock),
    .reset(r_count_0_reset),
    .io_en(r_count_0_io_en),
    .io_out(r_count_0_io_out)
  );
  MyCounter r_count_1 ( // @[SWChisel.scala 171:41]
    .clock(r_count_1_clock),
    .reset(r_count_1_reset),
    .io_en(r_count_1_io_en),
    .io_out(r_count_1_io_out)
  );
  MyCounter r_count_2 ( // @[SWChisel.scala 171:41]
    .clock(r_count_2_clock),
    .reset(r_count_2_reset),
    .io_en(r_count_2_io_en),
    .io_out(r_count_2_io_out)
  );
  MyCounter r_count_3 ( // @[SWChisel.scala 171:41]
    .clock(r_count_3_clock),
    .reset(r_count_3_reset),
    .io_en(r_count_3_io_en),
    .io_out(r_count_3_io_out)
  );
  MyCounter r_count_4 ( // @[SWChisel.scala 171:41]
    .clock(r_count_4_clock),
    .reset(r_count_4_reset),
    .io_en(r_count_4_io_en),
    .io_out(r_count_4_io_out)
  );
  MyCounter r_count_5 ( // @[SWChisel.scala 171:41]
    .clock(r_count_5_clock),
    .reset(r_count_5_reset),
    .io_en(r_count_5_io_en),
    .io_out(r_count_5_io_out)
  );
  MAX max ( // @[SWChisel.scala 174:19]
    .clock(max_clock),
    .reset(max_reset),
    .io_start(max_io_start),
    .io_in(max_io_in),
    .io_done(max_io_done),
    .io_out(max_io_out)
  );
  assign io_result = max_io_out; // @[SWChisel.scala 181:13]
  assign io_done = max_io_done; // @[SWChisel.scala 182:11]
  assign array_0_io_q = io_q_0_b; // @[SWChisel.scala 220:19]
  assign array_0_io_r = 4'h9 == r_count_0_io_out ? io_r_9_b : _GEN_26; // @[SWChisel.scala 221:{19,19}]
  assign array_0_io_e_i = E_0; // @[SWChisel.scala 196:21]
  assign array_0_io_f_i = 16'sh0; // @[SWChisel.scala 198:21]
  assign array_0_io_ve_i = V1_1; // @[SWChisel.scala 197:22]
  assign array_0_io_vf_i = V1_0; // @[SWChisel.scala 199:22]
  assign array_0_io_vv_i = V2_0; // @[SWChisel.scala 200:22]
  assign array_1_io_q = io_q_1_b; // @[SWChisel.scala 220:19]
  assign array_1_io_r = 4'h9 == r_count_1_io_out ? io_r_9_b : _GEN_36; // @[SWChisel.scala 221:{19,19}]
  assign array_1_io_e_i = E_1; // @[SWChisel.scala 196:21]
  assign array_1_io_f_i = F_1; // @[SWChisel.scala 198:21]
  assign array_1_io_ve_i = V1_2; // @[SWChisel.scala 197:22]
  assign array_1_io_vf_i = V1_1; // @[SWChisel.scala 199:22]
  assign array_1_io_vv_i = V2_1; // @[SWChisel.scala 200:22]
  assign array_2_io_q = io_q_2_b; // @[SWChisel.scala 220:19]
  assign array_2_io_r = 4'h9 == r_count_2_io_out ? io_r_9_b : _GEN_46; // @[SWChisel.scala 221:{19,19}]
  assign array_2_io_e_i = E_2; // @[SWChisel.scala 196:21]
  assign array_2_io_f_i = F_2; // @[SWChisel.scala 198:21]
  assign array_2_io_ve_i = V1_3; // @[SWChisel.scala 197:22]
  assign array_2_io_vf_i = V1_2; // @[SWChisel.scala 199:22]
  assign array_2_io_vv_i = V2_2; // @[SWChisel.scala 200:22]
  assign array_3_io_q = io_q_3_b; // @[SWChisel.scala 220:19]
  assign array_3_io_r = 4'h9 == r_count_3_io_out ? io_r_9_b : _GEN_56; // @[SWChisel.scala 221:{19,19}]
  assign array_3_io_e_i = E_3; // @[SWChisel.scala 196:21]
  assign array_3_io_f_i = F_3; // @[SWChisel.scala 198:21]
  assign array_3_io_ve_i = V1_4; // @[SWChisel.scala 197:22]
  assign array_3_io_vf_i = V1_3; // @[SWChisel.scala 199:22]
  assign array_3_io_vv_i = V2_3; // @[SWChisel.scala 200:22]
  assign array_4_io_q = io_q_4_b; // @[SWChisel.scala 220:19]
  assign array_4_io_r = 4'h9 == r_count_4_io_out ? io_r_9_b : _GEN_66; // @[SWChisel.scala 221:{19,19}]
  assign array_4_io_e_i = E_4; // @[SWChisel.scala 196:21]
  assign array_4_io_f_i = F_4; // @[SWChisel.scala 198:21]
  assign array_4_io_ve_i = V1_5; // @[SWChisel.scala 197:22]
  assign array_4_io_vf_i = V1_4; // @[SWChisel.scala 199:22]
  assign array_4_io_vv_i = V2_4; // @[SWChisel.scala 200:22]
  assign array_5_io_q = io_q_5_b; // @[SWChisel.scala 220:19]
  assign array_5_io_r = 4'h9 == r_count_5_io_out ? io_r_9_b : _GEN_76; // @[SWChisel.scala 221:{19,19}]
  assign array_5_io_e_i = E_5; // @[SWChisel.scala 196:21]
  assign array_5_io_f_i = F_5; // @[SWChisel.scala 198:21]
  assign array_5_io_ve_i = V1_6; // @[SWChisel.scala 197:22]
  assign array_5_io_vf_i = V1_5; // @[SWChisel.scala 199:22]
  assign array_5_io_vv_i = V2_5; // @[SWChisel.scala 200:22]
  assign r_count_0_clock = clock;
  assign r_count_0_reset = reset;
  assign r_count_0_io_en = start_reg_0; // @[SWChisel.scala 192:22]
  assign r_count_1_clock = clock;
  assign r_count_1_reset = reset;
  assign r_count_1_io_en = start_reg_1; // @[SWChisel.scala 192:22]
  assign r_count_2_clock = clock;
  assign r_count_2_reset = reset;
  assign r_count_2_io_en = start_reg_2; // @[SWChisel.scala 192:22]
  assign r_count_3_clock = clock;
  assign r_count_3_reset = reset;
  assign r_count_3_io_en = start_reg_3; // @[SWChisel.scala 192:22]
  assign r_count_4_clock = clock;
  assign r_count_4_reset = reset;
  assign r_count_4_io_en = start_reg_4; // @[SWChisel.scala 192:22]
  assign r_count_5_clock = clock;
  assign r_count_5_reset = reset;
  assign r_count_5_io_en = start_reg_5; // @[SWChisel.scala 192:22]
  assign max_clock = clock;
  assign max_reset = reset;
  assign max_io_start = start_reg_5; // @[SWChisel.scala 178:16]
  assign max_io_in = V1_6; // @[SWChisel.scala 177:13]
  always @(posedge clock) begin
    if (reset) begin // @[SWChisel.scala 162:18]
      E_0 <= -16'sh2; // @[SWChisel.scala 162:18]
    end else if (start_reg_0) begin // @[SWChisel.scala 207:25]
      E_0 <= array_0_io_e_o; // @[SWChisel.scala 208:12]
    end
    if (reset) begin // @[SWChisel.scala 162:18]
      E_1 <= -16'sh3; // @[SWChisel.scala 162:18]
    end else if (start_reg_1) begin // @[SWChisel.scala 207:25]
      E_1 <= array_1_io_e_o; // @[SWChisel.scala 208:12]
    end
    if (reset) begin // @[SWChisel.scala 162:18]
      E_2 <= -16'sh4; // @[SWChisel.scala 162:18]
    end else if (start_reg_2) begin // @[SWChisel.scala 207:25]
      E_2 <= array_2_io_e_o; // @[SWChisel.scala 208:12]
    end
    if (reset) begin // @[SWChisel.scala 162:18]
      E_3 <= -16'sh5; // @[SWChisel.scala 162:18]
    end else if (start_reg_3) begin // @[SWChisel.scala 207:25]
      E_3 <= array_3_io_e_o; // @[SWChisel.scala 208:12]
    end
    if (reset) begin // @[SWChisel.scala 162:18]
      E_4 <= -16'sh6; // @[SWChisel.scala 162:18]
    end else if (start_reg_4) begin // @[SWChisel.scala 207:25]
      E_4 <= array_4_io_e_o; // @[SWChisel.scala 208:12]
    end
    if (reset) begin // @[SWChisel.scala 162:18]
      E_5 <= -16'sh7; // @[SWChisel.scala 162:18]
    end else if (start_reg_5) begin // @[SWChisel.scala 207:25]
      E_5 <= array_5_io_e_o; // @[SWChisel.scala 208:12]
    end
    if (reset) begin // @[SWChisel.scala 163:18]
      F_1 <= 16'sh0; // @[SWChisel.scala 163:18]
    end else if (start_reg_0) begin // @[SWChisel.scala 207:25]
      F_1 <= array_0_io_f_o; // @[SWChisel.scala 209:14]
    end
    if (reset) begin // @[SWChisel.scala 163:18]
      F_2 <= 16'sh0; // @[SWChisel.scala 163:18]
    end else if (start_reg_1) begin // @[SWChisel.scala 207:25]
      F_2 <= array_1_io_f_o; // @[SWChisel.scala 209:14]
    end
    if (reset) begin // @[SWChisel.scala 163:18]
      F_3 <= 16'sh0; // @[SWChisel.scala 163:18]
    end else if (start_reg_2) begin // @[SWChisel.scala 207:25]
      F_3 <= array_2_io_f_o; // @[SWChisel.scala 209:14]
    end
    if (reset) begin // @[SWChisel.scala 163:18]
      F_4 <= 16'sh0; // @[SWChisel.scala 163:18]
    end else if (start_reg_3) begin // @[SWChisel.scala 207:25]
      F_4 <= array_3_io_f_o; // @[SWChisel.scala 209:14]
    end
    if (reset) begin // @[SWChisel.scala 163:18]
      F_5 <= 16'sh0; // @[SWChisel.scala 163:18]
    end else if (start_reg_4) begin // @[SWChisel.scala 207:25]
      F_5 <= array_4_io_f_o; // @[SWChisel.scala 209:14]
    end
    if (reset) begin // @[SWChisel.scala 164:19]
      V1_0 <= -16'sh1; // @[SWChisel.scala 164:19]
    end else begin
      V1_0 <= 16'sh0; // @[SWChisel.scala 165:9]
    end
    if (reset) begin // @[SWChisel.scala 164:19]
      V1_1 <= -16'sh2; // @[SWChisel.scala 164:19]
    end else if (start_reg_0) begin // @[SWChisel.scala 207:25]
      V1_1 <= array_0_io_v_o; // @[SWChisel.scala 210:15]
    end
    if (reset) begin // @[SWChisel.scala 164:19]
      V1_2 <= -16'sh3; // @[SWChisel.scala 164:19]
    end else if (start_reg_1) begin // @[SWChisel.scala 207:25]
      V1_2 <= array_1_io_v_o; // @[SWChisel.scala 210:15]
    end
    if (reset) begin // @[SWChisel.scala 164:19]
      V1_3 <= -16'sh4; // @[SWChisel.scala 164:19]
    end else if (start_reg_2) begin // @[SWChisel.scala 207:25]
      V1_3 <= array_2_io_v_o; // @[SWChisel.scala 210:15]
    end
    if (reset) begin // @[SWChisel.scala 164:19]
      V1_4 <= -16'sh5; // @[SWChisel.scala 164:19]
    end else if (start_reg_3) begin // @[SWChisel.scala 207:25]
      V1_4 <= array_3_io_v_o; // @[SWChisel.scala 210:15]
    end
    if (reset) begin // @[SWChisel.scala 164:19]
      V1_5 <= -16'sh6; // @[SWChisel.scala 164:19]
    end else if (start_reg_4) begin // @[SWChisel.scala 207:25]
      V1_5 <= array_4_io_v_o; // @[SWChisel.scala 210:15]
    end
    if (reset) begin // @[SWChisel.scala 164:19]
      V1_6 <= -16'sh7; // @[SWChisel.scala 164:19]
    end else if (start_reg_5) begin // @[SWChisel.scala 207:25]
      V1_6 <= array_5_io_v_o; // @[SWChisel.scala 210:15]
    end
    if (reset) begin // @[SWChisel.scala 166:19]
      V2_0 <= 16'sh0; // @[SWChisel.scala 166:19]
    end else begin
      V2_0 <= V1_0; // @[SWChisel.scala 226:11]
    end
    if (reset) begin // @[SWChisel.scala 166:19]
      V2_1 <= 16'sh0; // @[SWChisel.scala 166:19]
    end else begin
      V2_1 <= V1_1; // @[SWChisel.scala 226:11]
    end
    if (reset) begin // @[SWChisel.scala 166:19]
      V2_2 <= 16'sh0; // @[SWChisel.scala 166:19]
    end else begin
      V2_2 <= V1_2; // @[SWChisel.scala 226:11]
    end
    if (reset) begin // @[SWChisel.scala 166:19]
      V2_3 <= 16'sh0; // @[SWChisel.scala 166:19]
    end else begin
      V2_3 <= V1_3; // @[SWChisel.scala 226:11]
    end
    if (reset) begin // @[SWChisel.scala 166:19]
      V2_4 <= 16'sh0; // @[SWChisel.scala 166:19]
    end else begin
      V2_4 <= V1_4; // @[SWChisel.scala 226:11]
    end
    if (reset) begin // @[SWChisel.scala 166:19]
      V2_5 <= 16'sh0; // @[SWChisel.scala 166:19]
    end else begin
      V2_5 <= V1_5; // @[SWChisel.scala 226:11]
    end
    if (reset) begin // @[SWChisel.scala 167:26]
      start_reg_0 <= 1'h0; // @[SWChisel.scala 167:26]
    end else begin
      start_reg_0 <= io_start; // @[SWChisel.scala 185:16]
    end
    if (reset) begin // @[SWChisel.scala 167:26]
      start_reg_1 <= 1'h0; // @[SWChisel.scala 167:26]
    end else begin
      start_reg_1 <= start_reg_0; // @[SWChisel.scala 187:18]
    end
    if (reset) begin // @[SWChisel.scala 167:26]
      start_reg_2 <= 1'h0; // @[SWChisel.scala 167:26]
    end else begin
      start_reg_2 <= start_reg_1; // @[SWChisel.scala 187:18]
    end
    if (reset) begin // @[SWChisel.scala 167:26]
      start_reg_3 <= 1'h0; // @[SWChisel.scala 167:26]
    end else begin
      start_reg_3 <= start_reg_2; // @[SWChisel.scala 187:18]
    end
    if (reset) begin // @[SWChisel.scala 167:26]
      start_reg_4 <= 1'h0; // @[SWChisel.scala 167:26]
    end else begin
      start_reg_4 <= start_reg_3; // @[SWChisel.scala 187:18]
    end
    if (reset) begin // @[SWChisel.scala 167:26]
      start_reg_5 <= 1'h0; // @[SWChisel.scala 167:26]
    end else begin
      start_reg_5 <= start_reg_4; // @[SWChisel.scala 187:18]
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  E_0 = _RAND_0[15:0];
  _RAND_1 = {1{`RANDOM}};
  E_1 = _RAND_1[15:0];
  _RAND_2 = {1{`RANDOM}};
  E_2 = _RAND_2[15:0];
  _RAND_3 = {1{`RANDOM}};
  E_3 = _RAND_3[15:0];
  _RAND_4 = {1{`RANDOM}};
  E_4 = _RAND_4[15:0];
  _RAND_5 = {1{`RANDOM}};
  E_5 = _RAND_5[15:0];
  _RAND_6 = {1{`RANDOM}};
  F_1 = _RAND_6[15:0];
  _RAND_7 = {1{`RANDOM}};
  F_2 = _RAND_7[15:0];
  _RAND_8 = {1{`RANDOM}};
  F_3 = _RAND_8[15:0];
  _RAND_9 = {1{`RANDOM}};
  F_4 = _RAND_9[15:0];
  _RAND_10 = {1{`RANDOM}};
  F_5 = _RAND_10[15:0];
  _RAND_11 = {1{`RANDOM}};
  V1_0 = _RAND_11[15:0];
  _RAND_12 = {1{`RANDOM}};
  V1_1 = _RAND_12[15:0];
  _RAND_13 = {1{`RANDOM}};
  V1_2 = _RAND_13[15:0];
  _RAND_14 = {1{`RANDOM}};
  V1_3 = _RAND_14[15:0];
  _RAND_15 = {1{`RANDOM}};
  V1_4 = _RAND_15[15:0];
  _RAND_16 = {1{`RANDOM}};
  V1_5 = _RAND_16[15:0];
  _RAND_17 = {1{`RANDOM}};
  V1_6 = _RAND_17[15:0];
  _RAND_18 = {1{`RANDOM}};
  V2_0 = _RAND_18[15:0];
  _RAND_19 = {1{`RANDOM}};
  V2_1 = _RAND_19[15:0];
  _RAND_20 = {1{`RANDOM}};
  V2_2 = _RAND_20[15:0];
  _RAND_21 = {1{`RANDOM}};
  V2_3 = _RAND_21[15:0];
  _RAND_22 = {1{`RANDOM}};
  V2_4 = _RAND_22[15:0];
  _RAND_23 = {1{`RANDOM}};
  V2_5 = _RAND_23[15:0];
  _RAND_24 = {1{`RANDOM}};
  start_reg_0 = _RAND_24[0:0];
  _RAND_25 = {1{`RANDOM}};
  start_reg_1 = _RAND_25[0:0];
  _RAND_26 = {1{`RANDOM}};
  start_reg_2 = _RAND_26[0:0];
  _RAND_27 = {1{`RANDOM}};
  start_reg_3 = _RAND_27[0:0];
  _RAND_28 = {1{`RANDOM}};
  start_reg_4 = _RAND_28[0:0];
  _RAND_29 = {1{`RANDOM}};
  start_reg_5 = _RAND_29[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
