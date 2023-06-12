// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VSW_H_
#define VERILATED_VSW_H_  // guard

#include "verilated.h"

class VSW__Syms;
class VSW___024root;

// This class is the main interface to the Verilated model
class VSW VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    VSW__Syms* const vlSymsp;

  public:

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&clock,0,0);
    VL_IN8(&reset,0,0);
    VL_IN8(&io_q_0_b,1,0);
    VL_IN8(&io_q_1_b,1,0);
    VL_IN8(&io_q_2_b,1,0);
    VL_IN8(&io_q_3_b,1,0);
    VL_IN8(&io_q_4_b,1,0);
    VL_IN8(&io_q_5_b,1,0);
    VL_IN8(&io_q_6_b,1,0);
    VL_IN8(&io_q_7_b,1,0);
    VL_IN8(&io_q_8_b,1,0);
    VL_IN8(&io_q_9_b,1,0);
    VL_IN8(&io_r_0_b,1,0);
    VL_IN8(&io_r_1_b,1,0);
    VL_IN8(&io_r_2_b,1,0);
    VL_IN8(&io_r_3_b,1,0);
    VL_IN8(&io_r_4_b,1,0);
    VL_IN8(&io_r_5_b,1,0);
    VL_IN8(&io_r_6_b,1,0);
    VL_IN8(&io_r_7_b,1,0);
    VL_IN8(&io_r_8_b,1,0);
    VL_IN8(&io_r_9_b,1,0);
    VL_IN8(&io_r_10_b,1,0);
    VL_IN8(&io_r_11_b,1,0);
    VL_IN8(&io_r_12_b,1,0);
    VL_IN8(&io_r_13_b,1,0);
    VL_IN8(&io_r_14_b,1,0);
    VL_IN8(&io_r_15_b,1,0);
    VL_IN8(&io_r_16_b,1,0);
    VL_IN8(&io_start,0,0);
    VL_OUT8(&io_done,0,0);
    VL_OUT16(&io_result,15,0);
    VL_OUT16(&io_v1_out_0,15,0);
    VL_OUT16(&io_v1_out_1,15,0);
    VL_OUT16(&io_v1_out_2,15,0);
    VL_OUT16(&io_v1_out_3,15,0);
    VL_OUT16(&io_v1_out_4,15,0);
    VL_OUT16(&io_v1_out_5,15,0);
    VL_OUT16(&io_v1_out_6,15,0);
    VL_OUT16(&io_v1_out_7,15,0);
    VL_OUT16(&io_v1_out_8,15,0);
    VL_OUT16(&io_v1_out_9,15,0);
    VL_OUT16(&io_v1_out_10,15,0);
    VL_OUT16(&io_v2_out_0,15,0);
    VL_OUT16(&io_v2_out_1,15,0);
    VL_OUT16(&io_v2_out_2,15,0);
    VL_OUT16(&io_v2_out_3,15,0);
    VL_OUT16(&io_v2_out_4,15,0);
    VL_OUT16(&io_v2_out_5,15,0);
    VL_OUT16(&io_v2_out_6,15,0);
    VL_OUT16(&io_v2_out_7,15,0);
    VL_OUT16(&io_v2_out_8,15,0);
    VL_OUT16(&io_v2_out_9,15,0);
    VL_OUT16(&io_v2_out_10,15,0);
    VL_OUT16(&io_e_out_0,15,0);
    VL_OUT16(&io_e_out_1,15,0);
    VL_OUT16(&io_e_out_2,15,0);
    VL_OUT16(&io_e_out_3,15,0);
    VL_OUT16(&io_e_out_4,15,0);
    VL_OUT16(&io_e_out_5,15,0);
    VL_OUT16(&io_e_out_6,15,0);
    VL_OUT16(&io_e_out_7,15,0);
    VL_OUT16(&io_e_out_8,15,0);
    VL_OUT16(&io_e_out_9,15,0);
    VL_OUT16(&io_f_out_0,15,0);
    VL_OUT16(&io_f_out_1,15,0);
    VL_OUT16(&io_f_out_2,15,0);
    VL_OUT16(&io_f_out_3,15,0);
    VL_OUT16(&io_f_out_4,15,0);
    VL_OUT16(&io_f_out_5,15,0);
    VL_OUT16(&io_f_out_6,15,0);
    VL_OUT16(&io_f_out_7,15,0);
    VL_OUT16(&io_f_out_8,15,0);
    VL_OUT16(&io_f_out_9,15,0);
    VL_OUT16(&io_f_out_10,15,0);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    VSW___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit VSW(VerilatedContext* contextp, const char* name = "TOP");
    explicit VSW(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~VSW();
  private:
    VL_UNCOPYABLE(VSW);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
