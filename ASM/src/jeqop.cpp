#include "../include/jeqop.h"

void JeOp::Apply(Memory &mem) {
  if (mem.GetReg(cmp) == 0) {
    mem.SetReg(line, mem.GetReg(line) + op1_->Get(mem));
    //    WHY?
    //    JmpOp jmpop(op1_);
    //    jmpop.Apply(mem);
  }
}
