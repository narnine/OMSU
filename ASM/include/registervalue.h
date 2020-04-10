#pragma once
#include "imutablevalue.h"

class ValueRegister : public IMutableValue {
  const Register reg_; // Что это значит? Константная поле, которое содержит регистр

public:
  explicit ValueRegister(Register reg) : reg_(reg) {}
  int Get(const Memory &mem) const override;
  void Set(Memory &mem, int value) override;
  ~ValueRegister();
};
