/* verilator lint_off VARHIDDEN */

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
  reg [4:0] counter; // @[SWChisel.scala 133:24]
  wire [4:0] _counter_T_1 = counter - 5'h1; // @[SWChisel.scala 135:24]
  assign io_done = counter == 5'h0; // @[SWChisel.scala 141:17]
  assign io_out = max; // @[SWChisel.scala 123:10]
  always @(posedge clock) begin
    if (reset) begin // @[SWChisel.scala 122:20]
      max <= 16'sh8000; // @[SWChisel.scala 122:20]
    end else if ($signed(io_in) > $signed(max)) begin // @[SWChisel.scala 126:22]
      max <= io_in; // @[SWChisel.scala 127:9]
    end
    if (reset) begin // @[SWChisel.scala 133:24]
      counter <= 5'h12; // @[SWChisel.scala 133:24]
    end else if (counter == 5'h0) begin // @[SWChisel.scala 141:26]
      counter <= 5'h0; // @[SWChisel.scala 143:13]
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
  counter = _RAND_1[4:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
