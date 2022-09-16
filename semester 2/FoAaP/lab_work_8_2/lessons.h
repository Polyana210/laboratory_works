#ifndef LESSONS_H
#define LESSONS_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

// --------- �������� ���������� ���� ������ ���� -----------
class LESSON {
	int Number;            // ����� ����
	string LastName;       // ������� �������������
	string FirstName;      // ��� �������������
	string MiddleName;     // �������� �������������
	string LessonName;     // �������� ��������
  // ������������� ������� - ���������
	friend ostream& operator << (ostream& out, LESSON Lesson);
	friend istream& operator >> (istream& in, LESSON& Lesson);
	friend bool operator < (LESSON les1, LESSON les2);
};

// --------- �������� ���������� ���� ������ ���� ------------
class DAY {
	string Name;              // �������� ��� ������
	vector<LESSON> Lesson;    // ��������� (������) ���
public:
	void sort();              // ������������ ������ ���������
  // ������������� ������� - ���������
	friend ostream& operator << (ostream& out, DAY Day);
	friend istream& operator >> (istream& in, DAY& Day);
};
// =============== ����� ������������� �����  ==================
#endif

