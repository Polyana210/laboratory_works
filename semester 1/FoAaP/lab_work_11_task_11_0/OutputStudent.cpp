#include "header.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <locale.h>
#include <cctype>

using namespace std;

// ============ Вывод информации о студенте на экран ===========
void OutputStudent(STUDENT Student)
{
	setlocale(LC_ALL, "rus");
	cout.width(8);
	cout.fill('0');
	cout << Student.Number << " "
		<< Student.LastName << " "
		<< Student.FirstName[0] << ". "
		<< Student.MiddleName[0] << ".\n";
}

