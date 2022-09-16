/*Задание 1. Решите систему линейных алгебраических уравнений AX = f на основе
LU - разложения матрицы A.
Входные параметры : расширенная матрица системы размерности n (n + 1) такая,
что det(A) != 0.
Выходные параметры : 1) элементы матриц L и U в порядке их вычисления;
2) вектор - столбец значений неизвестных. */

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h> 

using namespace std;

// ввод матрицы
void InputMatrix(double** arrayPtr, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << "A[" << i + 1 << "][" << j + 1 << "] = ";
			cin >> arrayPtr[i][j];
		}
	}
}

// вывод матрицы
void OutputMatrix(double** arrayPtr, int n, int m, const char* Name) {
	cout << "     МАТРИЦА: " << Name << endl;
	if (n == m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << setw(15) << arrayPtr[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}else {	for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (j == m - 1) cout << setw(4) << " | " << setw(4) << arrayPtr[i][j];
				else  cout << setw(15) << arrayPtr[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
}

// очищение памяти
void Delete(double** arrayPtr, int n, int m) {
	for (int i = 0; i < n; i++) {
		delete[]arrayPtr[i];
	}
	delete[]arrayPtr;
}

 // решение Ux=g
double* Reverse_course_Uxg(double** a, int n, int m, double *x) {
	double d;
	for (int k = n - 1; k >= 0; k--) // обратный ход
	{
		d = 0;
		for (int j = k + 1; j <= m - 2; j++)
		{
			double s = a[k][j] * x[j]; // формула (4)
			d = d + s; // формула (4)
		}
		x[k] = (a[k][n] - d); // формула (4)
	}
	cout << endl << "    ВЕКТОР-СТОЛБЕЦ ЗНАЧЕНИЙ x:" << endl;
	for (int l = 0; l < n; l++) {
		cout << setw(20) << x[l] << endl;
	}
	cout << endl;
	return x;
}

// решение Lg=f
double* Reverse_course_Lgf(double** a, int n, int m, double* x) {
	double d;
	for (int k = 0; k <= n-1 ; k++)	{
		d = 0;
		for (int j = k-1; j >=0 ; j--)
		{	double s = a[k][j] * x[j]; 
			d = d + s; 
		}
		x[k] = (a[k][n] - d)/ a[k][k]; 
	}
	cout << endl << "    ВЕКТОР-СТОЛБЕЦ ЗНАЧЕНИЙ g:" << endl;
	for (int l = 0; l < n; l++) {
		cout << setw(20) << x[l] << endl;
	}
	cout << endl;
	return x;
}

// метод  LU-разложения
double* LU_Method(int n, int m) {
	double** matrix = new  double* [n]; // создаем расширенную матрицу
	for (int i = 0; i < n; i++) {
		matrix[i] = new double[m];
	}
	InputMatrix(matrix, n, m);
	cout << endl;
	OutputMatrix(matrix, n, m, "РАСШИРЕННАЯ МАТРИЦА СЛАУ:");

	double** L = new  double* [n];   // создаем матрицу L
	for (int i = 0; i < n; i++) {
		L[i] = new double[n];
	}
	OutputMatrix(L, n, n, "L");

	double** U = new  double* [n];  // создаем матрицу U
	for (int i = 0; i < n; i++) {
		U[i] = new double[n];
	}
	OutputMatrix(U, n, n, "U");
	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl << "       заполнение матриц L и U  "  << endl << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
	int s = 1;
	for (int i = 0; i < n; i++) {   //заполняем матрицы L и U
		// uik= (aik - summ(1; i-1)(lij*ujk))/lii     i<k    верхний правый треугольник
		// u11=1
		// lik = aik - summ(1; k-1)(lij*ujk)      i>=k     нижний левый треугольник
		for (int k = 0; k < n; k++) {
			if (i < k) {
				L[i][k] = 0;
				double sum1 = 0;
				for (int j = 0; j <= i - 1; j++) {
					sum1 += L[i][j] * U[j][k];
				}
				U[i][k] = (matrix[i][k] - sum1) / L[i][i];
			}
			if (i >= k) {
				if (i == k) U[i][k] = 1; else U[i][k] = 0;

				double sum = 0;
				for (int j = 0; j <= k - 1; j++) {
					sum += L[i][j] * U[j][k];
				}
				L[i][k] = matrix[i][k] - sum;
			}
			cout << " ----------------------------------------- " << endl << "       ШАГ " << s << endl << " ----------------------------------------- " << endl;
			OutputMatrix(L, n, n, "L");
			OutputMatrix(U, n, n, "U");
			s++;
		}
	}
	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl << "       вводим замену Ux=g  " << endl << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
	double** Lgf = new  double* [n]; // создаем матрицу Lg=f
	for (int i = 0; i < n; i++) {
		Lgf[i] = new double[m];
	}

	for (int i = 0; i < n; i++) {   // заполняем матрицу Lg=f
		for (int j = 0; j < m; j++) {
			if (j == m - 1) Lgf[i][m - 1] = matrix[i][m - 1];
			else  Lgf[i][j] = L[i][j];
		}
	}
	OutputMatrix(Lgf, n, m, "Lg = f");
	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl << "       решаем Lg=f относительно g  " << endl << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;

	double* g = new  double[n];    // создаем вектор-столбец g
	Reverse_course_Lgf(Lgf, n, m, g); // решаем матрицу Lg=f

	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl << "       обратная замена Ux=g  " << endl << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;

	double** Uxg = new  double* [n];   //создаем матрицу Ux=g
	for (int i = 0; i < n; i++) {
		Uxg[i] = new double[m];
	}

	for (int i = 0; i < n; i++) {     // заполняем матрицу Ux=g
		for (int j = 0; j < m; j++) {
			if (j == m - 1) Uxg[i][m - 1] = g[i];
			else  Uxg[i][j] = U[i][j];
		}
	}
	OutputMatrix(Uxg, n, m, "Ux = g");
	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl << "       решаем Ux=g относительно x  " << endl << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
	double* x = new  double[n]; // создаем вектор-столбец g
	Reverse_course_Uxg(Uxg, n, m, x);  // решаем матрицу Ux=g

	delete[] g;
	Delete(matrix, n, m);
	Delete(L, n, m);
	Delete(U, n, m);
	return x;
}


int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	int m;

	cout << "Укажите размерность расширенной матрицы n x (n+1)" << endl;
	cout << "Введите количество строк n: ";
	cin >> n;
	m = n + 1;
	double* x = new double[n];
	x = LU_Method(n, m);
	delete[] x;
	system("pause");
	return 0;
}
