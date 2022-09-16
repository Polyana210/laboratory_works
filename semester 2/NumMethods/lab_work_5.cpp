/*Решите систему линейных алгебраических уравнений AX = f методом
Жордана-Гаусса.
Входные параметры: расширенная матрица системы размерности n  (n + 1) такая,
что det(A)  0.
Выходные параметры:1) матрицы на каждом этапе вычислений;
                   2) вектор-столбец значений неизвестных. */

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
void OutputMatrix(double** arrayPtr, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ( j== m-1) cout << setw(4)<<" | " << setw(4) << arrayPtr[i][j];
			else  cout << setw(12) << arrayPtr[i][j];
		}
		cout << endl;
	}
	cout << endl;
}


// очищение памяти
void Delete(double** arrayPtr, int n, int m) {
	for (int i = 0; i < n; i++) {
		delete[]arrayPtr[i];
	}
	delete[]arrayPtr;
}

// метод Жордана - Гаусса
double** Gauss_Jordan_method(int n, int m, double** A) {

	for (int i = 0; i < n; i++) { 
		double u = A[i][i];
		for (int g = 0; g < m; g++) {
			A[i][g] = A[i][g] / u;  
		}

		for (int r = 0; r < n; r++) {
			double N = A[r][i];
			for (int b = 0; b < m; b++) {
				if (r!= i) A[r][b] = A[r][b] - N * A[i][b];
			}
		}
		OutputMatrix(A, n, m);
	}
	return A;
}

// заполнение вектора- столбца неизвестных 
double * Gauss_Jordan_korni(int n, int m, double** A) {
	double* x = new  double[n];
	for (int k = 0; k < n; k++) 
		x[k] = A[k][m-1];
	
	for (int l = 0; l < n; l++) {
		cout << setw(20)<< x[l] << endl;
	}
	cout << endl;
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

	double** matrix = new  double* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new double[m];
	}
	InputMatrix(matrix, n, m);

	cout << endl << endl << "       ВВЕДЕННАЯ РАСШИРЕННАЯ МАТРИЦА СЛАУ:"   << endl;
	OutputMatrix(matrix, n, m);
	cout << endl << endl << "       ЭТАПЫ ПРЕОБРАЗОВАНИЯ МАТРИЦЫ ПО МЕТОДУ ЖОРДАНА_ГАУССА:" <<endl;
	Gauss_Jordan_method(n, m, matrix);
	cout << endl  << "       ВЕКТОР-СТОЛБЕЦ ЗНАЧЕНИЙ НЕИЗВЕСТНЫХ:"  << endl;
	Gauss_Jordan_korni(n, m, matrix);
	Delete(matrix, n, m);


	system("pause");
	return 0;
}
