#pragma once
#include "memory.h"

class Interpreter {
public:
  void Run(Memory &mem, int maxIterations = 100) const;
};
