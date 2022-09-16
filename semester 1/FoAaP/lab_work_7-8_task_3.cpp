/*Задан двумерный массив. Составьте программу для поиска в этом массиве.
Подсчитайте количество локальных максимумов в прямоугольном массиве N×M. 
(Элемент массива является локальным максимумом, если он строго больше всех соседних с ним элементов).*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void VvodMassiva(long double** arrayPtr, size_t n, size_t m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << "A[" << i << "][" << j << "]=  ";
			cin >> arrayPtr[i][j];
		}
	}
}

void VivodMassiva(long double** arrayPtr, size_t n, size_t m) {
	cout << "\nВаш массив: \n" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(5) << arrayPtr[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void Ochistka(long double** arrayPtr, size_t n, size_t m) {
	for (int i = 0; i < n; i++) {
		delete[]arrayPtr[i];
	}
	delete[]arrayPtr;
}

int Podschet(long double** arrayPtr, size_t n, size_t m) {
	int M = 0;
	for (int i = 1; i < n-1; i++) {
		for (int j = 1; j < m - 1; j++) {
			if (arrayPtr[i][j] > arrayPtr[i + 1][j] && arrayPtr[i][j] > arrayPtr[i][j + 1] && arrayPtr[i][j] > arrayPtr[i - 1][j] && arrayPtr[i][j] > arrayPtr[i][j - 1]) M++;
		}
	}
	
	for (int j = 1; j < m-1; j++) {
		if (arrayPtr[0][j] > arrayPtr[1][j] && arrayPtr[0][j] > arrayPtr[0][j + 1] && arrayPtr[0][j] > arrayPtr[0][j - 1]) M++;
	}
	
	for (int j = 1; j < m - 1; j++) {
		if (arrayPtr[n - 1][j] > arrayPtr[n - 2][j] && arrayPtr[n - 1][j] > arrayPtr[n - 1][j + 1]&& arrayPtr[n - 1][j] > arrayPtr[n - 1][j + 1]) M++;
	}
	
	for (int u = 1; u < n - 1; u++) {
		if (arrayPtr[u][0] > arrayPtr[u - 1][0] && arrayPtr[u][0] > arrayPtr[u][1] && arrayPtr[u][0] > arrayPtr[u+1][0]) M++;
	}

	for (int u = 1; u < n - 1; u++) {
		if (arrayPtr[u][m-1] > arrayPtr[u - 1][m-1] && arrayPtr[u][m-1] > arrayPtr[u][m-2] && arrayPtr[u][m-1] > arrayPtr[u + 1][m-1]) M++;
	}
	if (arrayPtr[0][0] > arrayPtr[1][0] && arrayPtr[0][0] > arrayPtr[0][1])M++;
	if (arrayPtr[n-1][0] > arrayPtr[n-1][1] && arrayPtr[n-1][0] > arrayPtr[n-2][0])M++;
	if (arrayPtr[0][m-1] > arrayPtr[0][m-2] && arrayPtr[0][m-1] > arrayPtr[1][m-1])M++;
	if (arrayPtr[n-1][m-1] > arrayPtr[n-2][m-1] && arrayPtr[n-1][m-1] > arrayPtr[n-1][m-2])M++;
		return M;
}


int main() {
	setlocale(LC_ALL, "Russian");


	char* n = new char[255];
	char* m = new char[255];


	cout << "Укажите размерность массива n x m" << endl;
	cout << "Введите количество строк n: ";
	cin >> n;
	cout << "Введите количество столбцов m: ";
	cin >> m;

	double k = atof(n);
	double z = atof(m);


	if (n == to_string((int)atof(n)) && m == to_string((int)atof(m)) && k > 0 && z > 0 && k - int(k) == 0 && z - int(z) == 0) {
		long double** arrayPtr = new long double*[k];
		for (int i = 0; i < k; i++) {
			arrayPtr[i] = new long double[z];
		}

		VvodMassiva(arrayPtr, k, z);

		VivodMassiva(arrayPtr, k, z);

		cout << "Количество локальных максимумов М = " << Podschet(arrayPtr, k, z) << "\n" << endl;

		Ochistka(arrayPtr, k, z);

	}
	else {
		cout << "Некорректный ввод\n" << endl;
	}

	system("pause");
	return 0;
}