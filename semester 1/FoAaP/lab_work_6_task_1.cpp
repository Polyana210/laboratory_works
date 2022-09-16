/* Задание 1. Задан массив из N действительных чисел. Найдите в этом массиве произведение элементов массива с нечетными индексами.  */

#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	double n;

	cout << "Введите количество элементов массива N: ";
	cin >> n;

	if (n >= 1 && n - int(n) == 0) {
		if (n == 1) cout << "Элементов с нечетными номерами нет" <<endl; else {
			long double *Array = new long double[n];

			for (int i = 0; i < n; i++) {
				long double t;
				cout << "A[" << i << "]= ";
				cin >> t;
				Array[i] = t;
			}

			cout << "Заданный массив: [ ";

			for (int i = 0; i < n; i++) {
				cout << Array[i] << " ";
			}
			cout << "]" << endl;

			long double pr = 1;
				for (int p = 1; p < n; p = p+2) {
				pr *= Array[p]; }
		

			cout << "Произведение элементов массива с нечетными номерами равно " << pr << endl;

			delete[]Array;
		}
	}
	else {
		cout << "Проверьте введенные данные" << endl;
	}


	system("pause");
	return 0;
}