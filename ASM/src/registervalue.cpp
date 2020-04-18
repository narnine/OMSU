#include "../include/registervalue.h"
#include "iostream"

int ValueRegister::Get(const Memory &mem) const { return mem.GetReg(reg_); }

void ValueRegister::Set(Memory &mem, int value) { mem.SetReg(reg_, value); }
ValueRegister::~ValueRegister() { std::cout << "~ValueLiteral" << std::endl; }
