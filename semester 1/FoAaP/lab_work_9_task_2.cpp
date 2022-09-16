#include <iostream>
using namespace std;

char *scobki(char *a) {
	int i = 0;
	while (strchr(a, ')') != NULL) {
		if (a[i] == '(' && (isalpha(a[i + 1] || isdigit(a[i + 1])))) {
			int j = i;
			while (true) {
				if (a[j] == '(') a[j] = ' ';
				if (a[j] == ')') {
					a[j] = ' ';
					break;
				}
			}
		}
		if (a[i] == '(' && a[i - 1] != '-') {
			int j = i;
			while (a[j - 1] != ')') {
				if (a[j] == '(') a[j] = ' ';
				if (a[j] == ')') {
					a[j] = ' ';
					break;
				}
				j++;
			}
		}
		if (a[i] == '(' && a[i - 1] == '-') {
			int j = 0;
			while (a[j - 1] != ')') {
				if (a[j] == '(') {
					swap(a[j], a[j - 1]);
					a[j - 1] = ' ';
					j += 2;
				}
				if ((isalpha(a[j]) || isdigit(a[j]))) {
					if (a[j - 1] == '-')
						a[j - 1] = '+';
					else if (a[j - 1] == '+')
						a[j - 1] = '-';
					else
						a[j - 1] = '-';
				}
				if (a[j] == ')') {
					a[j] = ' ';
					i = j;
					break;
				}
				j++;
			}
		}
		i++;
	}
	cout << a;
	return a;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	char* chr = new char[255];
	cout << "Введите выражение: "<<endl;
	cin >> chr;
	cout << "Выражение, полученное после раскрытия скобок: " << endl;
	scobki(chr);
	cout << endl;
	system("pause");
	return 0;
	delete[]chr;
}