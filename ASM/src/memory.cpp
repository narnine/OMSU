#include "../include/memory.h"
#include "../include/ioperation.h"
#include "iostream"

int Memory::GetReg(Register reg) const { return registers.find(reg)->second; }

IOperation *Memory::GetCurrentOp() const { return instructions[GetReg(line)]; }

void Memory::PushOp(IOperation *op) { instructions.push_back(op); }

int Memory::GetOpsCount() const { return instructions.size(); }

void Memory::SetReg(Register reg, int value) {
  registers.find(reg)->second = value;
}

void Memory::Push(int value) { stack.push(value); }

int Memory::Pop() {
  int a = stack.top();
  stack.pop();
  return a;
}

Memory::~Memory() {
  for (auto &instruction : instructions) {
    std::cout << "delete " << instruction << std::endl;
    delete instruction;
  }
  //  for (int i = 0; i < GetOpsCount(); i++) {
  //    std::cout << "delete instraction" << std::endl;
  //    delete instructions[i];
  //  }
}
