#include "../include/literalvalue.h"
#include "iostream"
int ValueLiteral::Get(const Memory &mem) const { return value_; }
ValueLiteral::~ValueLiteral() { std::cout << "~ValueLiteral" << std::endl; }

// Зачем передавать memory