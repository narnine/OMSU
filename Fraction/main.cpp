#include <iostream>
#include <iterator> //set
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
using namespace std;

int NOK(int a, int b) {
  int x = a;
  int y = b;
  while (a != b) {
    if (a > b) {
      a = a - b;
    } else {
      b = b - a;
    }
  }
  int nok = x * (y / a);
  return nok;
}

int NOD(int n, int d) {

  while (n != 0 && d != 0) {
    if (n > d) {
      n = n % d;
    } else
      d = d % n;
  }
  return (n + d);
}

class Rational {
private:
  int Numer;
  int Denomin;

public:
  Rational(int n = 0, int d = 1) : Numer(n), Denomin(d) {
    if (d == 0) {
      throw invalid_argument("KAVO !!!");
    }
    if (Denomin < 0) {
      Numer *= -1;
      Denomin *= -1;
    }
    if ((n / d == 0) && (n % d == 0)) {
      Numer = 1;
      Denomin = 0;
    }

    int nod = NOD(n, d);
    Numer /= nod;
    Denomin /= nod;
  }

  int GetNumer() const { return Numer; }
  int GetDenomin() const { return Denomin; }

  // Почему с Rational &rat будет ругаться?
  Rational operator+(const Rational &rat) const {
    Rational r;
    if (Denomin != rat.Denomin) {
      r.Numer = Numer * rat.Denomin + rat.Numer * (Denomin);
      r.Denomin = Denomin * rat.Denomin;
    } else {
      r.Numer = Numer + rat.Numer;
    }
    return r;
  }

  Rational operator-(const Rational &rat) const {
    Rational r;
    if (Denomin != rat.Denomin) {
      r.Numer = Numer * rat.Denomin - rat.Numer * (Denomin);
      r.Denomin = Denomin * rat.Denomin;
    } else {
      r.Numer = Numer - rat.Numer;
    }
    return r;
  }

  Rational operator*(const Rational rat) const {
    Rational r = {Numer * rat.Numer, Denomin * rat.Denomin};
    return r;
  }

  Rational operator/(Rational rat) {
    Rational r = {Numer * rat.Denomin, Denomin * rat.Numer};
    return r;
  }

  bool operator<(const Rational &rat) const {
    return (Numer * rat.Denomin) < (rat.Numer * Denomin);
  }

  bool operator>(const Rational &rat) const {
    return (Numer * rat.Denomin) > (rat.Numer * Denomin);
  }

  bool operator>=(const Rational &rat) const {
    return (Numer * rat.Denomin) >= (rat.Numer * Denomin);
  }

  bool operator<=(const Rational &rat) const {
    return (Numer * rat.Denomin) <= (rat.Numer * Denomin);
  }

  bool operator==(const Rational &rat) const {
    return (Numer * rat.Denomin) == (rat.Numer * Denomin);
  }

  bool operator!=(const Rational &rat) const {
    return (Numer * rat.Denomin) != (rat.Numer * Denomin);
  }

  string ToString() const {
    stringstream ss;
    ss << GetNumer() << '/' << GetDenomin();
    return ss.str();
  }
};

ostream &operator<<(ostream &stream, const Rational &rational) {
  return stream << rational.ToString();
}

istream &operator>>(istream &stream, Rational &rational) {
  int n = 0;
  int d = 0;
  stream >> n;
  stream.ignore(1);
  stream >> d;
  rational = Rational{n, d};
  return stream;
}

float casttofloat(Rational r) {
  float a = static_cast<float>(r.GetNumer()) / r.GetDenomin();
  return a;
}

double casttodouble(Rational r) {
  double a = static_cast<double>(r.GetNumer()) / r.GetDenomin();
  return a;
}

int main() {
  // Rational r1;
  Rational r1 = {13, 7};
  Rational r2 = {2, 3};

  cout << r1 << endl;
  cout << r2 << endl;

  cout << Rational{13, 7} + Rational{2, 3} << endl;

  if (r1 < r2) {
    cout << r1 << "<" << r2 << endl;
  } else {
    cout << r1 << "=>" << r2 << endl;
  }

  const Rational r3 = r1 + r2;
  cout << r3 << endl;

  const Rational r4 = Rational(1, 2) + Rational(1, 3) - Rational(1, 4);
  if (r4 == Rational(7, 12)) {
    cout << "equal" << endl;
  }

  const Rational r5 = Rational(1, 6) * Rational(2, 3) / Rational(4, 3);
  cout << r5 << endl;

  const Rational r6 = Rational(1, 6) * Rational(2, 7) / Rational(4, 3);
  cout << r6 << endl;

  //  Rational r7;
  //  cin >> r7;
  //  cout << r7;

  float a1 = casttofloat(r1);
  cout << a1 << endl;

  float a2 = casttodouble(r1);
  cout << a2 << endl;

  cout << Rational(1,3) + Rational(7,4) << endl;
  cout << Rational(1,3) - Rational(7,4) << endl;
  cout << Rational(1,3) * Rational(7,4)* Rational(3,5) << endl;
//  set<Rational> rationals;
//  rationals.insert(Rational(1, 2));
//  rationals.insert(Rational(1, 3));
//
//  copy(rationals.begin(), rationals.end(),
//       ostream_iterator<Rational>(cout, " "));
//
//  map<Rational, string> name;
//  name[Rational(1, 2)] = "одна вторая";
//  name[Rational(1, 3)] = "одна треть";
//
//  cout << name.at(Rational(1, 2)) << endl;
//
//  auto it = name.begin();
//  for (int i = 0; it != name.end(); it++, i++) {
//    cout << " Ключ - " << it->first << ", значение - " << it->second << endl;
//  }
//
//  for (auto &p : name) {
//    cout << " Ключ - " << p.first << ", значение - " << p.second << endl;
//  }

  return 0;
}
