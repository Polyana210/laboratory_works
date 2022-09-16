#ifndef LESSONS_H
#define LESSONS_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

// --------- описание объектного типа данных УРОК -----------
class LESSON {
	int Number;            // Номер пары
	string LastName;       // Фамилия преподавателя
	string FirstName;      // Имя преподавателя
	string MiddleName;     // Отчество преподавателя
	string LessonName;     // название предмета
  // дружественные функции - операторы
	friend ostream& operator << (ostream& out, LESSON Lesson);
	friend istream& operator >> (istream& in, LESSON& Lesson);
	friend bool operator < (LESSON les1, LESSON les2);
};

// --------- описание объектного типа данных ДЕНЬ ------------
class DAY {
	string Name;              // Название дня недели
	vector<LESSON> Lesson;    // Контейнер (вектор) пар
public:
	void sort();              // Упорядочение списка студентов
  // дружественные функции - операторы
	friend ostream& operator << (ostream& out, DAY Day);
	friend istream& operator >> (istream& in, DAY& Day);
};
// =============== конец заголовочного файла  ==================
#endif

