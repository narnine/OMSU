#pragma once
#include "ivalue.h"

class IMutableValue : public IValue {
public:
  virtual void Set(Memory &mem, int value) = 0;
  ~IMutableValue() override  = default;
};