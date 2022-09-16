#ifndef STUDENTS_H
#define STUDENTS_H
/***************************************************************
  * Файл     : students.h                                       *
* Описание : заголовочный файл, описывающий объектные типы    *
 *            данных STUDENT (Студент) и GROUP (Группа)        *
  ***************************************************************/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// --------- описание объектного типа данных СТУДЕНТ -----------
class STUDENT {
	string LastName;       // Фамилия
	string FirstName;      // Имя
	string MiddleName;     // Отчество
	int Number;            // Номер студенческого
  // дружественные функции - операторы
	friend ostream& operator << (ostream& out, STUDENT Student);
	friend istream& operator >> (istream& in, STUDENT& Student);
	friend bool operator < (STUDENT stud1, STUDENT stud2);
};
// --------- описание объектного типа данных ГРУППА ------------
class GROUP {
	string Name;              // Название группы
	vector<STUDENT> Students; // Контейнер (вектор) студентов
public:
	void sort();              // Упорядочение списка студентов
  // дружественные функции - операторы
	friend ostream& operator << (ostream& out, GROUP Group);
	friend istream& operator >> (istream& in, GROUP& Group);
};
// =============== конец заголовочного файла  ==================
#endif
