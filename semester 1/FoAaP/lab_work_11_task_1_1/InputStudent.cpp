#include <iostream>
#include <windows.h>
#include <string>
#include <locale.h>
#include <cctype>
#include "Header.h"
using namespace std;

STUDENT InputStudent(void)
{
	setlocale(LC_ALL, "rus");
	STUDENT student;
	cout << "Введите фамилию (русскими буквами, не более 15 символов) ====> ";
	cin >> student.LastName;
	if (student.LastName.size() > 15) { cout << "Неккоректный ввод" << endl; exit(-1); }
	for (int i = 0; i < student.LastName.size(); i++) {
		if ('я' < student.LastName[i] || student.LastName[i] < 'А') {
			cout << "Неккоректный ввод" << endl; exit(-1);
		}
	}
	cout << "Введите имя (русскими буквами, не более 15 символов) ========> ";
	cin >> student.FirstName;
	if (student.FirstName.size() > 15) { cout << "Неккоректный ввод" << endl; exit(-1); }
	for (int i = 0; i < student.FirstName.size(); i++) {
		if ('я' < student.FirstName[i] || student.FirstName[i] < 'А') {
			cout << "Неккоректный ввод" << endl; exit(-1);
		}
	}
	cout << "Введите отчество (русскими буквами, не более 15 символов) ===> ";
	cin >> student.MiddleName;
	if (student.FirstName.size() > 15) { cout << "Неккоректный ввод" << endl; exit(-1); }
	for (int i = 0; i < student.MiddleName.size(); i++) {
		if ('я' < student.MiddleName[i] || student.MiddleName[i] < 'А') {
			cout << "Неккоректный ввод" << endl;	exit(-1);
		}
	}
	cout << "Введите номер  студенческого билета (натуральное число, не превышающее 8 знаков)===> ";
	cin >> student.Number;
	if (student.Number.size() > 8 || student.Number.size() <= 0) { cout << "Неккоректный ввод" << endl; exit(-1); }
	for (int i = 0; i < student.Number.size(); i++) {
		if (student.Number[i] < '0' || student.Number[i] > '9') {
			cout << "Неккоректный ввод" << endl;	 exit(-1);
		}
	}
	return student;
}
