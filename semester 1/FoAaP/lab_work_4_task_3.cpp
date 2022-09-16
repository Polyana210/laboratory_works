#include <iostream>
using namespace std;

 double sum(double x, int n) {
	double sum = 0;
	int i = 0;
	double accuracy = pow(10, -n); 
	while (fabs(pow(-1, i) * (i + 1) * pow(x, i)) > accuracy) {
		sum += pow(-1, i) * (i + 1) * pow(x, i);
		i++;
	}
	return sum;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int h;
	double x;
	cout << "Введите х и степень h";
	cin >> x >> h;

	cout << sum(x, h) << endl;
	cout <<  1 / ((1 + x)*(1 + x)) << endl;
	system("pause");
	return 0;
}