#pragma once
#include "memory.h"

class IOperation {
public:
  virtual void Apply(Memory &mem) = 0;
  virtual ~IOperation() = default;
//TODO cout
};
;
// ValueRegister &regist, IValue &value