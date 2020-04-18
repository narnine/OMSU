#include "../include/addop.h"
#include "iostream"
void AddOp::Apply(Memory &mem) { op1_->Set(mem, op1_->Get(mem) + op2_->Get(mem)); }
AddOp::~AddOp() {
  delete op1_ ;
  delete op2_;
  std::cout << "~AddOp" << std::endl;
}
