#include <iostream>
#include <iomanip>
#include <string>
#include "Header.h"

int Podschet(long double** arrayPtr, size_t n, size_t m) {
	int M = 0;
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			if (arrayPtr[i][j] < arrayPtr[i + 1][j] && arrayPtr[i][j] < arrayPtr[i][j + 1] && arrayPtr[i][j] < arrayPtr[i - 1][j] && arrayPtr[i][j] < arrayPtr[i][j - 1]) M++;
		}
	}

	for (int j = 1; j < m - 1; j++) {
		if (arrayPtr[0][j] < arrayPtr[1][j] && arrayPtr[0][j] < arrayPtr[0][j + 1] && arrayPtr[0][j] < arrayPtr[0][j - 1]) M++;
	}

	for (int j = 1; j < m - 1; j++) {
		if (arrayPtr[n - 1][j] < arrayPtr[n - 2][j] && arrayPtr[n - 1][j] < arrayPtr[n - 1][j + 1] && arrayPtr[n - 1][j] < arrayPtr[n - 1][j + 1]) M++;
	}

	for (int u = 1; u < n - 1; u++) {
		if (arrayPtr[u][0] < arrayPtr[u - 1][0] && arrayPtr[u][0] < arrayPtr[u][1] && arrayPtr[u][0] < arrayPtr[u + 1][0]) M++;
	}

	for (int u = 1; u < n - 1; u++) {
		if (arrayPtr[u][m - 1] < arrayPtr[u - 1][m - 1] && arrayPtr[u][m - 1] < arrayPtr[u][m - 2] && arrayPtr[u][m - 1] < arrayPtr[u + 1][m - 1]) M++;
	}
	if (arrayPtr[0][0] < arrayPtr[1][0] && arrayPtr[0][0] < arrayPtr[0][1])M++;
	if (arrayPtr[n - 1][0] < arrayPtr[n - 1][1] && arrayPtr[n - 1][0] < arrayPtr[n - 2][0])M++;
	if (arrayPtr[0][m - 1] < arrayPtr[0][m - 2] && arrayPtr[0][m - 1] < arrayPtr[1][m - 1])M++;
	if (arrayPtr[n - 1][m - 1] < arrayPtr[n - 2][m - 1] && arrayPtr[n - 1][m - 1] < arrayPtr[n - 1][m - 2])M++;
	return M;
}