/***************************************************************
  * ����     : iostudent.h                                      *
  * �������� : ������������ ����, ����������� �������           *
 *            ��� ����������� ���������� �����-������          *
 *            ���������� ����������� ����� ������              *
 *            STUDENT (�������) � GROUP (������)               *
  ***************************************************************/
#ifndef IOSTUDENT_H
#define IOSTUDENT_H
#include <iostream>
#include "students.h"
using namespace std;
  // ���� ���������� � �������� �� �������� ������
STUDENT ReadStudent(istream& in);
// ����� ���������� � �������� � �������� �����
ostream& WriteStudent(ostream& out, STUDENT Student);
// ���� ���������� � ������ �� �������� ������
istream& ReadGroup(istream& in, GROUP* Group);
// ����� ���������� � ������ � �������� �����
void WriteGroup(ostream& out, GROUP Group);
#endif
// =============== ����� ������������� �����  ==================

