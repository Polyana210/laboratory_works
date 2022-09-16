#pragma once
#include <string>
using namespace std;
struct STUDENT {
	string LastName;     // �������
	string FirstName;    // ���
	string MiddleName;   // ��������
	string Number;            // ����� ������������� ������
};


#define MAX_STUDENT 30
struct GROUP {
	string Name;          // �������� ������
	string N;                 // ���������� ���������
	STUDENT Student[MAX_STUDENT];  // ������ ���������
};


STUDENT InputStudent(void);
void OutputStudent(STUDENT Student);
void InputGroup(GROUP *Group);
void OutputGroup(GROUP Group);
