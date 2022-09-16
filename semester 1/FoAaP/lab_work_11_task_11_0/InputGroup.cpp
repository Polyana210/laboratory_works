#include "header.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <locale.h>
#include <cctype>

using namespace std;

// ============ ���� ���������� � ������ � ���������� ==========
void InputGroup(GROUP *Group)
{
	cout << "������� �������� ������ (����� � ������� �����, �� ����������� 5 ������) ===> ";
	cin >> Group->Name;
	if (Group->Name.size() > 5) { cout << "������������ ����" << endl; exit(-1); }
	for (int i = 0; i < Group->Name.size(); i++) {
		if (Group->Name[i] < '0' || Group->Name[i] > '9') {
			if (Group->Name[i] < '�' || Group->Name[i] > '�') {
				cout << "������������ ����" << endl;	 exit(-1);
			}
		}
	}

	cout << "������� ���������� ��������� (����������� �����, �� ����� "
		<< MAX_STUDENT << ") ===> ";
	cin >> Group->N;
	if (atoi(Group->N.c_str()) > 30 || atoi(Group->N.c_str()) < 0) { cout << "������������ ����" << endl; exit(-1); }
	for (int i = 0; i < Group->N.size(); i++) {
		if (Group->N[i] < '0' || Group->N[i] > '9') {
			cout << "������������ ����" << endl;	 exit(-1);
		}
	}
	for (int i = 0; i < atoi(Group->N.c_str()); i++)
	{
		cout << "������� ���������� � " << (i + 1) << "-�� ��������\n";
		Group->Student[i] = InputStudent();
	}
}

