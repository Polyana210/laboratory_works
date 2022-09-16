#include "header.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <locale.h>
#include <cctype>

using namespace std;

// ============ Ввод информации о группе с клавиатуры ==========
void InputGroup(GROUP *Group)
{
	cout << "Введите название группы (цифры и русские буквы, не превышающее 5 знаков) ===> ";
	cin >> Group->Name;
	if (Group->Name.size() > 5) { cout << "Неккоректный ввод" << endl; exit(-1); }
	for (int i = 0; i < Group->Name.size(); i++) {
		if (Group->Name[i] < '0' || Group->Name[i] > '9') {
			if (Group->Name[i] < 'А' || Group->Name[i] > 'я') {
				cout << "Неккоректный ввод" << endl;	 exit(-1);
			}
		}
	}

	cout << "Введите количество студентов (натуральное число, не более "
		<< MAX_STUDENT << ") ===> ";
	cin >> Group->N;
	if (atoi(Group->N.c_str()) > 30 || atoi(Group->N.c_str()) < 0) { cout << "Неккоректный ввод" << endl; exit(-1); }
	for (int i = 0; i < Group->N.size(); i++) {
		if (Group->N[i] < '0' || Group->N[i] > '9') {
			cout << "Неккоректный ввод" << endl;	 exit(-1);
		}
	}
	for (int i = 0; i < atoi(Group->N.c_str()); i++)
	{
		cout << "Введите информацию о " << (i + 1) << "-ом студенте\n";
		Group->Student[i] = InputStudent();
	}
}

