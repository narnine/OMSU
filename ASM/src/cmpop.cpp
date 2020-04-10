#include "../include/cmpop.h"
void CmpOp::Apply(Memory &mem) {
  if (op1_->Get(mem) == op2_->Get(mem)) {
    mem.SetReg(cmp, 0);
  } else if (op1_->Get(mem) > op2_->Get(mem)) {
    mem.SetReg(cmp, 1);
  } else {
    mem.SetReg(cmp, -1);
  }
}
CmpOp::~CmpOp() {
  delete op1_;
  delete op2_;
  std::cout << "~CmpOp" << std::endl;
}
