#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

//Функция для подсчета значения f(x)
double f(double x){
	return (x*log10(x)-1.2);
}

//Функция для вывода таблицы
void table(double x1, double x2, double dx) {
	if (x1 <= 0 || x2 < x1 || dx<=0) cout << "Некорректные данные ";
	else {
		cout << "         " << "X" << "             " << "Y1" << endl;
		for (x1; x1 <= x2; x1 += dx) {
			cout << "         " << x1 << "             " << f(x1) << endl;
		}
	}
}


//Функция для проверки существования корня на данном отрезке

bool check_1 (double a, double b) {
	if (f(a) * f(b) < 0) return true;
	else return false;
}

//Функция для поиска корня методом Дихотомии
double Dihotomiya(double a, double b, double eps) {
	double c; int iter = 0;
	do {
		//выбрать середину отрезка
		c = (a + b) / 2;
		
		if (f(c) == 0) return c;
		if (f(a) * f(c) < 0) { b = c; }
		else a = c;
		iter++;
	} while ((b-a)/2 > eps);
	cout << "Подсчет за " << iter << " итераций." << endl << "Корень: ";
	return c;
}

//Функция для подсчета значения производной f*(x)
double f1(double x) {
	return (log10(x)+1/log(10));
}

//Функция для подсчета значения второй производной f**(x)
double f2(double x) {
	return (1/(x*log(10)));
}

//Функция для проверки f(x)f**(x)>0
bool check_3(double x) {
	if (f(x)*f2(x)>0) return true;
	else return false;
}

//Функция для поиска корня методом касательных
double Met_tangent(double eps, double x0) {
	int iter = 0;
	do {
		//Xk+1= Xk - f(Xk)/f*(Xk)
		x0 = x0 - f(x0) / f1(x0);
		iter++;
	} while (fabs(f(x0)) > eps);
	cout << "Подсчет за " << iter << " итераций." << endl << "Корень: ";
	return x0;
}

//Функция для поиска корня методом секущих
double Met_secant(double eps, double x0, double x1) {
	int iter = 0; double x=x0; double y;
	do {
		// xk+1=xk - f(Xk)*(xk-x(k-1))/f(xk)-f(xk-1)
		y = x;
		x = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
		x0 = x1 ;
		x1 = x;
		iter++;
	} while (fabs(f(x0)) > eps);
	cout << "Подсчет за " << iter << " итераций." << endl << "Корень: ";
	return x0;

}

//Функция для поиска корня методом хорд
double Met_chord(double eps, double x0, double x1) {
	int iter = 0;
	do {
		// xk + 1 = xk - f(Xk) * (xk - x0) / f(xk) - f(x0)
		x1 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
		iter++;
	} while (fabs(f(x0)) > eps);
	cout << "Подсчет за " << iter << " итераций." << endl << "Корень: ";
	return x1;

}



//Функция для подсчета значения fi(x)
double fi(double x) {
	return (x - 0.2 * (pow(x,3)-3*x*x+6*x-5));
}

//Функция для проверки |fi*(x)|<1
bool check_2(double x) {
	if (fabs(1-0.2*(x*x-2*x+2) < 1)) return true;
	else return false;
}

//Функция для поиска корня методом Простой итерации
double MPI(double eps, double x0) {
	double x1; int iter = 0;
	do {
		x1 = x0;
		x0 = fi(x0);
		iter++;
	} while (fabs(x1 - x0) > eps);
	cout << "Подсчет за " << iter << " итераций." << endl << "Корень: ";
	return x0;
}


int main()
{  
	setlocale(LC_ALL, "rus");
	double A; double B;  double x0; double x1; double  x2, x3, x4, dx;
	double ep = 0.001; //Точность вычислений.
	cout << "Решение уравнения хlog(x) = 1.2 " << endl << endl;
	cout << "1(2) Отделение корней таблицей  " << endl << endl;
	cout << "Введите начальное значение X1: ";
	cin >> x1;
	cout << "Введите конечное значение X2: ";
	cin >> x3;
	cout << "Введите шаг значения dX: ";
	cin >> dx;
	table(x1, x3, dx);
	cout << endl;
	cout << "1(3) Уточнение корня  " << endl << endl;
	cout << "МЕТОД ДИХОТОМИИ" << endl;
	cout << "a="; cin >> A; 
	cout << "b="; cin >> B;
	if (check_1(A, B)) {
		cout << "Корень отделен верно" << endl;
		cout << Dihotomiya(A, B, ep) << endl << endl;
	} else cout << "Корень отделен неверно" << endl << endl;


	

	cout << "МЕТОД НЬЮТОНА" << endl;
	cout << "Введите начальное приближение x0 = ";
	cin >> x2;
	if (check_3(x2)) {
		cout << "Корень отделен верно" << endl;
		cout << Met_tangent(ep, x2) << endl << endl;
	} else cout << "Корень отделен неверно" << endl << endl;
	

	cout << "МЕТОД СЕКУЩИХ" << endl;
	cout << "Начальное приближение x0 = "<<x2<<endl;
	cout << "Введите начальное приближение x1 = ";
	cin >> x4;

	if (check_3(x2) && check_1(x2,x4)){
		cout << "Корень отделен верно" << endl;
		cout << Met_secant(ep, x2, x4) << endl << endl;
	} else cout << "Корень отделен неверно" << endl << endl;

	cout << "МЕТОД ХОРД"  << endl;
	cout << "Начальное приближение x0 = " << x2 << endl;
	cout << "Начальное приближение x1 = " << x4 << endl;
	if (check_3(x2) && check_1(x2, x4)) {
		cout << "Корень отделен верно" << endl;
		cout << Met_secant(ep, x2, x4) << endl << endl;
	} else cout << "Корень отделен неверно" << endl << endl;

	cout << "Решение уравнения x^3-3x^2+6x-5=0 " << endl << endl;
	cout << "2(3) Уточнение корня  " << endl << endl;
	cout << "МЕТОД ПРОСТОЙ ИТЕРАЦИИ" << endl;
    cout << "Введите начальное приближение x0 = ";
    cin >> x0;
    if (check_2(x0)) {
	 cout << "Корень отделен верно" << endl;
	 cout << MPI(ep, x0) << endl << endl;
    } else cout << "Корень отделен неверно" << endl << endl;

	system("pause");
	return 0;
}