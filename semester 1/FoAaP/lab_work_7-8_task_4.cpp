/*Заполните случайным образом двумерный массив двузначными числами и выведите его на экран.
 Выполинте циклический сдвиг его элементов в заданном направлении. Выведите полученный массив на экран.
(Циклический сдвиг означает, что все элементы массива, по возможности, 
должны переместиться в указанном направлении.
Те крайние элементы, которым некуда перемещаться, должны появиться с противоположной стороны. 
Квадратный массив N×N по диагонали влево вверх. */

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h> 

using namespace std;

void VvodMassiva(long double** arrayPtr, size_t n, size_t m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arrayPtr[i][j]=10+rand()%90;
		}
	}
}

void VivodMassiva(long double** arrayPtr, size_t n, size_t m) {
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

void Perestanovka(long double** arrayPtr, long double** arrayPtr1, size_t n, size_t m) {

	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < m-1; j++) {
			arrayPtr1[i][j] = arrayPtr[i+1][j+1];
		}
	}  
	for (int j = 0; j < m - 1; j++) arrayPtr1[n-1][j] = arrayPtr[0][j+1];
	for (int i = 0; i < n - 1; i++) arrayPtr1[i][m-1] = arrayPtr[i+1][0];
	arrayPtr1[n-1][m-1] = arrayPtr[0][0];
	
	}


int main() {
	setlocale(LC_ALL, "Russian");


	char* n = new char[255];
	char* m = new char[255];


	cout << "Укажите размерность квадратного массива n x n" << endl;
	cout << "Введите количество строк и столбцов n: ";
	cin >> n;
	m = n;

	double k = atof(n);
	double z = atof(m);


	if (n == to_string((int)atof(n)) && m == to_string((int)atof(m)) && k > 0 && z > 0 && k - int(k) == 0 && z - int(z) == 0) {
		long double** arrayPtr = new long double*[k];
		for (int i = 0; i < k; i++) {
			arrayPtr[i] = new long double[z];
		}

		long double** arrayPtr1 = new long double*[k];
		for (int i = 0; i < k; i++) {
			arrayPtr1[i] = new long double[z];
		}


		VvodMassiva(arrayPtr, k, z);
		cout << "Исходный квадратный массив:"<<endl;
		VivodMassiva(arrayPtr, k, z);

		Perestanovka(arrayPtr, arrayPtr1,  k, z);
		cout << "Mассив со сдвигом влево вверх:"<<endl;

		VivodMassiva(arrayPtr1, k, z);
		Ochistka(arrayPtr1, k, z);
		Ochistka(arrayPtr, k, z);
	}
	else {
		cout << "Некорректный ввод\n" << endl;
	}

	system("pause");
	return 0;
}
