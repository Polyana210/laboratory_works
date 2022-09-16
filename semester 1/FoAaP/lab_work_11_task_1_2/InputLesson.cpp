#include <iostream>
#include <windows.h>
#include <string>
#include <locale.h>
#include <cctype>
#include "Header.h"
using namespace std;


LESSON InputLesson(void)
{
	setlocale(LC_ALL, "rus");
	LESSON lesson;
	cout << "������� �������� ���������� (�������� �������, �� ����� 35 ��������, ��� ��������) ======> ";
	cin >> lesson.LessonName;
	if (lesson.LessonName.size() > 35) { cout << "������������ ����" << endl; exit(-1); }
	for (int i = 0; i < lesson.LessonName.size(); i++) {
		if ('�' < lesson.LessonName[i] || lesson.LessonName[i] < '�') {
			cout << "������������ ����" << endl;	exit(-1);
		}
	}
	cout << "������� ������� �������������  (�������� �������, �� ����� 15 ��������) ===> ";
	cin >> lesson.LastName;
	if (lesson.LastName.size() > 15) { cout << "������������ ����" << endl; exit(-1); }
	for (int i = 0; i < lesson.LastName.size(); i++) {
		if ('�' < lesson.LastName[i] || lesson.LastName[i] < '�') {
			cout << "������������ ����" << endl; exit(-1);
		}
	}
	cout << "������� ��� �������������  (�������� �������, �� ����� 15 ��������) =======> ";
	cin >> lesson.FirstName;
	if (lesson.FirstName.size() > 15) { cout << "������������ ����" << endl; exit(-1); }
	for (int i = 0; i < lesson.FirstName.size(); i++) {
		if ('�' < lesson.FirstName[i] || lesson.FirstName[i] < '�') {
			cout << "������������ ����" << endl; exit(-1);
		}
	}
	cout << "������� �������� ������������� (�������� �������, �� ����� 15 ��������) ===> ";
	cin >> lesson.MiddleName;
	if (lesson.FirstName.size() > 15) { cout << "������������ ����" << endl; exit(-1); }
	for (int i = 0; i < lesson.MiddleName.size(); i++) {
		if ('�' < lesson.MiddleName[i] || lesson.MiddleName[i] < '�') {
			cout << "������������ ����" << endl;	exit(-1);
		}
	}

	return lesson;
}
