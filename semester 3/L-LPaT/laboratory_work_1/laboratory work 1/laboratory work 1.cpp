#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	string str;
	cout << "Enter string: ";
	cin >> str;

	regex reg("ab*((c|d)*e)*");

	if (regex_match(str, reg)) {
		cout << "Result: YES" << endl;
	}
	else {
		cout << "Result: NO" << endl;
	}
	return 0;
}