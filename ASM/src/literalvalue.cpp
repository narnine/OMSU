#include "../include/literalvalue.h"
int ValueLiteral::Get(const Memory &mem) const { return value_; }
ValueLiteral::~ValueLiteral() { std::cout << "~ValueLiteral" << std::endl; }

// Зачем передавать memory