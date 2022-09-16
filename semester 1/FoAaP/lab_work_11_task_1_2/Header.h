#pragma once
#include <string>
using namespace std;

struct LESSON {
	string LastName;       // ������� �������������
	string FirstName;      // ��� �������������
	string MiddleName;     // �������� �������������
	string LessonName;     // �������� ����������
};

#define MAX_LESSON 10
struct DAY {
	string Name;          // �������� ��� ������
	string N;                 // ���������� ���
	LESSON Lesson[MAX_LESSON];  // ������ �������
};


LESSON InputLesson(void);
void OutputLesson(LESSON Lesson);
void InputDay(DAY *Day);
void OutputDay(DAY Day);
