#pragma once
// ------- описание структурного типа данных СТУДЕНТ -----------
struct STUDENT {
	std:: string LastName;     // Фамилия
	std::string FirstName;    // Имя
	std::string MiddleName;   // Отчество
	std::string Number;            // Номер студенческого билета
};

// ------- описание структурного типа данных ГРУППА ------------
// максимальное количество студентов в группе
#define MAX_STUDENT 30
struct GROUP {
	std::string Name;          // Название группы
	std::string N;                 // Количество студентов
	STUDENT Student[MAX_STUDENT];  // Массив студентов
};

// =============== описание прототипов функций =================

// Ввод информации о студенте с клавиатуры
STUDENT InputStudent(void);

// Вывод информации о студенте на экран
void OutputStudent(STUDENT Student);

// Ввод информации о группе с клавиатуры
void InputGroup(GROUP *Group);

// Вывод информации о группе на экран
void OutputGroup(GROUP Group);