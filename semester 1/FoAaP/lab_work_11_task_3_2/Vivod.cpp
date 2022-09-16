#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h> 
#include "Header.h"
using namespace std;

void VivodMassiva(long double** arrayPtr, size_t n, size_t m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(5) << arrayPtr[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
