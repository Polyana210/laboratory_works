#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
char int_symbol(int in) {
	char out[] = { '0','1','2','3','4','5','6','7','8','9',
	'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P',
	'Q','R','S','T','U','V','W','X','Y','Z' };
	return out[in];
}


void ten_base(int in, int base) {
	if (in < base) {
		std::cout << int_symbol(in);
		return;
	}
	ten_base(in / base, base);
	cout << int_symbol(in%base);
}
 

int main() {
	setlocale(LC_ALL, "RUS");

	char* N = new char[255]; //выделение памяти для строки (переводимое число)

	cout << "Введите натуральное число N (от 1 до 1000) в десятичной системе счисления: "<< endl;
	cin >> N;
	double in = atof(N);
	if (N == to_string((int)atof(N)) && in >= 1 && in <= 1000 && in - int(in) == 0) { 

		char* Base = new char[255]; //выделение памяти для строки (основание сс)

		cout << "Введите основание системы счисления, в которую будем переводить (натуральное число от 2 до 36):"<<endl;
		cin >> Base;
		double base = atof(Base);
		if (Base == to_string((int)atof(Base)) && base >= 2 && base <= 36 && base - int(base) == 0) {
			cout << "Результат перевода с помощью вычислений: ";
		   ten_base(in, base);
		   cout << endl;
		   cout << "Результат перевода с помощью функции _itoa(): " ;
		   char* res = new char[255]; //выделение памяти для строки (результат)
		   _itoa(in, res, base);
		   cout << res;
		   cout << endl;


		   delete[]Base;
		   delete[]N;     //очищение памяти
		   delete[]res;


		}  else cout << "****Проверьте корректность введенных данных****";
	}	else cout << "****Проверьте корректность введенных данных****";
	cout << endl;

	return 0;
}