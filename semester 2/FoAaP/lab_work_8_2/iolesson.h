#ifndef IOLESSON_H
#define IOLESSON_H

#include "lessons.h"
  // ���� ���������� � �������� �� ������
 istream& operator >> (istream& in, LESSON& Lesson);
// ����� ���������� � �������� � �������� �����
 ostream& operator << (ostream& out, LESSON Lesson);
// ���� ���������� � ������ �� �������� ������
 istream& operator >> (istream& in, DAY& Day);
// ����� ���������� � ������ � �������� �����
 ostream& operator << (ostream& out, DAY Day);
// =============== ����� ������������� �����  ==================
 bool Check_123(string b, int k, int n);
#endif
