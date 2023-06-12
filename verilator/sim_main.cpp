// DESCRIPTION: Verilator: Verilog example module
//
// This file ONLY is placed under the Creative Commons Public Domain, for
// any use, without warranty, 2017 by Wilson Snyder.
// SPDX-License-Identifier: CC0-1.0
//======================================================================

// For std::unique_ptr
#include <memory>

// Include common routines
#include <verilated.h>

// Include model header, generated from Verilating "SWCell.v"
#include "VSW.h"

// Include files for C model
#include <iostream>
#include <array>

#include "systolic.hpp"
#include "smith_waterman.hpp"
#include "arrayops.hpp"
#include "utility.hpp"
#include "map.hpp"

// Legacy function required only so linking works on Cygwin and MSVC++
double sc_time_stamp() { return 0; }

// Smith Waterman Struct from C model
struct SmithWatermanUnit{
	// Base, recursive operator
	score operator()(hw_base const& read,
			sw_ref const& ref,
			std::array<std::array<score, SW_HIST>, 1> const& smatrix) const{
		score ret = {0,0,0};
		return ret;
	}

	// Recursive operator
	template <std::size_t IDX>
	score operator()(hw_base const& read,
			sw_ref const& ref,
			std::array<std::array<score, SW_HIST>, IDX> const& smatrix) const{
		score ret;
		short int sigma;
		if(ref.last){
#ifdef BIT_ACCURATE
			ret = {(ap_int<hops::clog2(IDX)+1>)-(IDX),
			       (ap_int<hops::clog2(IDX)+1>)-(IDX),
			       (ap_int<hops::clog2(IDX)+1>)-(IDX)};
#else
			ret = {(short int)-(IDX), (short int)-(IDX), (short int)-(IDX)};
#endif
		}else{
			sigma = (read == ref.b)? MATCH: -MATCH;
			ret.e = std::max(smatrix[0][0].v - ALPHA, 
					smatrix[0][0].e - BETA);
			ret.f = std::max(smatrix[1][0].v - ALPHA,
					smatrix[1][0].f - BETA);
			ret.v = std::max((short int)(smatrix[1][1].v + sigma),
					std::max(ret.e, ret.f));
		}
		return ret;
	}

    score operator()(std::size_t const& IDX,
			hw_base const& read,
			sw_ref const& ref,
			std::array<std::array<score, SW_HIST>, READ_LENGTH> const& smatrix) const{
		score ret;
		short int sigma;
		if(IDX == 0){
			ret = {0,0,0};
		} else {
			if(ref.last){
				ret = {(short int)-(IDX+1), (short int)-(IDX+1), (short int)-(IDX+1)};
			}else{
				sigma = (read == ref.b)? MATCH: -MATCH;
				ret.e = std::max(smatrix[IDX + 0][0].v - ALPHA,
						smatrix[IDX + 0][0].e - BETA);
				ret.f = std::max(smatrix[IDX - 1][0].v - ALPHA,
						smatrix[IDX - 1][0].f - BETA);
				ret.v = std::max((short int)(smatrix[IDX - 1][1].v + sigma),
						std::max(ret.e, ret.f));
			}
		}
		return ret;
	}

} sw_op;

// convert base to integer
int send_to_hw(short int base) {
    switch(base){
		case 'a':
			return 0;
		case 'c':
			return 1;
		case 't':
			return 2;
		case 'g':
			return 3;
		default:
			return 0;
		}
}


// Test Smith Wateran
int main(int argc, char** argv) {

    // Prevent unused variable warnings
    if (false && argc && argv) {}

    // Create logs/ directory in case we have traces to put under it
    Verilated::mkdir("logs");

    // Using unique_ptr is similar to
    // "VerilatedContext* contextp = new VerilatedContext" then deleting at end.
    const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};
    // Do not instead make VSWCell as a file-scope static variable, as the
    // "C++ static initialization order fiasco" may cause a crash

    // Set debug level, 0 is off, 9 is highest presently used
    // May be overridden by commandArgs argument parsing
    contextp->debug(0);

    // Randomization reset policy
    // May be overridden by commandArgs argument parsing
    contextp->randReset(2);

    // Verilator must compute traced signals
    contextp->traceEverOn(true);

    // Pass arguments so Verilated code can see them, e.g. $value$plusargs
    // This needs to be called before you create any model
    contextp->commandArgs(argc, argv);

    // Construct the Verilated model, from VSWCell.h generated from Verilating "SWCell.v".
    // Using unique_ptr is similar to "VSWCell* SWCell = new VSWCell" then deleting at end.
    // "SWCELL" will be the hierarchical name of the module.
    const std::unique_ptr<VSW> SW{new VSW{contextp.get(), "SW"}};

    // Set up Smith Waterman C model variables
    int err;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<unsigned short int> distribution(0, 1<<(8*sizeof(unsigned short int) - 1));
	
	std::array<base, READ_LENGTH> read;

	std::array<sw_ref, READ_LENGTH> soln_top;
	std::array<base, REF_LENGTH> soln_ref;
	matrix<score, REF_LENGTH, READ_LENGTH> soln;

	std::array<sw_ref, READ_LENGTH> top;
	std::array<base, REF_LENGTH> ref;
	matrix<score, SW_HIST, READ_LENGTH> smatrix;

    // Fill the read 
	read[0] = 'x';
    printf("read: ");
	for(std::size_t i = 1; i < READ_LENGTH; ++i){
		read[i] = randtobase(distribution(gen));
        printf("%c",read[i]);
	}
    printf("\n");

	// Fill the reference
	ref[0] = 'x';
	soln_ref[0] = 'x';
    printf("ref: ");
	for(std::size_t i = 1; i < REF_LENGTH; ++i){
		ref[i] = randtobase(distribution(gen));
		soln_ref[i] = ref[i];
        printf("%c",soln_ref[i]);
	}
    printf("\n");

    // Initialize Solution Matrix
	for(int y = 0; y < READ_LENGTH; ++y){
		for(int x = 0; x < REF_LENGTH; ++x){
			soln[y][x] = {0,0,0};
		}
	}

    // Compute the entire solution matrix
	for(int cyc = 0; cyc < REF_LENGTH; ++cyc){
		for(int k = READ_LENGTH-1; k > 0; --k){
			soln_top[k] = soln_top[k-1];
		}

		soln_top[0] = {to_hw_base(soln_ref[cyc]), soln_ref[cyc]=='x'};
		for(int sr_idx = 0, sr_cyc = cyc; (sr_idx < READ_LENGTH) && (sr_cyc >= 0); ++sr_idx, sr_cyc--){
			if(sr_idx == 0){
				soln[sr_idx][cyc] = {0,0,0};
			} else{
				if(soln_top[sr_idx].last){
					soln[sr_idx][sr_cyc] = {(short int)-(sr_idx+1), (short int)-(sr_idx+1), (short int)-(sr_idx+1)};
				} else {
					score temp;
					short int sigma = (to_hw_base(read[sr_idx]) == soln_top[sr_idx].b)? 2: -2;
					temp.e = std::max(soln[sr_idx][sr_cyc-1].v - ALPHA, 
							soln[sr_idx][sr_cyc-1].e - BETA);
					temp.f = std::max(soln[sr_idx-1][sr_cyc].v - ALPHA, 
							soln[sr_idx-1][sr_cyc].f - BETA);
					temp.v = std::max((short int)(soln[sr_idx-1][sr_cyc-1].v + sigma), 
							std::max(temp.e, temp.f));
					soln[sr_idx][sr_cyc] = temp;
				}
			}
		}
	}

    // Set VSW's input signals
	SW->reset = !0;
	SW->clock = 0;
    
	SW->io_q_0_b = send_to_hw(read[1]);
	SW->io_q_1_b = send_to_hw(read[2]);
	SW->io_q_2_b = send_to_hw(read[3]);
	SW->io_q_3_b = send_to_hw(read[4]);
	SW->io_q_4_b = send_to_hw(read[5]);
	SW->io_q_5_b = send_to_hw(read[6]);
	SW->io_q_6_b = send_to_hw(read[7]);
	SW->io_q_7_b = send_to_hw(read[8]);
	SW->io_q_8_b = send_to_hw(read[9]);
	SW->io_q_9_b = send_to_hw(read[10]);

	SW->io_r_0_b = send_to_hw(ref[1]);
	SW->io_r_1_b = send_to_hw(ref[2]);
	SW->io_r_2_b = send_to_hw(ref[3]);
	SW->io_r_3_b = send_to_hw(ref[4]);
	SW->io_r_4_b = send_to_hw(ref[5]);
	SW->io_r_5_b = send_to_hw(ref[6]);
	SW->io_r_6_b = send_to_hw(ref[7]);
	SW->io_r_7_b = send_to_hw(ref[8]);
	SW->io_r_8_b = send_to_hw(ref[9]);
	SW->io_r_9_b = send_to_hw(ref[10]);
	SW->io_r_10_b = send_to_hw(ref[11]);
	SW->io_r_11_b = send_to_hw(ref[12]);
	SW->io_r_12_b = send_to_hw(ref[13]);
	SW->io_r_13_b = send_to_hw(ref[14]);
	SW->io_r_14_b = send_to_hw(ref[15]);
	SW->io_r_15_b = send_to_hw(ref[16]);
	SW->io_r_16_b = send_to_hw(ref[17]);

    SW->io_start = 0;

    // Start in reset state
    SW->eval();
    // step the clock
    SW->clock = !SW->clock;	
    SW->eval();
    SW->clock = !SW->clock;
    contextp->timeInc(1);
    
    // start the device
    SW->reset = 0;
    SW->io_start = 1;
    SW->eval();

    // step the clock
    SW->clock = !SW->clock;	
    SW->eval();
    SW->clock = !SW->clock;
    contextp->timeInc(1);
    SW->eval();
    SW->clock = !SW->clock;
    SW->eval();
    SW->clock = !SW->clock;
    contextp->timeInc(1);

    // Check ramp up scoring
	for (int j = 1; j < (READ_LENGTH); j++) {
	
        // SW->eval();
        for (int i = 0; i < j; i++){
            //printf("%d ",soln[i+1][j-i].v);
            switch(i+1){                
				case(1):
					//printf("%hd\n", SW->io_v1_out_1);
					assert(soln[i+1][j-i].v == (char)SW->io_v1_out_1);
					break;
				case(2):
					//printf("%hd\n", SW->io_v1_out_2);
					assert(soln[i+1][j-i].v == (char)SW->io_v1_out_2);
					break;
				case(3):
					//printf("%hd\n", SW->io_v1_out_3);
					assert(soln[i+1][j-i].v == (char)SW->io_v1_out_3);
					break;
				case(4):
					//printf("%hd\n", SW->io_v1_out_4);
					assert(soln[i+1][j-i].v == (char)SW->io_v1_out_4);
					break;
				case(5):
					//printf("%hd\n", SW->io_v1_out_5);
					assert(soln[i+1][j-i].v == (char)SW->io_v1_out_5);
					break;
				case(6):
					//printf("%hd\n", SW->io_v1_out_6);
					assert(soln[i+1][j-i].v == (char)SW->io_v1_out_6);
					break;
				case(7):
					//printf("%hd\n", SW->io_v1_out_7);
					assert(soln[i+1][j-i].v == (char)SW->io_v1_out_7);
					break;
				case(8):
					//printf("%hd\n", SW->io_v1_out_8);
					assert(soln[i+1][j-i].v == (char)SW->io_v1_out_8);
					break;
				case(9):
					//printf("%hd\n", SW->io_v1_out_9);
					assert(soln[i+1][j-i].v == (char)SW->io_v1_out_9);
					break;
				case(10):
					//printf("%hd\n", SW->io_v1_out_10);
					assert(soln[i+1][j-i].v == (char)SW->io_v1_out_10);
					break;
				default:
					break;
            }
        }
        // step the clock
        SW->eval();
		SW->clock = !SW->clock;	
        SW->eval();
        SW->clock = !SW->clock;

        //increment time signal
        contextp->timeInc(1);
		
	}	

    // check pipeline full testing
    for (int j = READ_LENGTH; j < REF_LENGTH-1; j++) {
        
         for (int i = 0; i < READ_LENGTH-1; i++){
            //printf("%d ",soln[i+1][j-i].v);
            switch(i+1){
				case(1):
					//printf("%hd\n", SW->io_v1_out_1);
					assert(soln[i+1][j-i].v == (char)SW->io_v1_out_1);
					break;
				case(2):
					//printf("%hd\n", SW->io_v1_out_2);
					assert(soln[i+1][j-i].v == (char)SW->io_v1_out_2);
					break;
				case(3):
					//printf("%hd\n", SW->io_v1_out_3);
					assert(soln[i+1][j-i].v == (char)SW->io_v1_out_3);
					break;
				case(4):
					//printf("%hd\n", SW->io_v1_out_4);
					assert(soln[i+1][j-i].v == (char)SW->io_v1_out_4);
					break;
				case(5):
					//printf("%hd\n", SW->io_v1_out_5);
					assert(soln[i+1][j-i].v == (char)SW->io_v1_out_5);
					break;
				case(6):
					//printf("%hd\n", SW->io_v1_out_6);
					assert(soln[i+1][j-i].v == (char)SW->io_v1_out_6);
					break;
				case(7):
					//printf("%hd\n", SW->io_v1_out_7);
					assert(soln[i+1][j-i].v == (char)SW->io_v1_out_7);
					break;
				case(8):
					//printf("%hd\n", SW->io_v1_out_8);
					assert(soln[i+1][j-i].v == (char)SW->io_v1_out_8);
					break;
				case(9):
					//printf("%hd\n", SW->io_v1_out_9);
					assert(soln[i+1][j-i].v == (char)SW->io_v1_out_9);
					break;
				case(10):
					//printf("%hd\n", SW->io_v1_out_10);
					assert(soln[i+1][j-i].v == (char)SW->io_v1_out_10);
					break;
				default:
					break;
            }
        }

        // step the clock
        SW->eval();
		SW->clock = !SW->clock;	
        SW->eval();
        SW->clock = !SW->clock;

        //increment time signal
        contextp->timeInc(1);
    }

    // step through the rest of the array
    for (int j = REF_LENGTH; j < REF_LENGTH+READ_LENGTH; j++) {
        SW->eval();
		SW->clock = !SW->clock;	
        SW->eval();
        SW->clock = !SW->clock;

        //increment time signal
        contextp->timeInc(1);
    }

    // assert done
    assert(true == SW->io_done);
    printf("Test Passed\n");

    // Final model cleanup
    SW->final();

    // Return good completion status
    // Don't use exit() or destructor won't get called
    return 0;
}

