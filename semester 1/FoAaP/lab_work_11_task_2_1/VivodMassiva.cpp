#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

void VivodMassiva(long double* arrayPtr, double array_size) {
	cout << "[ ";
	for (int i = 0; i < array_size; i++) {
		cout << arrayPtr[i] << " ";
	}
	cout << "]\n" << endl;
}