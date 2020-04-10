#include "../include/movop.h"
#include "iostream"

void MovOp::Apply(Memory &mem) {
  //  mem.SetReg(mem.registers[op1_], op2_->Get(mem));
  op1_->Set(mem, op2_->Get(mem));
  mem.Push(op2_->Get(mem));
}
MovOp::~MovOp() {
  std::cout << "delete - op1_ " << op1_ << std::endl;
  delete op1_;
  delete op2_;
  std::cout << "~MovOp" << std::endl;
}

// нужно так?
// Memory& mem;
// mutablevalue.Set(mem, value);
