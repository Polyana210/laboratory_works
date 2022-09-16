#include <iostream>
#include <string>
using namespace std;

int bSearch(long double* Array, double array_size, double key) {
	int left = 0;
	int right = array_size - 1;
	while (left < right) {
		int mid = (left + right) / 2;
		if (key < Array[mid]) {
			right = mid - 1;
		}
		else if (key > Array[mid]) {
			left = mid + 1;
		}
		else {
			return mid;
		}
	}
}

