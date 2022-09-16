#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h> 
#include "Header.h"
using namespace std;
void VvodMassiva(long double** arrayPtr, size_t n, size_t m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arrayPtr[i][j] = 10 + rand() % 90;
		}
	}
}