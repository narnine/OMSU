#include "include/addop.h"
#include "include/andop.h"
#include "include/cmpop.h"
#include "include/interpreter.h"
#include "include/jeqop.h"
#include "include/jgrop.h"
#include "include/jleop.h"
#include "include/jmpop.h"
#include "include/jnqop.h"
#include "include/literalvalue.h"
#include "include/memory.h"
#include "include/movop.h"
#include "include/mulop.h"
#include "include/notop.h"
#include "include/orop.h"
#include "include/registervalue.h"
#include "include/tokenizer.h"
#include "iostream"

int main() {
  Interpreter interpreter;

  Memory mem;
  mem.PushOp(new MovOp(
      new ValueRegister(r0),
      new ValueLiteral(5))); // первый операнд обязан быть IMutableValue, а
  // второй может быть просто IValue
  mem.PushOp(new MovOp(new ValueRegister(r1), new ValueLiteral(1)));
  mem.PushOp(new MovOp(new ValueRegister(r0), new ValueLiteral(1)));



  interpreter.Run(mem);
}
// interpreter.Run();
/*Questions
Зачем используем new
Как менять код в несколько строчках +
Override это метка
explicit
virtual зачем приравнивать нулю, для компилаятора
Как менять именна классов сразу и везде +
Если у двух родителей одни и тежи аргументы, а у ребенка нужно по-друшому- это
шибка проектирования Где-то используем коструктор, где-то нет почему
~Something = default - что если его убрать не будут уничтожаться
registervalue.h - там сам вопрос
Зачем наи иногда возращать const this как в Get только если у нас до этого this
был константной Почему в классах ValueRegister и LiteralValue мы не пишем
деструктор
У нас был массив ПРИВАТНЫЙ с instructions, просто так мы до него не достучимся,
почему GET() может?
Про дескрукторы у child
 Почему иногда нужно наследовать от public Parents
 Почему когда пишем virtual ~CommandOp происываем virtual, a void Apply(Memory&
mem), нет
 Почему деструктор пишем в Ioperation в ImutableValue в Ivalue, потом в командах но не в RegisterValue и ЛшеукфдМфдгу
Неопределенное поведенеие в memory.cpp при delete instraction;
 А мы же регистры и цифры создаем через new, почему там не пишем делит
 */