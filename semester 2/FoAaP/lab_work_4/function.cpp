#include <math.h>
#include <iostream>
#include "Header.h"

Fraction::Fraction(double num, double denum) {
	if ( num- int(num) != 0)
		throw "Числитель не целое число!!!";
	if (denum <= 0 ||denum - int(denum) != 0)
		throw "Знаменатель не натуральное число!!!";
	numerator = num; denumerator = denum; 
	reduce();
}

double Fraction:: getNum() {
	return numerator;
}

double Fraction :: getDenum() {
	return denumerator;
}

int Fraction::nod(int a, int b) {
	return (int(b) == 0) ? (int(a) > 0 ? int(a) : -int(a)) : nod(int(b), int(a) % int(b));
}

void Fraction :: reduce() {
	int nod = Fraction::nod(numerator, denumerator);
	numerator /= nod;
	denumerator /= nod;
}


std::ostream& operator<< (std::ostream& out, const Fraction& fraction) {
	if (fraction.numerator == 0) out << fraction.numerator;
	else {
		if (fraction.numerator == fraction.denumerator) out << "  1  ";
		else {
			if (fraction.numerator == -1* fraction.denumerator) out << "  -1  ";
			else {

			if (fabs(fraction.numerator) > fraction.denumerator) {
				if (int(fraction.numerator) % int(fraction.denumerator) == 0) out << int(fraction.numerator) / int(fraction.denumerator)<< "  ";
				else {
					int c = int(fraction.numerator / fraction.denumerator);
					out << c << "(" << fabs(fraction.numerator) - fabs(c) * fraction.denumerator << " / " << fraction.denumerator << ")  ";
				}
			}
			else
				out << fraction.numerator << " / " << fraction.denumerator << "   ";
		   }
		}
	}
	return out;
}

std::istream& operator>> (std::istream& in, Fraction& fraction) {
	in >> fraction.numerator;
	in >> fraction.denumerator;
	if (fraction.numerator - int(fraction.numerator) != 0)
		throw "Числитель не целое число!!!";
	if (fraction.denumerator <= 0 || fraction.denumerator - int(fraction.denumerator) != 0)
		throw "Знаменатель не натуральное число!!!";
	return in;
}

 Fraction operator-(const Fraction& f1, const Fraction& f2) {
	 return Fraction(f1.numerator * f2.denumerator - f2.numerator * f1.denumerator, f1.denumerator * f2.denumerator);
}

Fraction operator*(const Fraction& f1, const Fraction& f2) {
	return Fraction(f1.numerator * f2.numerator, f1.denumerator * f2.denumerator);
}
