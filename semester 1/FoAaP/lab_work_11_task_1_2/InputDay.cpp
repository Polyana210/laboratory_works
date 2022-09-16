#include <iostream>
#include <windows.h>
#include <string>
#include <locale.h>
#include <cctype>
#include "Header.h"
using namespace std;

void InputDay(DAY *Day)
{
	cout << "Введите номер дня недели (от 1 до 7) =======================> ";
	cin >> Day->Name;
	if (Day->Name.size() != 1) { cout << "Неккоректный ввод" << endl; exit(-1); }
	for (int i = 0; i < Day->Name.size(); i++) {
		if (Day->Name[i] < '1' || Day->Name[i] > '7') {
			cout << "Неккоректный ввод" << endl;	 exit(-1);
		}
	}

	cout << "Введите количество пар (натуральное число, не более "
		<< MAX_LESSON << ") ====> ";
	cin >> Day->N;
	if (atoi(Day->N.c_str()) > 10 || atoi(Day->N.c_str()) < 0) { cout << "Неккоректный ввод" << endl; exit(-1); }
	for (int i = 0; i < Day->N.size(); i++) {
		if (Day->N[i] < '0' || Day->N[i] > '9') {
			cout << "Неккоректный ввод" << endl;	 exit(-1);
		}
	}
	for (int i = 0; i < atoi(Day->N.c_str()); i++)
	{
		cout << "Введите информацию о " << (i + 1) << "-ой паре\n";
		Day->Lesson[i] = InputLesson();
	}
}