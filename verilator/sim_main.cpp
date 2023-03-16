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

// Include model header, generated from Verilating "SW.v"
#include "VSW.h"

// Legacy function required only so linking works on Cygwin and MSVC++
double sc_time_stamp() { return 0; }

int main(int argc, char** argv) {
    // This is a more complicated example, please also see the simpler examples/make_hello_c.

    // Prevent unused variable warnings
    if (false && argc && argv) {}

    // Create logs/ directory in case we have traces to put under it
    Verilated::mkdir("logs");

    // Construct a VerilatedContext to hold simulation time, etc.
    // Multiple modules (made later below with VSW) may share the same
    // context to share time, or modules may have different contexts if
    // they should be independent from each other.

    // Using unique_ptr is similar to
    // "VerilatedContext* contextp = new VerilatedContext" then deleting at end.
    const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};
    // Do not instead make VSW as a file-scope static variable, as the
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

    // Construct the Verilated model, from VSW.h generated from Verilating "SW.v".
    // Using unique_ptr is similar to "VSW* SW = new VSW" then deleting at end.
    // "SW" will be the hierarchical name of the module.
    const std::unique_ptr<VSW> SW{new VSW{contextp.get(), "SW"}};

    // Set VSW's input signals
	SW->reset = !0;
	SW->clock = 0;
	SW->io_in = 0;

	for (int i = 0; i < 16; i++) {
		
		// increment time signal
		contextp->timeInc(1);

		// create fast clock
		SW->clock = !SW->clock;	
		
		// set reset logic
		if (!SW->clock) {
			if (contextp->time() > 1 && contextp->time() < 10) {
				SW->reset = !1; // Assert reset
			} else {
				SW->reset = !0;
			}
			// toggle input value
			SW->io_in = !SW->io_in;
		}

		// Evaluate the model
		SW->eval();

		// print out the variables
		VL_PRINTF("[%" PRId64 "] clock=%x reset=%x -> io_in=%x io_out=%x\n",
                  contextp->time(), SW->clock, SW->reset, SW->io_in,
                  SW->io_out);
        
		
		// SW->io_in = !SW->io_in;
		
	}	

    // Simulate until $finish
//    while (!contextp->gotFinish()) {
//        // Historical note, before Verilator 4.200 Verilated::gotFinish()
//        // was used above in place of contextp->gotFinish().
//        // Most of the contextp-> calls can use Verilated:: calls instead;
//        // the Verilated:: versions just assume there's a single context
//        // being used (per thread).  It's faster and clearer to use the
//        // newer contextp-> versions.
//
//        contextp->timeInc(1);  // 1 timeprecision period passes...
//        // Historical note, before Verilator 4.200 a sc_time_stamp()
//        // function was required instead of using timeInc.  Once timeInc()
//        // is called (with non-zero), the Verilated libraries assume the
//        // new API, and sc_time_stamp() will no longer work.
//
//        // Toggle a fast (time/2 period) clock
//        SW->clk = !SW->clk;
//
//        // Toggle control signals on an edge that doesn't correspond
//        // to where the controls are sampled; in this example we do
//        // this only on a negedge of clk, because we know
//        // reset is not sampled there.
//        if (!SW->clk) {
//            if (contextp->time() > 1 && contextp->time() < 10) {
//                SW->reset_l = !1;  // Assert reset
//            } else {
//                SW->reset_l = !0;  // Deassert reset
//            }
//            // Assign some other inputs
//            // SW->in_quad += 0x12;
//        }
//
//        // Evaluate model
//        // (If you have multiple models being simulated in the same
//        // timestep then instead of eval(), call eval_step() on each, then
//        // eval_end_step() on each. See the manual.)
//        SW->eval();
//
//        // Read outputs
//        //VL_PRINTF("[%" PRId64 "] clk=%x rstl=%x -> oquad=%" PRIx64
//        //          " owide=%x_%08x_%08x\n",
//        //          contextp->time(), SW->clk, SW->reset_l, SW->out_quad,
//        //          SW->out_wide[2], SW->out_wide[1], SW->out_wide[0]);
//    }

    // Final model cleanup
    SW->final();

    // Coverage analysis (calling write only after the test is known to pass)
#if VM_COVERAGE
    Verilated::mkdir("logs");
    contextp->coveragep()->write("logs/coverage.dat");
#endif

    // Return good completion status
    // Don't use exit() or destructor won't get called
    return 0;
}
