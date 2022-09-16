#include <iostream>
#include <iomanip>

using namespace std;
// вывод матрицы
void OutputMatrix(double** arrayPtr, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j == m - 1) cout << setw(4) << " | " << setw(4) << arrayPtr[i][j];
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
				if (r != i) A[r][b] = A[r][b] - N * A[i][b];
			}
		}
		//OutputMatrix(A, n, m);
	}
	return A;
}

// расчет апроксимирующей функции F = ax + b;
void func1(int n, double X[], double Y[]) {
	cout << "--------------------------------------------------------------------" << endl
		 << "                          y = ax + b                                " <<endl
		 << "--------------------------------------------------------------------" << endl;
	/* расчет апроксимирующей функции F = ax + b;
   S(ax+b-y)x=0
   S(ax+b-y)1=0

   a*Sx2 +b*Sx= Sxy
   a*Sx+7*b= Sy
*/
	double a, b, Sx2 = 0, Sxy = 0, Sy = 0, Sx = 0;
	for (int i = 0; i < n; i++) {
		Sx += X[i];
		Sy += Y[i];
		Sx2 += X[i] * X[i];
		Sxy += X[i] * Y[i];
	}

	int N = 2, M = 3;
	double** matrix = new  double* [N];
	for (int i = 0; i < N; i++) {
		matrix[i] = new double[M];
	}
	matrix[0][0] = Sx2;
	matrix[0][1] = Sx;
	matrix[0][2] = Sxy;
	matrix[1][0] = Sx;
	matrix[1][1] = n;
	matrix[1][2] = Sy;
	cout << " Полученная система: " << endl;
	OutputMatrix(matrix, N, M);
	Gauss_Jordan_method(N, M, matrix);
	a = matrix[0][2];
	b = matrix[1][2];
	cout << " Аппроксимирующая линейная функция: " << endl
		<< " y = " << a << "*x + " << b << endl;
	Delete(matrix, N, M);

	double r=0;
	for (int i = 0; i < n; i++) {
		r += (a * X[i] + b - Y[i]) * (a * X[i] + b - Y[i]);
	}
	cout <<" Cуммa квадратов отклонений: "<< endl
		 << " ||r|| = "<< r<< endl;

}

// расчет апроксимирующей функции F = ax2 + bx + c;
void func2(int n, double X[], double Y[]) {
	cout << "--------------------------------------------------------------------" << endl
		<< "                        y = ax2 + bx + c                             " << endl
		<< "--------------------------------------------------------------------" << endl;
	/* расчет апроксимирующей функции F = ax2 + bx + c;
   S(ax2+bx+c-y)x2=0
   S(ax2+bx +c -y)x=0
   S(ax2+bx+c-y)1=0

   a*Sx4 + b*Sx3 + с*Sx2 = Sx2y
   a*Sx3 + b*Sx2 + с*Sx = Sxy
   a*Sx2 + b*Sx + 7*c = Sy
*/
	double a, b, c, Sx4 = 0, Sx3 = 0, Sx2 = 0, Sx2y = 0, Sx = 0, Sxy = 0, Sy=0;
	for (int i = 0; i < n; i++) {
		Sx += X[i];
		Sy += Y[i];
		Sx2 += X[i] * X[i];
		Sx3 += X[i] * X[i] * X[i];
		Sx4 += X[i] * X[i] * X[i] * X[i];
		Sxy += X[i] * Y[i];
		Sx2y += X[i] * X[i] * Y[i];
	}

	int N = 3, M = 4;
	double** matrix = new  double* [N];
	for (int i = 0; i < N; i++) {
		matrix[i] = new double[M];
	}
	matrix[0][0] = Sx4;
	matrix[0][1] = Sx3;
	matrix[0][2] = Sx2;
	matrix[0][3] = Sx2y;
	matrix[1][0] = Sx3;
	matrix[1][1] = Sx2;
	matrix[1][2] = Sx;
	matrix[1][3] = Sxy;
	matrix[2][0] = Sx2;
	matrix[2][1] = Sx;
	matrix[2][2] = n;
	matrix[2][3] = Sy;
	cout << " Полученная система: " << endl;
	OutputMatrix(matrix, N, M);
	Gauss_Jordan_method(N, M, matrix);
	a = matrix[0][3];
	b = matrix[1][3];
	c=  matrix[2][3];
	cout << " Аппроксимирующая квадратичная функция: " << endl
		<< " y = " << a << "*x2 + " << b << "*x + " << c<< endl;
	Delete(matrix, N, M);

	double r = 0;
	for (int i = 0; i < n; i++) {
		r += (a * X[i] * X[i] + b * X[i] + c - Y[i]) * (a * X[i] * X[i] + b * X[i] + c - Y[i]);
	}
	cout << " Cуммa квадратов отклонений: " << endl
		<< " ||r|| = " << r << endl;
}

// расчет апроксимирующей функции F = ax3 + bx2 + cx + d;
void func3(int n, double X[], double Y[]) {
	cout << "--------------------------------------------------------------------" << endl
		<< "                     y = ax3 + bx2 + cx + d                         " << endl
		<< "--------------------------------------------------------------------" << endl;
	/* расчет апроксимирующей функции F = ax3 + bx2 + cx + d;
   S(ax3 + bx2 + cx + d -y)x3=0 
   S(ax3 + bx2 + cx + d -y)x2=0
   S(ax3 + bx2 + cx + d -y)x=0
   S(ax3 + bx2 + cx + d -y)1=0

   a*Sx6 + b*Sx5 + с*Sx4 + d*Sx3 = Sx3y
   a*Sx5 + b*Sx4 + с*Sx3 + d*Sx2 = Sx2y
   a*Sx4 + b*Sx3 + с*Sx2 + d*Sx = Sxy
   a*Sx3 + b*Sx2 + с*Sx + d*7 = Sy
*/
	double a, b, c, d, Sx6=0, Sx5=0, Sx4 = 0, Sx3 = 0, Sx2 = 0, Sx2y = 0, Sx3y = 0, Sx = 0, Sxy = 0, Sy = 0;
	for (int i = 0; i < n; i++) {
		Sx += X[i];
		Sx2 += X[i] * X[i];
		Sx3 += X[i] * X[i] * X[i];
		Sx4 += X[i] * X[i] * X[i] * X[i];
		Sx5 += X[i] * X[i] * X[i] * X[i] * X[i];
		Sx6 += X[i] * X[i] * X[i] * X[i] * X[i] * X[i];
		Sy += Y[i];
		Sxy += X[i] * Y[i];
		Sx2y += X[i] * X[i] * Y[i];
		Sx3y += X[i] * X[i] * X[i] * Y[i];
	}

	int N = 4, M = 5;
	double** matrix = new  double* [N];
	for (int i = 0; i < N; i++) {
		matrix[i] = new double[M];
	}
	matrix[0][0] = Sx6;
	matrix[0][1] = Sx5;
	matrix[0][2] = Sx4;
	matrix[0][3] = Sx3;
	matrix[0][4] = Sx3y;
	matrix[1][0] = Sx5;
	matrix[1][1] = Sx4;
	matrix[1][2] = Sx3;
	matrix[1][3] = Sx2;
	matrix[1][4] = Sx2y;
	matrix[2][0] = Sx4;
	matrix[2][1] = Sx3;
	matrix[2][2] = Sx2;
	matrix[2][3] = Sx;
	matrix[2][4] = Sxy;
	matrix[3][0] = Sx3;
	matrix[3][1] = Sx2;
	matrix[3][2] = Sx;
	matrix[3][3] = n;
	matrix[3][4] = Sy;
	cout << " Полученная система: " << endl;
	OutputMatrix(matrix, N, M);
	Gauss_Jordan_method(N, M, matrix);
	a = matrix[0][4];
	b = matrix[1][4];
	c = matrix[2][4];
	d = matrix[3][4];
	cout << " Аппроксимирующая кубическая функция: " << endl 
		<< " y = " << a << "*x3 + " << b << "*x2 + " << c << "*x + " << d << endl;
	Delete(matrix, N, M);

	double r = 0;
	for (int i = 0; i < n; i++) {
		r += (a * X[i] * X[i] * X[i] + b * X[i] * X[i] + c * X[i] +d - Y[i]) * (a * X[i] * X[i] * X[i] + b * X[i] * X[i] + c * X[i] + d - Y[i]);
	}
	cout << " Cуммa квадратов отклонений: " << endl
		<< " ||r|| = " << r << endl;
}

int main() {
	setlocale(LC_ALL, "rus");
	int n = 7;
	double X[7] = { 0, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0 };
	double Y[7] = { 1.67, 1.2, 1.10, 0.81, 0.48, 0.18, -0.10};
	func1(n, X, Y);
	func2(n, X, Y);
	func3(n, X, Y);

	cout << "--------------------------------------------------------------------" << endl;
	return 0;
}