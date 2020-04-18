#include "../include/mulop.h"
#include "iostream"
void MulOp::Apply(Memory &mem) {
  op1_->Set(mem, op1_->Get(mem) * op2_->Get(mem));
}
MulOp::~MulOp() {
  delete op1_;
  delete op2_;
  std::cout << "~MulOp" << std::endl;
}
