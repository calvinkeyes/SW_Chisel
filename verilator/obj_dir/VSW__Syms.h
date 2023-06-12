// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSW__SYMS_H_
#define VERILATED_VSW__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VSW.h"

// INCLUDE MODULE CLASSES
#include "VSW___024root.h"

// SYMS CLASS (contains all model state)
class VSW__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VSW* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VSW___024root                  TOP;

    // CONSTRUCTORS
    VSW__Syms(VerilatedContext* contextp, const char* namep, VSW* modelp);
    ~VSW__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
