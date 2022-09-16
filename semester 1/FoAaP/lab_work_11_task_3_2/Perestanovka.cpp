#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h> 
#include "Header.h"
using namespace std;
void Perestanovka(long double** arrayPtr, long double** arrayPtr1, size_t n, size_t m) {

	for (int i = 1; i < n ; i++) {
		for (int j = 0; j < m ; j++) {
			arrayPtr1[i][j] = arrayPtr[i - 1][j];
		}
	}

	for (int j=0; j < m ; j++) arrayPtr1[0][j] = arrayPtr[n-1][j];
	//arrayPtr1[n - 1][m - 1] = arrayPtr[0][0];

}