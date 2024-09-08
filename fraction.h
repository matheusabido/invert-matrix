#ifndef FRACTION_H
#define FRACTION_H

typedef struct {
    int numerator;
    int denominator;
} Fraction;

Fraction fadd(Fraction a, Fraction b);
Fraction fsub(Fraction a, Fraction b);
Fraction fmul(Fraction a, Fraction b);
Fraction fdiv(Fraction a, Fraction b);
Fraction fsimplify(Fraction a);
int mmc(int a, int b);
int mdc(int a, int b);

#endif