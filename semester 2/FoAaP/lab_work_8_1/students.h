#ifndef STUDENTS_H
#define STUDENTS_H
/***************************************************************
  * ����     : students.h                                       *
* �������� : ������������ ����, ����������� ��������� ����    *
 *            ������ STUDENT (�������) � GROUP (������)        *
  ***************************************************************/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// --------- �������� ���������� ���� ������ ������� -----------
class STUDENT {
	string LastName;       // �������
	string FirstName;      // ���
	string MiddleName;     // ��������
	int Number;            // ����� �������������
  // ������������� ������� - ���������
	friend ostream& operator << (ostream& out, STUDENT Student);
	friend istream& operator >> (istream& in, STUDENT& Student);
	friend bool operator < (STUDENT stud1, STUDENT stud2);
};
// --------- �������� ���������� ���� ������ ������ ------------
class GROUP {
	string Name;              // �������� ������
	vector<STUDENT> Students; // ��������� (������) ���������
public:
	void sort();              // ������������ ������ ���������
  // ������������� ������� - ���������
	friend ostream& operator << (ostream& out, GROUP Group);
	friend istream& operator >> (istream& in, GROUP& Group);
};
// =============== ����� ������������� �����  ==================
#endif
