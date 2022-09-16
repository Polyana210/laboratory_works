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
	cout << "������� ������� (�������� �������, �� ����� 15 ��������) ====> ";
	cin >> student.LastName;
	if (student.LastName.size() > 15) { cout << "������������ ����" << endl; exit(-1); }
	for (int i = 0; i < student.LastName.size(); i++) {
		if ('�' < student.LastName[i] || student.LastName[i] < '�') {
			cout << "������������ ����" << endl; exit(-1);
		}
	}
	cout << "������� ��� (�������� �������, �� ����� 15 ��������) ========> ";
	cin >> student.FirstName;
	if (student.FirstName.size() > 15) { cout << "������������ ����" << endl; exit(-1); }
	for (int i = 0; i < student.FirstName.size(); i++) {
		if ('�' < student.FirstName[i] || student.FirstName[i] < '�') {
			cout << "������������ ����" << endl; exit(-1);
		}
	}
	cout << "������� �������� (�������� �������, �� ����� 15 ��������) ===> ";
	cin >> student.MiddleName;
	if (student.FirstName.size() > 15) { cout << "������������ ����" << endl; exit(-1); }
	for (int i = 0; i < student.MiddleName.size(); i++) {
		if ('�' < student.MiddleName[i] || student.MiddleName[i] < '�') {
			cout << "������������ ����" << endl;	exit(-1);
		}
	}
	cout << "������� �����  ������������� ������ (����������� �����, �� ����������� 8 ������)===> ";
	cin >> student.Number;
	if (student.Number.size() > 8 || student.Number.size() <= 0) { cout << "������������ ����" << endl; exit(-1); }
	for (int i = 0; i < student.Number.size(); i++) {
		if (student.Number[i] < '0' || student.Number[i] > '9') {
			cout << "������������ ����" << endl;	 exit(-1);
		}
	}
	return student;
}
