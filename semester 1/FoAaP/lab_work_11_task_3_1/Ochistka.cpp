#include <iostream>
#include <iomanip>
#include <string>
#include "Header.h"

void Ochistka(long double** arrayPtr, size_t n, size_t m) {
	for (int i = 0; i < n; i++) {
		delete[]arrayPtr[i];
	}
	delete[]arrayPtr;
}