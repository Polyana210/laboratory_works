#include <iostream>
using namespace std;

bool Simplicity_of_numbers(int Num) {             // размерность  l=1
	int div = 0;                                  // временная сложность T(l)= n
	for (int i = 1; i <= Num; i++) {              // емкостная сложность S(l)=3;
		if (Num % i == 0) div++;                  
		if (div == 3) return false;
	} 
	return true;
}
 
bool Sieve_of_eratosthenes(int* a, int n, int Num) {    // размерность l=n+2
	for (int i = 2; i * i <= n; i++)                    // временная сложность Т(l)= n^2+n
	{	if (a[i])                                       // емкостная сложность S(l)= n+5;
		for (int j = i * i; j <= n; j += i)		
		a[j] = 0;
	}
		for (int i = 2; i < n; i++)	{
		if (a[i] == Num) return true;
	    }
	return false;
}

int main() {
	setlocale(LC_ALL, "rus");
	double Num; 
	cout << "Введите натуральное число (от 1 до 1000): ";
	cin >> Num;
	try {
		if (Num <= 0 || Num - int(Num) != 0)
			throw "Число должно быть натуральным !!!";
		if ( Num > 1000)
			throw "Число должно быть натуральным !!!";
		if (Num == 1 ) cout << "Число 1 не является ни простым, ни составным";
		else {
			cout << "АЛГОРИТМ ПОЛНОГО ПЕРЕБОРА: " << endl;
			if (Simplicity_of_numbers(int(Num)))cout << "Число простое" << endl;
			else cout << "Число составное" << endl;

			int Num1 = int(Num) + 1;
			int* a = new int[Num1 + 1];
			for (int i = 0; i <= Num1; i++) a[i] = i;
		
			cout << "РЕШЕТО ЭРАТОСФЕНА: " << endl;
			if (Sieve_of_eratosthenes(a, Num1, Num))cout << "Число простое" << endl;
			else cout << "Число составное" << endl;
			delete[] a; 
		}
	}
	catch (const char* exception) 
	{
		cerr << "Error: " << exception << '\n';
	}
	return 0;
}
