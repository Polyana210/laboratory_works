/*Задание 2. Используя алгоритм бинарного поиска определите,
 содержит ли ранее упорядоченный массив заданное действительное число. 
Если содержит, то выведите индекс искомого элемента. */

#include <iostream>
#include <string>

using namespace std;

void VvodMassiva(long double* arrayPtr, double array_size) {
	for (int i = 0; i < array_size; i++) {
		cout << "A[" << i << "]= ";
		cin >> arrayPtr[i];
	}
}

void VivodMassiva(long double* arrayPtr, double array_size) {
	cout << "[";
	for (int i = 0; i < array_size; i++) {
		cout << arrayPtr[i] << " ";
	}
	cout << "]\n" << endl;
	}


void SortirovkaVozrastsnie(long double* arrayPtr, double array_size) {
	long double temp;
	int index;
	for (int i = 1; i < array_size; i++) {
		temp = arrayPtr[i];
		index = i - 1;
		while (index >= 0 && arrayPtr[index] > temp) {
			arrayPtr[index + 1] = arrayPtr[index];
			arrayPtr[index] = temp;
			index--;
		}
	}
}

bool check(long double* arrayPtr, double array_size, long double entry) {
	bool is_entry = false;
	for (int i = 0; i < array_size; i++) {
		if (arrayPtr[i] == entry) {
			is_entry = true;
		}
	}
	return is_entry;
}

int bSearch(long double* Array, double array_size, double key) {
	int left = 0;
	int right = array_size - 1;
	while (left < right) {
		int mid = (left + right) / 2;
		if (key < Array[mid]) {
			right = mid - 1;
		}
		else if (key > Array[mid]) {
			left = mid + 1;
		}
		else {
			return mid;
		}
	}
}

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