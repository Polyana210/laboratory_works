#ifndef IOSTUDENT_H
#define IOSTUDENT_H
/***************************************************************
  * ����     : iostudent.h                                      *
  * �������� : ������������ ����, ����������� ���������         *
 *            ��� ����������� ���������� �����-������          *
 *            ���������� ��������� ����� ������                *
 *            STUDENT (�������) � GROUP (������)               *
  ***************************************************************/
#include "students.h"
  // ���� ���������� � �������� �� ������
istream& operator >> (istream& in, STUDENT& Student);
// ����� ���������� � �������� � �������� �����
ostream& operator << (ostream& out, STUDENT Student);
// ���� ���������� � ������ �� �������� ������
istream& operator >> (istream& in, GROUP& Group);
// ����� ���������� � ������ � �������� �����
ostream& operator << (ostream& out, GROUP Group);

bool Check_123(string b, int k, int n);
// =============== ����� ������������� �����  ==================
#endif
