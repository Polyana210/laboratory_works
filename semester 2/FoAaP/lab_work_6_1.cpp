/*Задание 1. Выполните задания с использованием библиотечного класса string.
Даны строка S, символ C и строка S0. Необходимо после каждого
вхождения символа C в строку S вставить строку S0. (Например, "пример", 'р', "сла" →
"прслаимерсла")
*/
#include <iostream>
#include <windows.h>
#include <string>
#include <locale.h>
using namespace std;


int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	
	string S;
	string C;
	string S0;
	try {
		cout << "Введите строку S (цифры и русские буквы, не превышающее 55 знаков) ===> ";
		cin >> S;
		if (S.size() > 55) { throw "Строка НЕ БОЛЕЕ 55 символов!!!"; exit(-1); }
		for (int i = 0; i < S.size(); i++) {
			if (S[i] < '0' || S[i] > '9') {
				if (S[i] < 'А' || S[i]  > 'я') {
					throw "Строка содержит недопустимые символы"; exit(-1);
				}
			}
		}

		cout << "Введите символ C (цифры и русские буквы, не превышающее 1 знака) ===> ";
		cin >> C;
		if (C.size() > 1) { throw "Строка НЕ БОЛЕЕ 1 знака!!!"; exit(-1); }
		for (int i = 0; i < C.size(); i++) {
			if (C[i] < '0' || C[i] > '9') {
				if (C[i] < 'А' || C[i] > 'я') {
					throw "Недопустимый символ"; exit(-1);
				}
			}
		}

		cout << "Введите строку S0 (цифры и русские буквы, не превышающее 55 знаков) ===> ";
		cin >> S0;
		if (S0.size() > 55) { throw "Строка НЕ БОЛЕЕ 55 символов!!!"; exit(-1); }
		for (int i = 0; i < S0.size(); i++) {
			if (S0[i] < '0' || S0[i] > '9') {
				if (S0[i] < 'А' || S0[i] > 'я') {
					throw "Строка содержит недопустимые символы"; exit(-1);
				}
			}
		}

		cout << "Строка, полученная из строки " << S << " подстановкой строки " << S0 << " после каждого вхождения символа " << C << endl;
		for (int i = 0; i < S.size(); i++) {
			cout << S[i];
			if (C[0] == S[i]) {
				cout << S0;
	     	}
	    }
		
    } 

		catch (const char* exception) 
		{
			std::cerr << "Error: " << exception << '\n';
		}
		return 0;
}