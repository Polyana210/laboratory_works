#include <iostream>
#include <windows.h>
#include <string>
#include <locale.h>
#include <cctype>
#include "Header.h"
using namespace std;

void InputDay(DAY *Day)
{
	cout << "������� ����� ��� ������ (�� 1 �� 7) =======================> ";
	cin >> Day->Name;
	if (Day->Name.size() != 1) { cout << "������������ ����" << endl; exit(-1); }
	for (int i = 0; i < Day->Name.size(); i++) {
		if (Day->Name[i] < '1' || Day->Name[i] > '7') {
			cout << "������������ ����" << endl;	 exit(-1);
		}
	}

	cout << "������� ���������� ��� (����������� �����, �� ����� "
		<< MAX_LESSON << ") ====> ";
	cin >> Day->N;
	if (atoi(Day->N.c_str()) > 10 || atoi(Day->N.c_str()) < 0) { cout << "������������ ����" << endl; exit(-1); }
	for (int i = 0; i < Day->N.size(); i++) {
		if (Day->N[i] < '0' || Day->N[i] > '9') {
			cout << "������������ ����" << endl;	 exit(-1);
		}
	}
	for (int i = 0; i < atoi(Day->N.c_str()); i++)
	{
		cout << "������� ���������� � " << (i + 1) << "-�� ����\n";
		Day->Lesson[i] = InputLesson();
	}
}