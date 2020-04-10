#pragma once
#include "ioperation.h"
#include "ivalue.h"
#include "imutablevalue.h"


class AddOp : public IOperation {
    IMutableValue *const op1_;
    const IValue *const op2_;

public:
    AddOp(IMutableValue *op1, const IValue *op2) : op1_(op1), op2_(op2) {}
    void Apply(Memory &mem) override;

    ~AddOp();
};

// Почему мы у нас поля не ValueRegister и literalValue и можно ли фунции Apply
// дописать туда аргументы Vsaluereigst value написать over как мы доних
// дсотучимся из мемори/