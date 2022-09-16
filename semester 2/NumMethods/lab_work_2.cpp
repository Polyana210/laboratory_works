#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

//Функция для подсчета значения f(x)
double f(double x) {
	return (x*exp(x)+x*x);
}

//Функция для подсчета значения производной f*(x)
double f1(double x) {
	return (exp(x)+x*exp(x)+2*x);
}

//Функция для подсчета значения второй производной f**(x)
double l(double x) {
	return (2*exp(x)+x*exp(x)+2);
}

//Функция для подсчета значения левой производной f*(x)
//y1= f(X[i]) - f(X[i-1])) / h
void left(double *X, double h, int n) {
	cout << "Left" << setw(10) << "-" << setw(10);
	for (int i = 1; i < n; i++) {
		cout << setw(10) << (f(X[i]) - f(X[i-1])) / h << setw(10);
	}
}

//Функция для подсчета значения правой производной f*(x)
// (f(X[i + 1]) - f(X[i])) / h
void right(double *X, double h, int n) {
	cout << "Right" << setw(10);
	for (int i = 0; i < n - 1; i++) {
		cout << setw(10) << ((f(X[i + 1]) - f(X[i])) / h) << setw(10);
	} cout << "-" << setw(10);
}

//Функция для подсчета значения центральной производной f*(x)
// f(X[i + 1]) - f(X[i - 1])) / (2 * h)
void center(double* X, double h, int n) {
	cout << "Center" << setw(10) << "-" << setw(10);
	for (int i = 1; i < n - 1; i++) {
		cout << setw(10) << (f(X[i + 1]) - f(X[i - 1])) / (2 * h) << setw(10);
	}cout << "-" << setw(10);
}

//Функция для подсчета приблизительного значения второй производной f**(x)
// f(X[i + 1]) + f(X[i - 1]) - 2 * f(X[i])) / (h * h)
void approx_f2(double* X, double h, int n) {
	cout << "ap. f**(x)" << setw(10) << "-" << setw(10);
	for (int i = 1; i < n - 1; i++) {
		cout << setw(10) << (f(X[i + 1]) + f(X[i - 1]) - 2 * f(X[i])) / (h * h) << setw(10);
	}cout << "-" << setw(10);
}

//Функция для вывода значений i
void Vivod_i(double* X, double h, int n, int a) {
	cout << setw(10) << "i" << setw(10);
	for (int i = 0; i < n; i++) {
		cout << i << setw(10);
	}
	cout << endl;
}

//Функция для вывода значений Хi
void Vivod_Xi(double* X, double h, int n, int a) {
	X[0] = a;
	cout << "Xi" << setw(10) << X[0] << setw(10);
	for (int i = 1; i < n; i++) {
		X[i] = X[i - 1] + h;
		cout << X[i] << setw(10);
	}
}

//Функция для вывода значений f(x)
void Vivod_f(double* X, double h, int n) {
	cout << endl;
	cout << "f(x)" << setw(10);
	for (int i = 0; i < n; i++) {
		cout << setw(10) << f(X[i]) << setw(10);
	}cout << setw(10);
}

//Функция для вывода значений f*(x)
void Vivod_f1(double* X, double h, int n) {

	cout << endl;
	cout << "f*(x)" << setw(10);
	for (int i = 0; i < n; i++) {
		cout << setw(10) << f1(X[i]) << setw(10);
	}cout << setw(10);
}

//Функция для вывода значений f**(x)
void Vivod_f2(double* X, double h, int n) {	
	cout << "f**(x)" << setw(10);
	for (int i = 0; i < n; i++) {
		cout << setw(10) << l(X[i]) << setw(10);
	}cout << setw(10);
	cout << endl;
}



int main(){
	setlocale(LC_ALL, "rus");
	   int a, b, h;int n;
	   cout << "Введите границы отрезка:" << endl;
	   cout << "a = "; cin >> a;
	   cout << "b = "; cin >> b; cout << endl;
	   cout << "Введите шаг:" << endl;
	   cout << "h = "; cin >> h; cout << endl;
	
	   n= (b-a)/h+1;
	  
	   cout << endl;
	   double *X = new double[n];
	   Vivod_i(X, h, n, a);
	   Vivod_Xi(X, h, n, a);
	   Vivod_f(X, h, n); cout << endl;
	   right(X, h, n); cout << endl;
	   left(X, h, n);  cout << endl;
	   center(X, h, n);
	   Vivod_f1(X, h, n);  cout << endl << endl;
	   approx_f2(X, h, n); cout << endl;
	   Vivod_f2(X, h, n);
	   delete[]X;
		system("pause");
}

