/*Задание 1. Задан одномерный массив из N действительных чисел. Необходимо упорядочить его элементы методом вставки
а) по возрастанию;
б) по убыванию. 
*/

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

void SortirovkaUbivanie(long double* arrayPtr, double array_size) {
	long double temp;
	int index;
	for (int i = 1; i < array_size; i++) {
		temp = arrayPtr[i];
		index = i - 1;
		while (index >= 0 && arrayPtr[index] < temp) {
			arrayPtr[index + 1] = arrayPtr[index];
			arrayPtr[index] = temp;
			index--;
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

		SortirovkaUbivanie(Array, n);
	   	cout << "Ваш массив по убыванию:  ";
		VivodMassiva(Array, n);
	
		delete[]Array;
	} else cout << "Некорректный ввод" << endl;
	system("pause");
	return 0;
}