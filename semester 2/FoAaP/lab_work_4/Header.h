#pragma once
#ifndef HEADER_H
#define HEADER_H
#include <iostream>
 
class Fraction {
    double numerator;
    double denumerator;
public:
    Fraction(double num=0, double denum=1);
    double getNum();
    double getDenum();
    static int nod(int a, int b);
    void reduce();
    friend std::ostream& operator<< (std::ostream& out, const Fraction& fraction);
    friend std::istream& operator>> (std::istream& in, Fraction& fraction);
    friend Fraction operator-(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
};

#endif

