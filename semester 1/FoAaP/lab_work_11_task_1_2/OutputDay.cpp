#include <iostream>
#include <windows.h>
#include <string>
#include <locale.h>
#include <cctype>
#include "Header.h"
using namespace std;

void OutputDay(DAY Day)
{
	cout << "\n ���������� �� ";
	if (atoi(Day.Name.c_str()) == 1) cout << "�����������:" << endl;
	if (atoi(Day.Name.c_str()) == 2) cout << "�������:" << endl;
	if (atoi(Day.Name.c_str()) == 3) cout << "�����:" << endl;
	if (atoi(Day.Name.c_str()) == 4) cout << "�������:" << endl;
	if (atoi(Day.Name.c_str()) == 5) cout << "�������:" << endl;
	if (atoi(Day.Name.c_str()) == 6) cout << "�������:" << endl;
	if (atoi(Day.Name.c_str()) == 7) cout << "�����������:" << endl;
	for (int i = 0; i < atoi(Day.N.c_str()); i++) {
		cout << i + 1 << ". "; OutputLesson(Day.Lesson[i]);
	}
}