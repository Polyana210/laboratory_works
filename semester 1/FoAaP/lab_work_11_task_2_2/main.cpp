#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	char* N = new char[255];
	cout << "Введите количество элементов массива N: ";
	cin >> N;
	double n = atof(N);
	if (N == to_string((int)atof(N)) && n >= 1 && n - int(n) == 0) {

		long double* Array = new long double[n];
		VvodMassiva(Array, n);

		cout << "Ваш массив: ";
		VivodMassiva(Array, n);

		SortirovkaVozrastsnie(Array, n);

		cout << "Ваш массив по возрастанию:";
		VivodMassiva(Array, n);

		long double key;
		cout << "Введите искомый элемент: ";
		cin >> key;
		cout << endl;

		if (check(Array, n, key)) {
			cout << "Искомый элемент в упорядоченном массиве имеет индекс: " << bSearch(Array, n, key) << endl;
			cout << "И является A[" << bSearch(Array, n, key) << "] элементом упорядоченного массива\n" << endl;
		}
		else {
			cout << "Массив не содержит указанный элемент\n" << endl;
		}
		delete[]Array;
	}
	else cout << "Некорректный ввод" << endl;
	system("pause");
	return 0;
}