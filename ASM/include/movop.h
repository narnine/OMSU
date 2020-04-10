#pragma once
#include "ioperation.h"
#include "imutablevalue.h"

class MovOp : public IOperation {
  IMutableValue *const op1_;
  const IValue *const op2_;

public:
  MovOp(IMutableValue *op1, const IValue *op2) : op1_(op1), op2_(op2) {}

  void Apply(Memory &mem) override;

  ~MovOp();

};
