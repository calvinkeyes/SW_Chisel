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
	SW->io_q = 0;
    SW->io_r = 0;
    SW->io_top = 0;
    SW->io_diag = 0;
    SW->io_left = 0;

	for (int i = 0; i < 8; i++) {
		
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
			SW->io_q = 1;
            SW->io_r = 1;
            SW->io_top = 3;
            SW->io_diag = 2;
            SW->io_left = 4;
		}

		// Evaluate the model
		SW->eval();

		// print out the variables
		VL_PRINTF("[%" PRId64 "] clock=%x reset=%x -> io_q=%x io_r=%x io_top=%x io_diag=%x io_left=%x io_result=%x\n",
                  contextp->time(), SW->clock, SW->reset, SW->io_q,
                  SW->io_r, SW->io_top, SW->io_diag, SW->io_left, SW->io_result);	
	}	

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
