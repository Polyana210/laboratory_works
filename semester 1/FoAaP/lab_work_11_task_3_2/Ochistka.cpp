#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h> 
#include "Header.h"
using namespace std;
void Ochistka(long double** arrayPtr, size_t n, size_t m) {
	for (int i = 0; i < n; i++) {
		delete[]arrayPtr[i];
	}
	delete[]arrayPtr;
}
