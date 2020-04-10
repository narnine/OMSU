#pragma once
#include "ivalue.h"

class ValueLiteral : public IValue {
  const int value_;

public:
  explicit ValueLiteral(int value) : value_(value) {}
  int Get(const Memory& mem) const override ;
  ~ValueLiteral();
};
