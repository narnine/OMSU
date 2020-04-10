#include "../include/memory.h"

IOperation *Memory::GetCurrentOp() const { return instructions[line]; }

void Memory::PushOp(IOperation *op) { instructions.push_back(op); }

int Memory::GetOpsCount() const { return registers.size(); }

void Memory::SetReg(Register reg, int value) { registers[reg] = value; }

int Memory::GetReg(Register reg) const { return registers.at(reg); }

void Memory::Push(int value) { stack.push(value); }

int Memory::Pop() {
  int a = stack.top();
  stack.pop();
  return a;
}

Memory::~Memory() {
  //  for (auto &instruction : instructions) {
  //    std::cout << "delete " << instruction << std::endl;
  //    delete instruction;
  //  }
  for (int i = 0; i < GetOpsCount(); i++) {
    std::cout << "delete instraction" << std::endl;
    delete instructions[i];
  }
}
