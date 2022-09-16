#include <iostream>
#include <iomanip>
using namespace std;
double eps = 0.001;
int ITER = 0;

// ввод расширенной матрицы
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
	if (m == n + 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (j == m - 1) cout << setw(4) << " | " << setw(4) << arrayPtr[i][j];
				else  cout << setw(12) << arrayPtr[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
	if(m==n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				  cout << setw(12) << arrayPtr[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
}

// вывод вектора-столбца
void OutputSt(double* a, int n) {
	for (int l = 0; l < n ; l++) {
		cout << setw(20) << a[l] << endl;
	}
	cout << endl;
}

// очистка памяти
void Delete(double** arrayPtr, int n, int m) {
	for (int i = 0; i < n; i++) {
		delete[]arrayPtr[i];
	}
	delete[]arrayPtr;
}

// проверка диагонального преобладания
// |aii|> summ(j=1; n(j!=i))(aij)
bool check_diag_preobl(double** a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j=0; j < n; j++) {
			if(i!=j)
			if (fabs(a[i][j]) >= fabs(a[i][i])) return 0;
		}
	}
	return 1;
}

// преобразование матрицы g
double* BX1(double** a, int n, double* g) {
	for (int i = 0; i < n; i++) {
		g[i] /= a[i][i];
	}
	cout << " ~ ВЕКТОР-СТОЛБЕЦ g ~ " << endl;
	OutputSt(g, n);
	return g;
}

// преобразование матрицы B
double** BX(double** a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) a[i][j] /= -a[i][i];
		}
		a[i][i] = 0;
	}
	cout << " ~ МАТРИЦА В ~ " << endl;
	OutputMatrix(a, n, n);
	return a;
}

// xi = - summ(j=1; j.=i; n)(aij/aii + fi/aii)
// метод Простой итерации (метод Якоби)
double* Iter(double** a, int n, double* g, double* X0, double* X) {
	for (int i = 0; i < n; i++) {
		double d;
		double sum = g[i];
		for (int j = 0; j < n; j++) {
			 d = a[i][j] * X0[j];
			sum = sum +a[i][j] * X0[j];
		}
		X[i] = sum;
		sum = 0;
	}
	return X;
}

// проверка продолжения итерационного процесса 
bool check_Usl(double* X, double* X0, int n) {
	double max= fabs(X[0] - X0[0]);
	for (int i = 0; i < n; i++) {
		int k = fabs(X[i] - X0[i]);
		if (k > max) max = k;
	}
	if (max > eps) return 1;
	else return 0;
}

bool Method_Yakobi(double** matrix, int n) {
	cout << endl << "--------------------------------- МЕТОД ЯКОБИ --------------------------------- " << endl;
	if (!check_diag_preobl(matrix, n)) { cout << " УСЛОВИЕ ДИАГОНАЛЬНОГО ПРЕОБЛАДАНИЯ НЕ ВЫПОЛНЯЕТСЯ"; return 0; }
	else cout << " условие диагонального преобладания выполняется" << endl << endl;
	double** B = new double* [n];
	for (int i = 0; i < n; i++) {
		B[i] = new double[n+1];
	}
// X= BX+g
// 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			B[i][j] = matrix[i][j];
		}
	}

	double* g = new double[n];
	for (int i = 0; i < n; i++) {
		g[i] = matrix[i][n];
	}
	BX1(B, n, g);
	BX(B, n);
	double* X0 = new double[n];
	for (int i = 0; i < n; i++) {
		X0[i] = g[i];
	}
	double* X = new double[n];
	do {
		if (ITER != 0)
			for (int i = 0; i < n; i++) {
				X0[i] = X[i];
			}
		X = Iter(B, n, g, X0, X);
		ITER++;

	} while (check_Usl(X, X0, n));


	cout << " Вектор-столбец значений неизвестных: " << endl;
	OutputSt(X, n);
	cout << " Количество итераций: " << ITER << endl;

	delete[]g;
	Delete(B, n, n);
	delete[]X;
	delete[]X0;
	return 1;
}

bool check_norma(double** B, int n) {
	double max = 0;
	for (int i = 0; i < n; i++) {
		double sum = 0;
		for (int j = 0; j < n; j++) {
			sum += fabs(B[i][j]);
		}
		if (sum > max) max = sum;
	}
	if (max < 1)return 1;
	else return 0;
}

// xi = summ(1; i-1)(bij*xj^(k+1)) + summ (j=i; n)(bij*xj^(k))+gi
double* Iter_Z(double** a, int n, double* g, double* X) {
	for (int i = 0; i < n; i++) {
		double d;
		double sum = g[i];
		for (int j = 0; j < n; j++) {
			sum = a[i][j] * X[j] + sum;
		}
		X[i] = sum;
		sum = 0;
	}
	return X;
}

bool Method_Zeydelya(double** matrix, int n) {
	cout << endl << "--------------------------------- МЕТОД ЗЕЙДЕЛЯ --------------------------------- " << endl;

	double** B = new double* [n];
	for (int i = 0; i < n; i++) {
		B[i] = new double[n + 1];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			B[i][j] = matrix[i][j];
		}
	}

	double* g = new double[n];
	for (int i = 0; i < n; i++) {
		g[i] = matrix[i][n];
	}
	BX1(B, n, g);
	BX(B, n);
	if (!check_norma(B, n)) { cout << " ДОСТАТОЧНОЕ УСЛОВИЕ СХОДИМОСТИ НЕ ВЫПОЛНЯЕТСЯ"; return 0; }
	else cout << " достаточное условие сходимости выполняется " << endl << endl;
	
	double* X0 = new double[n];
	for (int i = 0; i < n; i++) {
		X0[i] = g[i];
	}
	double* X = new double[n];
	for (int i = 0; i < n; i++) {
		X[i] = X0[i];
	}

	ITER = 0;
	do {
		if (ITER != 0)
			for (int i = 0; i < n; i++) {
				X0[i] = X[i];
			}
		X = Iter_Z(B, n, g, X);
		ITER++;

	} while (check_Usl(X, X0, n));
	cout << " Вектор-столбец значений неизвестных: " << endl;
	OutputSt(X, n);
	cout << " Количество итераций: " << ITER << endl;

	delete[]g;
	Delete(B, n, n);
	delete[]X;
	delete[]X0;
	return 1;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
		cout << " Укажите размерность расширенной матрицы n x n+1" << endl;
		cout << " Введите количество строк n: ";
		cin >> n;
		int m = n + 1;
		double** matrix = new  double* [n];
		for (int i = 0; i < n; i++) {
			matrix[i] = new double[m];
		}
		InputMatrix(matrix, n, m);

		cout << endl << endl << " ~ ВВЕДЕННАЯ РАСШИРЕННАЯ МАТРИЦА СЛАУ: ~" << endl;
		OutputMatrix(matrix, n, m);
		Method_Yakobi(matrix, n);
		Method_Zeydelya(matrix, n);
				
	   Delete(matrix, n, m);

return 0;
system("pause");
return 0;
}