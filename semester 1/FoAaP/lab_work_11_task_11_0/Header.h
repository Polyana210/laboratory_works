#pragma once
// ------- �������� ������������ ���� ������ ������� -----------
struct STUDENT {
	std:: string LastName;     // �������
	std::string FirstName;    // ���
	std::string MiddleName;   // ��������
	std::string Number;            // ����� ������������� ������
};

// ------- �������� ������������ ���� ������ ������ ------------
// ������������ ���������� ��������� � ������
#define MAX_STUDENT 30
struct GROUP {
	std::string Name;          // �������� ������
	std::string N;                 // ���������� ���������
	STUDENT Student[MAX_STUDENT];  // ������ ���������
};

// =============== �������� ���������� ������� =================

// ���� ���������� � �������� � ����������
STUDENT InputStudent(void);

// ����� ���������� � �������� �� �����
void OutputStudent(STUDENT Student);

// ���� ���������� � ������ � ����������
void InputGroup(GROUP *Group);

// ����� ���������� � ������ �� �����
void OutputGroup(GROUP Group);