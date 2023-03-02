module SWCell(
  input   clock,
  input   reset,
  input   io_in,
  output  io_out
);
  assign io_out = ~io_in; // @[SWChisel.scala 16:13]
  always @(posedge clock) begin
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (~reset) begin
          $fwrite(32'h80000002,"Hello World\n"); // @[SWChisel.scala 15:9]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
  end
endmodule
