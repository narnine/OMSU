#pragma once
#include "ioperation.h"
#include "ivalue.h"

class CmpOp : public IOperation {
  const IValue *const op1_;
  const IValue *const op2_;

public:
  CmpOp(const IValue *op1, const IValue *op2) : op1_(op1), op2_(op2) {}
  void Apply(Memory &mem) override;

  ~CmpOp();
};
