/*Задание. 1) Вычислить определитель матрицы, используя её LU - разложение.

Входные параметры : квадратная матрица.
Выходные параметры : 1) матрицы L и U;
                     2) определитель заданной матрицы.

2 Вычислить обратную матрицу, используя её LU - разложение и метод Жордана-Гаусса.

Входные параметры : квадратная матрица.
Выходные параметры : 1) для LU - разложения: матрицы L и U, вектора Y1, Y2, …, Yn,
                      обратная матрица;
					  2) для метода Жордана-Гаусса: последовательность матриц
                     в процессе преобразований на каждом шаге метода.*/

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h> 

using namespace std;

// ввод матрицы с клавиатуры
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
	cout << "     матрица: " << Name << endl;
	if (n == m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << setw(15) << arrayPtr[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (j == m - 1) cout << setw(4) << " | " << setw(4) << arrayPtr[i][j];
				else  cout << setw(15) << arrayPtr[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
}

// вывод матрицы
void OutputMatrix_2(double** arrayPtr, int n, int m) {
	if (m == 2 * n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (j == m / 2) cout << setw(3) << " | " << setw(3) << arrayPtr[i][j];
				else cout << setw(10) << arrayPtr[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
	else for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(10) << arrayPtr[i][j];
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

// решение LY=e
double* Reverse_course_Lye(double** a, int n, int m, double* x) {
	double d;
	for (int k = 0; k <= n - 1; k++) {	d = 0;
		for (int j = k - 1; j >= 0; j--){
			double s = a[k][j] * x[j];
			d = d + s;
		}
		x[k] = (a[k][n] - d) / a[k][k];
	}
	cout << endl << "    ВЕКТОР-СТОЛБЕЦ ЗНАЧЕНИЙ Y:" << endl;
	for (int l = 0; l < n; l++) {
		cout << setw(20) << x[l] << endl;
	}
	cout << endl;
	return x;
}

// решение Ux=Y
double* Reverse_course_Uxy(double** a, int n, int m, double* x) {
	double d;
	for (int k = n - 1; k >= 0; k--) // обратный ход хода Гаусса
	{	d = 0;
		for (int j = k + 1; j <= m - 2; j++)
		{	double s = a[k][j] * x[j]; 
			d = d + s; 
		}
		x[k] = (a[k][n] - d); 
	}
	cout << endl;
	return x;
}

// заполняем матрицу LY=e
double** LYe(double** L, double ** e, int n, int j, double ** lue) {
	for (int i = 0; i < n; i++) {  // заполняем  матрицу lue
		for (int k = 0; k < n + 1; k++) {
			if (k == n) lue[i][n] = e[i][j];
			else  lue[i][k] = L[i][k];
		}
	}
	return lue;
}

// заполняем матрицу UX=Y
double** Uxy (double** U, double* y, int n, int j, double** uxy) {
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n + 1; k++) {
			if (k == n) uxy[i][n] = y[i];
			else  uxy[i][k] = U[i][k];
		}
	}
	return uxy;
}

// заполняем обратную матрицу 
double** reverse_matrix(double ** REVERSE_MATRIX, double * x, int n, int h) {
	for (int i = 0; i < n; i++) {
		REVERSE_MATRIX[i][h] = x[i];
	}
	OutputMatrix(REVERSE_MATRIX, n, n, "Обратная матрица");
	return REVERSE_MATRIX;
}

// нахождение обратной матрицы с помощью LU-разложения LUX=E
double** reverse_matrix_LU(double** L, double** U, int n) {

	double** REVERSE_MATRIX = new  double* [n]; // создаем обратную матрицу 
	for (int i = 0; i < n; i++) {
		REVERSE_MATRIX[i] = new double[n];
	}

	double** Lye = new  double* [n]; // создаем  матрицу LY=e
	for (int i = 0; i < n; i++) {
		Lye[i] = new double[n+1];
	}

	double** UxY = new  double* [n]; // создаем  матрицу UX=Y
	for (int i = 0; i < n; i++) {
		UxY[i] = new double[n + 1];
	}

	double** e = new  double* [n];  // создаем единичную матрицу e
	for (int i = 0; i < n; i++) {
		e[i] = new double[n];
	}

	//заполняем единичную матрицу e
	for (int i = 0; i < n; i++) {  
		for (int k = 0; k < n; k++) {
			if (k == i) e[i][k] = 1;
			else  e[i][k] = 0;
		}
	}

	double* y = new double[n]; // создаем вектор-столбец значений y
	double* x = new double[n]; // создаем вектор-столбец значений x
	for (int h = 0; h < n; h++) { 
		cout << " ----------------------------------  ШАГ " << h+1  << "  ----------------------------------- " << endl;
		Lye= LYe(L, e, n, h, Lye);    // заполняем матрицу LY=e
		y = Reverse_course_Lye(Lye, n, n + 1, y); // решение уравнения LY=e
		UxY = Uxy(U, y, n, h, UxY);   // заполняем матрицу UX=Y
		x = Reverse_course_Uxy(UxY, n, n + 1, x); // решение уравнения UX=Y
		REVERSE_MATRIX = reverse_matrix(REVERSE_MATRIX, x, n, h); // заполняем обратную матрицу UX=Y
	}
	cout << " ------------------------------------------------------------------------------ " << endl;
	OutputMatrix(REVERSE_MATRIX, n, n, "КОНЕЧНАЯ ОБРАТНАЯ МАТРИЦА");
	Delete(e, n, n);
	Delete(Lye, n, n);
	Delete(UxY, n, n);
	delete[] x;
	delete[] y;
	return REVERSE_MATRIX;
}

// метод  LU-разложения
double LU_Method(int n, double** matrix) {
	double det = 1;  
	double** L = new  double* [n];   // создаем матрицу L
	for (int i = 0; i < n; i++) {
		L[i] = new double[n];
	}

	double** U = new  double* [n];  // создаем матрицу U
	for (int i = 0; i < n; i++) {
		U[i] = new double[n];
	}

	//заполняем матрицы L и U
	for (int i = 0; i < n; i++) {   
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
		}
	}
	OutputMatrix(L, n, n, "L");
	OutputMatrix(U, n, n, "U");
	// считаем определитель матрицы
	for (int i = 0; i < n; i++) {  
		det *= L[i][i];
	}
	cout << "   ОПРЕДЕЛИТЕЛЬ МАТРИЦЫ: " << det << endl;
	cout << " ============================================================================== " << endl
		<< "                                  задание 2(1) " << endl << " ============================================================================== " << endl;
	OutputMatrix(L, n, n, "L");
	OutputMatrix(U, n, n, "U");
	reverse_matrix_LU(L, U, n); // считаем обратную матрицу

	Delete(L, n, n);
	Delete(U, n, n);
	return det;
}

// заполняем  матрицу A|E 
double** Matrix(double** a1, int n) {
	double** matrix = new  double* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new double[2 * n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n; j++)
			if (j < n) { matrix[i][j] = a1[i][j]; }
			else {
				if (i == j - n) matrix[i][j] = 1; else  matrix[i][j] = 0;
			};
	}
	OutputMatrix_2(matrix, n, 2 * n);
	return matrix;
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
				if (r != i) A[r][b] = A[r][b] - N * A[i][b];
			}
		}
		OutputMatrix_2(A, n, m);
	}
	return A;
}

// заполняем обратную матрицу 
double** Gauss_Jordan_matrix_back(int n, double** A) {

	double** matrix = new  double* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new double[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = n; j < 2 * n; j++)
			matrix[i][j - n] = A[i][j];
	}
	OutputMatrix_2(matrix, n, n);
	return matrix;
}

// нахождение обратной матрицы с помощью методa Жордана - Гаусса
double ** reverse_matrix_Gauss_Jordan(int n, double** matrix) {
	cout << "    МАТРИЦА (A|E)" << endl;
	matrix = Matrix(matrix, n);
	cout << "------------------------------------------------------------------------------" << endl << "    ЭТАПЫ ПРЕОБРАЗОВАНИЯ МАТРИЦЫ  (A|E) ПО МЕТОДУ ЖОРДАНА_ГАУССА:" << endl;
	matrix = Gauss_Jordan_method(n, 2 * n, matrix);
	cout <<endl << "------------------------------------------------------------------------------" << endl << "    ОБРАТНАЯ МАТРИЦА " << endl;
	Gauss_Jordan_matrix_back(n, matrix);
	return matrix;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	cout << "Укажите размерность квадратной матрицы n x n " << endl;
	cout << "Введите количество строк n: ";
	cin >> n;

	double** matrix = new  double* [n]; // создаем  матрицу
	for (int i = 0; i < n; i++) {
		matrix[i] = new double[n];
	}
	InputMatrix(matrix, n, n);
	cout << endl;
	cout << " ============================================================================== " << endl;
	OutputMatrix(matrix, n, n, "исходная");
	cout << " ============================================================================== " << endl
		<< "                                  задание 1 " << endl << " ============================================================================== " << endl;
	LU_Method(n, matrix);
	 cout << " ============================================================================== " << endl
		 << "                                  задание 2(2) " << endl << " ============================================================================== " << endl;
	reverse_matrix_Gauss_Jordan(n, matrix);
	cout << " ============================================================================== " << endl;
	Delete(matrix, n, n);
	system("pause");
	return 0;
}
