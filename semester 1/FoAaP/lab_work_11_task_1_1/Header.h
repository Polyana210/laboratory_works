#pragma once
#include <string>
using namespace std;
struct STUDENT {
	string LastName;     // Фамилия
	string FirstName;    // Имя
	string MiddleName;   // Отчество
	string Number;            // Номер студенческого билета
};


#define MAX_STUDENT 30
struct GROUP {
	string Name;          // Название группы
	string N;                 // Количество студентов
	STUDENT Student[MAX_STUDENT];  // Массив студентов
};


STUDENT InputStudent(void);
void OutputStudent(STUDENT Student);
void InputGroup(GROUP *Group);
void OutputGroup(GROUP Group);
