#ifndef IOSTUDENT_H
#define IOSTUDENT_H
#include <iostream>
#include "lessons.h"
using namespace std;
#include <string>

// ���� ���������� � ����� �� �������� ������
LESSON ReadLesson(istream& in);
// ����� ���������� � ����� � �������� �����
ostream& WriteLesson(ostream& out, LESSON lesson);
// ���� ���������� � ��� �� �������� ������
istream& ReadDay(istream& in, DAY* Day);
// ����� ���������� � ��� � �������� �����
void WriteDay(ostream& out, DAY Day);

#endif
// =============== ����� ������������� �����  ==================

