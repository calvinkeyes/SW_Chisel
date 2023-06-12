// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSW.h for the primary calling header

#include "verilated.h"

#include "VSW__Syms.h"
#include "VSW___024root.h"

void VSW___024root___ctor_var_reset(VSW___024root* vlSelf);

VSW___024root::VSW___024root(VSW__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VSW___024root___ctor_var_reset(this);
}

void VSW___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VSW___024root::~VSW___024root() {
}
