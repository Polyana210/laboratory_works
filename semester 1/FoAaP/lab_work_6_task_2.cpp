/* Задан массив из N действительных чисел. Составьте программу для поиска в этом массиве
Сумму элементов массива, расположенных между первым и вторым положительными элементами. */

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
			cout << "A[" << i  << "]= ";
			cin >> t;
			Array[i] = t;
		}

		cout << "Ваш массив: [ ";

		for (int p = 0; p < n; p++) {
			cout << Array[p] << " ";
		}
		cout << "]" << endl << endl;


		int plus = 0;
		for (int k = 0; k < n; k++) {
			if (Array[k]>0) {
				plus++;
			}
		}
		cout << "Количество положительных элементов в массиве: " << plus << endl;


		if (plus >= 2) {
			int f = 0;
			while (Array[f] <= 0) {
				f++;
			}

			cout << "Первый положительный элемент массива A[" << f << "]" << endl;
			f++;

			long double s = 0;

			while (Array[f] <= 0) {
				s += Array[f];
				f++;
			}
			cout << "Второй положительный элемент массива A[" << f << "]" << endl;
			cout << "Сумма элементов массива, расположенных между первым и вторым положительными элементами равна:  " << s << endl << endl;

		}
		else {
			cout << "В массиве меньше двух положительных элементов " << endl << endl;
		}
		delete[]Array;
	}
	else {
		cout << "Некорректный ввод" << endl;
	}

	system("pause");
	return 0;
}