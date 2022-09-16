/*Задание 3. Задан массив из N действительных чисел. Составьте программу для преобразования массива.
Переставьте элементы массива так, чтобы сначала шли все положительные элементы массива, 
затем все неположительные (с сохранением исходного относительного порядка).  */

#include <iostream>

using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");

	double n;
	cout << "Введите количество элементов массива N: ";
	cin >> n;

	if (n >= 1 && n - int(n) == 0) {
		long double* Array = new long double[n];

		for (int i = 0; i < n; i++) {
			long double t;
			cout << "A[" << i << "]= ";
			cin >> t;
			Array[i] = t;
		}

		cout << "Ваш массив: [ ";

		for (int p = 0; p < n; p++) {
			cout << Array[p] << " ";
		}
		cout << "]" << endl << endl;

		
		cout << "Преобразованный массив: [ " ;
		for (int i=0; i < n; i++)
		{
			if (Array[i] > 0)
				cout << Array[i] << " ";
		}
		for (int i=0; i < n; i++)
		{
			if (Array[i] <= 0)
				cout << Array[i] << " ";
		}
		cout << "]";
		cout << endl;

	}
	else {
		cout << "Некорректный ввод" << endl;
	}

	system("pause");
	return 0;
}
