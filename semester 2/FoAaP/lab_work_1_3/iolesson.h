#ifndef IOLESSON_H
#define IOLESSON_H
#include <iostream>
#include "lessons.h"
using namespace std;
#include <string>

// ���� ���������� � ����� �� �������� ������
istream& operator >> (istream& in, LESSON& lesson);
// ����� ���������� � ����� � �������� �����
ostream& operator <<(ostream& out, LESSON Lesson);
// ���� ���������� � ��� �� �������� ������
istream& operator >>(istream& in, DAY& Day);
// ����� ���������� � ��� � �������� �����
ostream& operator <<(ostream& out, DAY Day);
#endif
// =============== ����� ������������� �����  ==================

#pragma once
