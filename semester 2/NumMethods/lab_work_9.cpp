#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iomanip>
using namespace std;
double a = 0;
double b = M_PI;
double h = M_PI / 5;

//Функция для подсчета значения f(x)
double f(double x) {
	return ((x+1)*(x+1)+sin(x));
}

//Функция для подсчета значения 4-ой производной
double f4(double x) {
	return (sin(x));
}

//Функция для подсчета значения 3-ей производной
double f3(double x) {
	return (-cos(x));
}

//Функция для подсчета факториала
int fac(int n) {
	int fa=1;
	for (int i = 1; i <= n; i++) {
		fa *= i;
	}
	return fa;
}

//Функция для подсчета значения |W|
double w(double x, double* X, int n) {
	double W = 1;
	for (int i = 0; i < n; i++) {
		W *= (x - X[i]);
	}
	return fabs(W);
}

//Функция для вывода вектора-столбца
void OutputSt(double* a, int n) {
	for (int l = 0; l < n; l++) {
		cout << setw(20) << a[l] << endl;
	}
	cout << endl;
}

//Функция для вывода таблицы
void table(double*X, double * Y, int N){
	double A = a; 
	cout << setw(12) << "X" << setw(12) << "Y" << endl;
	for (int i = 0; i < N; i++) {
		X[i] = a; Y[i] = f(X[i]);
		cout << setw(12) << X[i] << setw(12) << Y[i] << endl;
		a += h;
	}
}

//Функция для подсчета числителя в форме Лагранжа
double chislitel(double* x, int n1, double x1, int i) {
	double pr = 1;
	for (int o = 0; o < n1; o++) {
		if (o != i) pr *= (x1 - x[o]);
	}
	return pr;
}

//Функция для подсчета знаменателя в форме Лагранжа
double znamenatel(double* x, int n1, int i) {
	double pr = 1;
	for (int o = 0; o < n1; o++) {
		if (o != i) pr *= (x[i] - x[o]);
	}
	return pr;
}

//Функция для подсчета значения многочлена Лагранжа в точке
double lagranz(double * x,int n1, double x1) {
	double L = 0; double d;
	for (int i = 0; i < n1; i++) {
		d = f(x[i]) * chislitel(x, n1, x1, i) / znamenatel(x, n1, i);
		L += d;
	}
	return L;
}

double Nuton1(double* x, int n1, double x1) {
	double sum = f(x[0]);
	for (int i = 1; i < n1; ++i) {
		double F = 0;
		for (int j = 0; j <= i; ++j) {
			double den = 1;
			for (int k = 0; k <= i; ++k)
				if (k != j) {
					den *= (x[j] - x[k]);
				}
			F += f(x[j]) / den;
		}

		for (int k = 0; k < i; ++k) {
			F *= (x1 - x[k]);
		}

		sum += F;
	}
	return sum;
}

//Функция для определения точек для Лагранжа
double* Xx(double *X, double *x, double x1, double n1, double N) {
	int i = 0;
	while (X[i] < x1) {
		i++;
	}
	i--;
	if ((i + n1) >= N)i = i - (i + n1 - N);
	for (int h = 0, l = 0; h < n1; h++) {
		x[l] = X[i];
		l++; i++;
	}
	return x;
}

double y1(double x1, double x2) {
	return ((f(x2) - f(x1)) / (x2 - x1));	
}

double y2(double x1, double x2, double x3) {
	return ((y1(x2, x3) - y1(x1, x2)) / (x3 - x1));
}

double y3(double x1, double x2, double x3, double x4) {
	return ((y2(x2, x3, x4) - y2(x1, x2, x3)) / (x4 - x1));
}

double y4(double x1, double x2, double x3, double x4, double x5) {
	return ((y3(x2, x3, x4, x5) - y3(x1, x2, x3, x4)) / (x5 - x1));
}

double y5(double x1, double x2, double x3, double x4, double x5, double x6) {
	return ((y3(x2, x3, x4, x5) - y3(x1, x2, x3, x4)) / (x5 - x1));
}

double Nuton(double* x, int n, double x1) {
	switch (n)
	{
	case 1: return ( f(x[0])+y1(x[0],x[1])*(x1-x[0]) ); break;
	case 2: return ( f(x[0]) + y1(x[0], x[1]) * (x1 - x[0])+ y2(x[0], x[1], x[2])*(x1-x[0])*(x1-x[1])*(x1-x[2])); break;
	case 3: return (f(x[0]) + y1(x[0], x[1]) * (x1 - x[0]) + y2(x[0], x[1], x[2]) * (x1 - x[0]) * (x1 - x[1]) * (x1 - x[2])+ y3(x[0], x[1], x[2], x[3])*(x1-x[0])*(x1-x[1])*(x1-x[2])*(x1-x[4])); break;
	}
}

double MAX(double* x, int n) {
	if (M_PI / 2 >= x[0] && M_PI / 2 <= x[n-1]) return 1;

	if (fabs(f4(x[0])) > fabs(f4(x[n - 1]))) return fabs(f4(x[0]));
	else return fabs(f4(x[n - 1]));
}

double MAX1(double* x, int n) {
	
		if (fabs(f3(x[0])) > fabs(f3(x[n - 1]))) return fabs(f3(x[0]));
		else return fabs(f3(x[n - 1]));
	
}


int main() {
	setlocale(LC_ALL, "rus");
	int N = (b - a) / h + 1;
	double* X = new double[N];
	double* Y = new double[N];
	cout << " Начало отрезка a = " << a << endl;
	cout << " Конец отрезка b = " << b << endl;
	cout << " Шаг h = " << h << endl;
	table(X, Y, N);
	cout << endl;

	
	cout << " Введите X1 = " ;
	double x1, x2, x3; cin >> x1;
	cout << " Введите X2 = " ;
	cin >> x2;
	cout << " Введите X3 = " ;
	cin >> x3;
	cout << endl << "--------------------------------- Многочлен Лагранжа --------------------------------- " << endl;
	int n1;
	cout << " Введите степень многочлена в форме Лагранжа: ";
	cin >> n1;
	n1++;
	double* x = new double[n1];
	cout  << endl;


	double max;

	x = Xx(X, x, x1, n1, N);
	cout <<" L("<<x1<<") = " << lagranz(x, n1, x1)<< endl;
	cout << " Погрешность R1 = " << fabs(f(x1) - lagranz(x, n1, x1)) << endl;
	max = MAX(x, n1);
	cout << " Оценка погрешности R1 <= " << max*w(x1, x, n1)/fac(n1) << endl;
	cout << endl;
	x = Xx(X, x, x2, n1, N);
	cout << " L(" << x2 << ") = " << lagranz(x, n1, x2)<< endl;
	cout << " Погрешность R2 = " << fabs(f(x2)- lagranz(x, n1, x2)) << endl;
	max = MAX(x, n1);
	cout << " Оценка погрешности R2 <= " << max * w(x2, x, n1) / fac(n1 ) << endl;
	cout << endl;
	x = Xx(X, x, x3, n1, N);
	cout << " L(" << x3 << ") = " << lagranz(x, n1, x3)<< endl;
	max = MAX(x, n1);
	cout << " Погрешность R3 = " << fabs(f(x3) - lagranz(x, n1, x3)) << endl;
	cout << " Оценка погрешности R3 <= " << max * w(x2, x, n1) / fac(n1 ) << endl;


	cout << endl << "--------------------------------- Многочлен Ньютона --------------------------------- " << endl;
	int n2;
	cout << " Введите степень многочлена в форме Ньютона: ";
	cin >> n2;
	n2++;

	double* xx = new double[n2];
	 max = f3(X[0]);

	cout << endl;
	xx = Xx(X, xx, x1, n2, N);

	cout << " N"<<n2<<"(" << x1 << ") = " << Nuton1(xx, n2, x1) << endl;
	cout << " Погрешность R1 = " << fabs(f(x1) - Nuton1(xx, n2, x1)) << endl;
	max = MAX1(xx, n2);
	cout << " Оценка погрешности R1 <= " << max * w(x1, x, n2) / fac(n2 ) << endl;
	cout << endl;

	xx = Xx(X, xx, x2, n2 + 1, N);
	cout << " N" << n2 << "(" << x2 << ") = " << Nuton1(xx, n2, x2) << endl;
	cout << " Погрешность R2 = " << fabs(f(x2) - Nuton1(xx, n2, x2)) << endl;
	max = MAX1(xx, n2);
	cout << " Оценка погрешности R2 <= " << max * w(x2, x, n2) / fac(n2) << endl;
	cout << endl;

	xx = Xx(X, xx, x3, n2 + 1, N);
	cout << " N" << n2 << "(" << x3 << ") = " << Nuton1(xx, n2, x3) << endl;
	cout << " Погрешность R3 = " << fabs(f(x3) - Nuton1(xx, n2, x3)) << endl;
	max = MAX1(xx, n2);
	cout << " Оценка погрешности R3 <= " << max * w(x2, x, n2) / fac(n2) << endl;

	delete[]xx;
	delete[]x;
	delete[]X;
	delete[]Y;
	return 0;
}