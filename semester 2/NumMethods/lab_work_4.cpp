#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdlib.h> 
int n;
int P;
using namespace std;

void InputMatrix(double** arrayPtr, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << "A[" << i + 1 << "][" << j + 1 << "] = ";
			cin >> arrayPtr[i][j];
		}
	}
}

// ����� �������
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
// ������� ������
void Delete(double** arrayPtr, int n, int m) {
	for (int i = 0; i < n; i++) {
		delete[]arrayPtr[i];
	}
	delete[]arrayPtr;
}

// ����� ������������ �����
int min(int n, int m) {
	if (n > m) return m;
	else return n;
}

// ������� ����� ������
double line_sum(int line, double** a, int m) {
	double sum = 0;
	for (int i = 0; i < m - 1; i++) {
		if (a[line][i] == 0) sum += a[line][i];
		else return 100;
	}
	return sum;
}

// ����� ���������� ������� �����
int empty_row(double** a, int n, int m) {
	int empty = 0;
	for (int i = 0; i < n; i++) {
		if (line_sum(i, a, m + 1) == 0)empty++;
	}
	return empty;
}

// �������� ������
double** delete_row(double** a, int n, int m, int empty) {
	int N = n - empty;
	double** MATRiX = new double* [N];
	for (int i = 0; i < N; i++) {
		MATRiX[i] = new double[m];
	}
	cout << " ~ ������� ������� ������ ~" << endl;
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (line_sum(i, a, m + 1) != 0)
			for (int jo = 0; jo < m; jo++) {
				MATRiX[k][jo] = a[i][jo];
				if (jo == m - 1)k++;
			};
	}
	return MATRiX;
}

int NO_NULL(double** A, int m, int s) {
	int i = m + 1;
	for (int h = 0; h < m - 1; h++) {
		if (A[s][h] != 0) {
			return h;
		}
	}
	return i;
}

//���� ����� ������, �� ������ ��� ������ ����
double** ffff(double** A, int n, int m, int s, int p) {

	double u = A[s][p];
	for (int g = p; g < m; g++) {
		A[s][g] = A[s][g] / u;
	}

	for (int r = s + 1; r < n; r++) {
		double N = A[r][p];
		for (int b = p; b < m; b++) {
			A[r][b] = A[r][b] - N * A[s][b];
		}
	}

	OutputMatrix(A, n, m);

	return A;
}

//������� ��� ����������� ����� �������
void inf_solution(double** matrix, int n, int m) {
	int empty = empty_row(matrix, n, m);
	int N = n - empty;
	double** matrix1 = new  double* [N];
	for (int i = 0; i < N; i++) {
		matrix1[i] = new double[m];
	}

	matrix1 = delete_row(matrix, n, m, empty);
	OutputMatrix(matrix1, N, m);
	cout << " ~ �������� ������� � ������������ ���� ~" << endl;
	for (int j = 0; j <= N - 1; j++) {
		int y = NO_NULL(matrix1, m, j);
		if (y != m - 1) matrix1 = ffff(matrix1, N, m, j, y);
	}

	int empty1 = empty_row(matrix1, N, m);
	int L = N - empty1;
	double** matrix2 = new  double* [L];
	for (int i = 0; i < L; i++) {
		matrix2[i] = new double[m];
	}

	matrix2 = delete_row(matrix1, N, m, empty1);
	OutputMatrix(matrix2, L, m);

	int* PER = new int[m - 1];
	for (int i = 0; i < m - 1; i++) {
		PER[i] = 0;
	}
	cout << " ~ ���������� �������� ���������� ~" << endl;
	for (int j = 0; j < L; j++) {
		int p = NO_NULL(matrix2, m, j);
		PER[p] = 1;
		cout << "X[" << p + 1 << "] " << endl;
	}

	double* X = new double[m - 1];
	for (int i = 0; i < m - 1; i++) {
		if (PER[i] == 0) {
			cout << "������� �������� ��������� ���������� X[" << i + 1 << "]=";
			cin >> X[i];
		}
	}

	n = L;
	cout << endl << "    ������-������� �������� �����������:" << endl;
	int E;
	int U = m;
	for (int k = n - 1; k >= 0; k--) {
		U--;
		for (int r = U; r >= 0; r--) {
			if (PER[r] == 1) {
				E = r; U = r; break;
			}
		}

		int d = 0;
		for (int j = E + 1; j <= m - 2; j++)
		{
			double s = matrix2[k][j] * X[j];
			d = d + s;
		}
		X[E] = (matrix2[k][m - 1] - d);
	}
	for (int l = 0; l < m - 1; l++) {
		cout << setw(20) << X[l] << endl;
	}
	cout << endl;

	delete[]X;
	delete[]PER;
	exit(0);
}

double** swap(double** a, int n, int m, int i) {
	double* temp = new double[m];
	if (i == n - 1) return a; else {
		for (int r = 0; r < m; r++) {
			temp[r] = a[i][r];
			a[i][r] = a[i + 1][r];
			a[i + 1][r] = temp[r];
		}
		OutputMatrix(a, n, m);
		return a;
	}
}


// ����������� ����� �������
int solution(double** a, int n, int m) {
	bool no_solutions = false;
	double diagonal_sum = 0;

	int min_variables_row_count = m - 1;
	for (int i = 0; i < n; i++) {
		double sum = line_sum(i, a, m);

		if (sum == 0 && a[i][m - 1] != 0) {
			throw "������� �� ����� �������";
		}
		if (sum == 0 && a[i][m - 1] == 0)
			swap(a, n, m, i);
	}

	int Nu = empty_row(a, n, m);

	for (int i = 0; i < n - Nu; i++) {
		if (a[i][i] == 0) {
			swap(a, n, m, i);
			return Nu;
		}
	}
	return Nu;
}
double** jordan(double** A, int n, int m) {

	for (int i = n-1; i >= 0; i--) {
		double u = A[i][i];
		if (u != 0) for (int g = 0; g < m; g++) {
			A[i][g] = A[i][g] / u;
		}

		for (int r = i - 1; r >=0 ; r--) {
			double N = A[r][i];
			for (int b = 0; b < m; b++) {
				A[r][b] = A[r][b] - N * A[i][b];
			}
		}

		OutputMatrix(A, n, m);
		int K = solution(A, n, m);
	}
	return A;
}

// ������ ��� ������ ������
double** Straight_running(int n, int m, double** A) {
	int K = 0;
	for (int i = 0; i < n; i++) {
		double u = A[i][i];
		if (u != 0) for (int g = 0; g < m; g++) {
			A[i][g] = A[i][g] / u;
		}

		for (int r = i + 1; r < n; r++) {
			double N = A[r][i];
			for (int b = 0; b < m; b++) {
				A[r][b] = A[r][b] - N * A[i][b];
			}
		}

		OutputMatrix(A, n, m);
		K = solution(A, n, m);
	}

	A = jordan(A, n, m);
	K = solution(A, n, m);
	n = n - K;
	P = n;
	double** matrix1 = new  double* [n];
	for (int i = 0; i < n; i++) {
		matrix1[i] = new double[m];
	}
	matrix1 = delete_row(A, n + K, m, K);
	OutputMatrix(matrix1, n, m);
	return matrix1;
}

// �������� ��� ������ ������
double* Reverse_course(double** a, int n, int m) {
	double* x = new  double[m - 1];
	double d;
	for (int k = n - 1; k >= 0; k--)
	{
		d = 0;
		for (int j = k + 1; j <= m - 2; j++)
		{
			double s = a[k][j] * x[j];
			d = d + s;
		}
		x[k] = (a[k][n] - d);
	}
	for (int l = 0; l < m - 1; l++) {
		cout << setw(20) << x[l] << endl;
	}
	cout << endl;
	return x;
}



int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	int m;
	try {
		cout << "������� ����������� ����������� ������� n x m" << endl;
		cout << "������� ���������� ����� n: ";
		cin >> n;
		cout << "������� ���������� �������� m: ";
		cin >> m;

		double** matrix = new  double* [n];
		for (int i = 0; i < n; i++) {
			matrix[i] = new double[m];
		}
		InputMatrix(matrix, n, m);


		cout << endl << "    ��������� ����������� ������� ����:" << endl;
		OutputMatrix(matrix, n, m);
		cout << endl << "    ����� ������:" << endl;
		Straight_running(n, m, matrix);

		if (P < m - 1) {
			cout << "  �����: ������� ����� ����������� ��������� �������" << endl;
			inf_solution(matrix, n, m);
		}
		else {
			cout << endl << "    ������-������� �������� �����������:" << endl;
			Reverse_course(matrix, n, m);
		}
		Delete(matrix, n, m);
	}
	catch (const char* exception)
	{
		std::cerr << "  �����: " << exception << '\n';
	}
	return 0;
	system("pause");
	return 0;
}
