#include <iostream>
#include <string>
#include "Header.h"

using namespace std;
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