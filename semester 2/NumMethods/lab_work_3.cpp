#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iomanip>
using namespace std;

double f(double x) {
	return x * exp(0.8 * x);
}

double F(double x) {
	return  exp(0.8 * x) * (0.8 * x - 1) / 0.64;
}

// метод прямоугольникoв
// S= h*summ(f(xi))
// 0 n-1 левые
// 1 n правые
//  0 n-1 S= h*summ(f(xi+h/2)) центральные
double Rectangle_method(double a, double h, int n) {
	double integral = 0;
	for (int i = 0; i < n; i++) {
		integral += f(a);
		a += h;
	}
	integral = integral* h;
	return integral;
}


// метод трапеций
// S = h/2 *(f(x0)+2f(x1)+2f(x2)+...+ 2f(xn-1)+f(xn)) 
double Trapezoid_method(double a, double b, double h, int n) {
	double integral = 0;
	integral = integral + f(a) + f(b);
	for (int i = 1; i < n - 1; i++) {
		a += h;
		integral =integral + 2 * f(a);
	}
	integral = h * integral / 2;
	return integral;
}


// метод парабол
// S = h / 3 * (f(x0) + 4f(x1) + 2f(x2) + 4f(x3)+ ...+ 2f(2n - 2) + 4f(2n - 1) + f(xn))
double  Parabola_method(double a, double b, double h, int n) {
	double integral = 0;
	integral = integral + f(a) + f(b);
	for (int i = 1; i < n - 1; i++) {
		a += h;
		if (i % 2 == 0) integral = integral + 4 * f(a);
		else integral = integral + 2 * f(a);
	}
	integral = h * integral / 3;
	return integral;
}

// по формуле Ньютона-Лейбница
double formula(double a, double b) {
	return F(b) - F(a);
}

//S= int(-1;1)fxdx = summ(ck*fxk) +R
//  если граница не -1 1. то t= (b-a)x/2 +(b+a)/2
//S =(b-a)/2 * int(-1;1)f((b-a)x/2 +(b+a)/2)dx

double Gauss_1(double a, double b) {
	double rez;
	rez = 2 * f((b+a)/2);
	return rez;
}

double Gauss_2(double a, double b) {
	double rez=0;
	rez += f(-0.5773503 * (b - a) / 2 + (b + a) / 2);
	rez += f(0.5773503 * (b - a) / 2 + (b + a) / 2);
	return rez;
}

double Gauss_3(double a, double b) {
	double rez=0;
	rez += 0.5555556*f(-0.7745967 * (b - a) / 2 + (b + a) / 2);
	rez += 0.8888889*f(0* (b - a) / 2 + (b + a) / 2);
	rez += 0.5555556 * f(0.7745967 * (b - a) / 2 + (b + a) / 2);
	return rez;
}

double Gauss_4(double a, double b) {
	double rez=0;
	rez += 0.3478548 *( f(-0.8611363 * (b - a) / 2 + (b + a) / 2) + f(0.8611363 * (b - a) / 2 + (b + a) / 2));
	rez += 0.6521451 *( f(-0.3399810 * (b - a) / 2 + (b + a) / 2) + f(0.3399810 * (b - a) / 2 + (b + a) / 2));
	return rez;
}

double Gauss_5(double a, double b) {
	double rez = 0;
	rez += 0.4786287 * (f(-0.9061798 * (b - a) / 2 + (b + a) / 2) + f(0.9061798 * (b - a) / 2 + (b + a) / 2));
	rez += 0.2369269 * (f(-0.5384693 * (b - a) / 2 + (b + a) / 2) + f(0.5384693 * (b - a) / 2 + (b + a) / 2));
	rez += 0.5688888 * f( (b + a) / 2);
	return rez;
}

double Gauss_6(double a, double b) {
	double rez = 0;
	rez += 0.1713245 * (f(-0.9324700 * (b - a) / 2 + (b + a) / 2) + f(0.9324700 * (b - a) / 2 + (b + a) / 2));
	rez += 0.3607616 * (f(-0.6612094 * (b - a) / 2 + (b + a) / 2) + f(0.6612094 * (b - a) / 2 + (b + a) / 2));
	rez += 0.4679140 * (f(-0.2386142 * (b - a) / 2 + (b + a) / 2) + f(0.2386142 * (b - a) / 2 + (b + a) / 2));
	return rez;
}


// метод Гаусса
double Gauss_method(int p, double a, double b) {
	double integral = 1;
	integral *= (b - a) / 2;
	switch (p) {
	case 1: integral *= Gauss_1(a, b); break;
	case 2: integral *= Gauss_2(a, b); break;
	case 3: integral *= Gauss_3(a, b); break;
	case 4: integral *= Gauss_4(a, b); break;
	case 5: integral *= Gauss_5(a, b); break;
	case 6: integral *= Gauss_6(a, b); break;
	}
	return integral;
}


int main() {
	setlocale(LC_ALL, "rus");
	double a, b, n, h;
	cout << " Введите начало промежутка: ";
	cin >> a;
	cout << " Введите конец промежутка: ";
	cin >> b;
	cout << " Введите количество отрезков:  ";
	cin >> n;
	h = (b - a) / n;
	cout << " Mетод левыx прямоугольникoв " <<setw(15) << Rectangle_method(a, h, n) << endl;            
	cout << " Mетод правых прямоугольникoв " << setw(14)<< Rectangle_method(a+h, h, n) << endl;            
	cout << " Mетод центральных прямоугольникoв " << setw(9) << Rectangle_method((a + h / 2), h, n) << endl;    
	cout << " Mетод трапеций " << setw(28) << Trapezoid_method(a,b, h, n) << endl;           
	cout << " Mетод парабол " << setw(29) << Parabola_method(a, b, h / 2, 2 * n) << endl;
	cout << " Формула Ньютона-Лейбница" << setw(19) << formula( a, b) << endl;
	int p; cout << " Введите количество точек для метода Гаусса (от 1 до 6): "; cin >> p;
	cout << " Метод Гаусса" << setw(31) << Gauss_method(p, a, b) << endl;

	return 0;
}