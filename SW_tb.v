`timescale 1ns / 1ns
// Import the main code into the testbench
`include "SW.v"

module SW_tb;

    // inputs as registers
    reg clock;
    reg reset;
    reg io_start;
    reg [1:0] io_q_0_b;
    reg [1:0] io_q_1_b;
    reg [1:0] io_q_2_b;
    reg [1:0] io_q_3_b;
    reg [1:0] io_q_4_b;
    reg [1:0] io_q_5_b;
    reg [1:0] io_r_0_b;
    reg [1:0] io_r_1_b;
    reg [1:0] io_r_2_b;
    reg [1:0] io_r_3_b;
    reg [1:0] io_r_4_b;
    reg [1:0] io_r_5_b;
    reg [1:0] io_r_6_b;
    reg [1:0] io_r_7_b;
    reg [1:0] io_r_8_b;
    reg [1:0] io_r_9_b;

    // Outputs as wires
    wire [4:0] io_result;
    wire io_done;

    SW dut(
        .clock(clock),
        .reset(reset),
        .io_start(io_start),
        .io_q_0_b(io_q_0_b),
        .io_q_1_b(io_q_1_b),
        .io_q_2_b(io_q_2_b),
        .io_q_3_b(io_q_3_b),
        .io_q_4_b(io_q_4_b),
        .io_q_5_b(io_q_5_b),
        .io_r_0_b(io_r_0_b),
        .io_r_1_b(io_r_1_b),
        .io_r_2_b(io_r_2_b),
        .io_r_3_b(io_r_3_b),
        .io_r_4_b(io_r_4_b),
        .io_r_5_b(io_r_5_b),
        .io_r_6_b(io_r_6_b),
        .io_r_7_b(io_r_7_b),
        .io_r_8_b(io_r_8_b),
        .io_r_9_b(io_r_9_b),
        .io_result(io_result),
        .io_done(io_done)
    );

    always 
        #5 clock = !clock;

    integer i;

    initial begin
        $dumpfile("sw_tb.vcd");
        $dumpvars(0,SW_tb);

        clock = 0;

        io_q_0_b = 0;
        io_q_1_b = 1;
        io_q_2_b = 2;
        io_q_3_b = 3;
        io_q_4_b = 4;
        io_q_5_b = 5;

        io_r_0_b = 0;
        io_r_1_b = 3;
        io_r_2_b = 2;
        io_r_3_b = 0;
        io_r_4_b = 1;
        io_r_5_b = 2;
        io_r_6_b = 3;
        io_r_7_b = 1;
        io_r_8_b = 3;
        io_r_9_b = 0;

        io_start = 1'b0;
        reset = 1'b1;


        @(posedge clock);
        #1
        io_start = 1'b1;
        reset = 1'b0;
        @(posedge clock); 

        for (i = 0; i < 11; i= i+ 1) begin
            @(posedge clock);
        end

        #5
        io_start = 1'b0;

        while (io_done == 1'b0) begin
            @(posedge clock);
            $display("cycle: %d",i);
            $display("done? %d", io_done);
            $display("result: %d", io_result);
            i = i + 1;
        end

        $display("result: %d",io_result);
        $finish;

    end
endmodule