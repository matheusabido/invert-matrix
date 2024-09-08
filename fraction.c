#include "fraction.h"

Fraction fadd(Fraction a, Fraction b) {
  int d = mmc(a.denominator, b.denominator);
  int f = a.numerator * (d/a.denominator);
  int s = b.numerator * (d/b.denominator);
  Fraction result = {f+s, d};
  return result;
}

Fraction fsub(Fraction a, Fraction b) {
  b.numerator = -b.numerator;
  return fadd(a, b);
}

Fraction fmul(Fraction a, Fraction b) {
  Fraction result = {a.numerator * b.numerator, a.denominator * b.denominator};
  return result;
}

Fraction fdiv(Fraction a, Fraction b) {
  Fraction result = {a.numerator * b.denominator, a.denominator * b.numerator};
  return result;
}

Fraction fsimplify(Fraction a) {
  int m = mdc(a.numerator, a.denominator);
  a.numerator /= m;
  a.denominator /= m;
  if (a.denominator < 0) {
    a.denominator *= -1;
    a.numerator *= -1;
  }
  return a;
}

int mdc(int a, int b) {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int mmc(int a, int b) {
  return (a * b) / mdc(a, b);
}