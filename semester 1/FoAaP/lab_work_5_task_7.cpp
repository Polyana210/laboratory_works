#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	long double a, b, x, x2, dX;

	cout << "Введите начальное значение X1: ";
	cin >> x;

	cout << "Введите конечное значение X2: ";
	cin >> x2;

	cout << "Введите шаг значения dX: ";
	cin >> dX;

	cout << "Введите a: ";
	cin >> a;

	cout << "Введите b: ";
	cin >> b;

	cout << "             " << "X" << "             "  << "Y1" << "             "  << "Y2" << "             Y3" << endl;


	for (x; x <= x2; x += dX) {

		long double y1, y2, y3 = 0;

		if (x <= 0) {
			y1 = sin(a/(1+pow(x, 2)));
		}
		else {
			y1 = log(x+1)+sin(a) ;
		}

		if (x <= 1) {
			y2 = fabs(pow(a,x) - pow(x,2));
		}
		else {
			y2 = a+ cos(M_PI *x/2);
		}

		if (x < 1) {
			y3 = a*x - b*pow(x,2);
		}
		else {
			y3 = (a-b)/log(M_E +sqrt(x*x -1));
		}




		cout << "             " << x << "             " << y1 << "             " << y2 << "             " << y3 << endl;

	}

	system("pause");
	return 0;
}