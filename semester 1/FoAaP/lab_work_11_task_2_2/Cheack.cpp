#include <iostream>
#include <string>

using namespace std;

bool check(long double* arrayPtr, double array_size, long double entry) {
	bool is_entry = false;
	for (int i = 0; i < array_size; i++) {
		if (arrayPtr[i] == entry) {
			is_entry = true;
		}
	}
	return is_entry;
}
