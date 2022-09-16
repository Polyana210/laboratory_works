#include <iostream>
#include <conio.h>
using namespace std;
int main(){
	setlocale(0, "");
	int i, n, a[30];
	int *max = a;
	int num = 0;
	cout << "Задайте натуральное число: ";
	cin >> i;
	if (i > 0) {
		for (n = 0; i != 0; n++) {
				a[n] = i % 10;
				if (a[n] > *max) {
					max = &a[n];
					num = n;
				}
				i /= 10;
			}
			for (n -= 1; n >= 0; n--) {
				if (n != num)cout << a[n];
			}
			cout << endl;
		}
	else cout << "!Число "<< i << " не натуральное!" << endl;
		system("pause");
		return 0;
	}