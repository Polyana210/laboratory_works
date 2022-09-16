#include <iostream>
#include <string>

using namespace std;

void VvodMassiva(long double* arrayPtr, double array_size) {
	for (int i = 0; i < array_size; i++) {
		cout << "A[" << i << "]= ";
		cin >> arrayPtr[i];
	}
}