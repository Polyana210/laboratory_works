#ifndef STUDENTS_H
#define STUDENTS_H
#include <string>

 // ------- описание структурного типа данных УРОК -----------
struct LESSON {
	char LastName[25];       // Фамилия преподавателя
	char FirstName[25];      // Имя преподавателя
	char MiddleName[25];     // Отчество преподавателя
	char LessonName[25];     // Название дисциплины
};

#define MAX_LESSON 10

// ------- описание структурного типа данных ДЕНЬ -----------
struct DAY {
	char Name[11];             // Название дня недели
	int N;                 // Количество пар
	LESSON* Lesson;          // Массив занятий
};

#endif