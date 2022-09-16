#ifndef STUDENTS_H
#define STUDENTS_H
#include <string>

 // ------- �������� ������������ ���� ������ ���� -----------
struct LESSON {
	char LastName[25];       // ������� �������������
	char FirstName[25];      // ��� �������������
	char MiddleName[25];     // �������� �������������
	char LessonName[25];     // �������� ����������
};

#define MAX_LESSON 10

// ------- �������� ������������ ���� ������ ���� -----------
struct DAY {
	char Name[11];             // �������� ��� ������
	int N;                 // ���������� ���
	LESSON* Lesson;          // ������ �������
};

#endif