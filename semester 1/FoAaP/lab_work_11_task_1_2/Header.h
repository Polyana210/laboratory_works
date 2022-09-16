#pragma once
#include <string>
using namespace std;

struct LESSON {
	string LastName;       // Фамилия преподавателя
	string FirstName;      // Имя преподавателя
	string MiddleName;     // Отчество преподавателя
	string LessonName;     // Название дисциплины
};

#define MAX_LESSON 10
struct DAY {
	string Name;          // Название дня недели
	string N;                 // Количество пар
	LESSON Lesson[MAX_LESSON];  // Массив занятий
};


LESSON InputLesson(void);
void OutputLesson(LESSON Lesson);
void InputDay(DAY *Day);
void OutputDay(DAY Day);
