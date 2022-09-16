#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h> 
#include "Header.h"
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");


	char* n = new char[255];
	char* m = new char[255];


	cout << "Укажите размерность прямоугольного массива n x m" << endl;
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

		long double** arrayPtr1 = new long double*[k];
		for (int i = 0; i < k; i++) {
			arrayPtr1[i] = new long double[z];
		}


		VvodMassiva(arrayPtr, k, z);
		cout << "Исходный прямоугольный массив:" << endl;
		VivodMassiva(arrayPtr, k, z);

		Perestanovka(arrayPtr, arrayPtr1, k, z);
		cout << "Mассив со сдвигом сверху вниз по вертикали:" << endl;

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
