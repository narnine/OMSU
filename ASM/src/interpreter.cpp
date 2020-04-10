#include "../include/interpreter.h"
#include "../include/ioperation.h"
class IOperation;

void Interpreter::Run(Memory &mem, int maxIterations) const {
  while (mem.GetReg(line) < mem.GetOpsCount() && maxIterations > 0) {
    IOperation* op = mem.GetCurrentOp();
    op->Apply(mem);
    mem.SetReg(line, mem.GetReg(line) + 1);
    maxIterations--;
  }
}
