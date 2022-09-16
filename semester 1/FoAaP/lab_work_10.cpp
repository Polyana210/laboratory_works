/***************************************************************
 *                                                             *
 * Файл     : students.cpp                                     *
 *                                                             *
 * Описание : пример программы для обработки структурных типов *
 *            данных STUDENT (Студент) и GROUP (Группа)        *
 *                                                             *
 ***************************************************************/

#include <iostream>
#include <windows.h>
#include <string>
#include <locale.h>
#include <cctype>
using namespace std;
 // ================ описание типов данных ======================

 // ------- описание структурного типа данных СТУДЕНТ -----------
struct STUDENT {
	string LastName;     // Фамилия
	string FirstName;    // Имя
	string MiddleName;   // Отчество
	string Number;            // Номер студенческого билета
};

// ------- описание структурного типа данных ГРУППА ------------
// максимальное количество студентов в группе
#define MAX_STUDENT 30
struct GROUP {
	string Name;          // Название группы
	string N;                 // Количество студентов
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

// =============== основная функция программы ==================

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	GROUP Group;
	InputGroup(&Group);
	OutputGroup(Group);

	return 0;
}

// ============ Ввод информации о студенте с клавиатуры ========
STUDENT InputStudent(void)
{
	setlocale(LC_ALL, "rus");
	STUDENT student;
	cout << "Введите фамилию (русскими буквами, не более 15 символов) ====> ";
	cin >> student.LastName;
	if (student.LastName.size() > 15) { cout << "Неккоректный ввод" << endl; exit(-1); }
	for (int i = 0; i < student.LastName.size(); i++) {
		if ('я' < student.LastName[i] || student.LastName[i] < 'А') {
			 cout << "Неккоректный ввод" << endl; exit(-1);
		}
	}
	cout << "Введите имя (русскими буквами, не более 15 символов) ========> ";
	cin >> student.FirstName;
	if (student.FirstName.size() > 15) { cout << "Неккоректный ввод" << endl; exit(-1); }
	for (int i = 0; i < student.FirstName.size(); i++) {
		if ('я' < student.FirstName[i] || student.FirstName[i] < 'А') {
			 cout << "Неккоректный ввод" << endl; exit(-1);
		}
	}
	cout << "Введите отчество (русскими буквами, не более 15 символов) ===> ";
	cin >> student.MiddleName;
	if (student.FirstName.size() > 15) { cout << "Неккоректный ввод" << endl; exit(-1); }
	for (int i = 0; i < student.MiddleName.size(); i++) {
		if ('я' < student.MiddleName[i] || student.MiddleName[i] < 'А') {
			cout << "Неккоректный ввод" << endl;	exit(-1);
		}
	}
	cout << "Введите номер  студенческого билета (натуральное число, не превышающее 8 знаков)===> ";
	cin >> student.Number;
	if (student.Number.size() > 8 || student.Number.size() <= 0) { cout << "Неккоректный ввод" << endl; exit(-1); }
	for (int i = 0; i < student.Number.size(); i++) {
		if (student.Number[i] < '0' || student.Number[i] > '9') {
			cout << "Неккоректный ввод" << endl;	 exit(-1);
		}
	}
	return student;
}

// ============ Вывод информации о студенте на экран ===========
void OutputStudent(STUDENT Student)
{
	setlocale(LC_ALL, "rus");
	cout.width(8);
	cout.fill('0');
	cout << Student.Number << " "
		<< Student.LastName << " "
		<< Student.FirstName[0] << ". "
		<< Student.MiddleName[0] << ".\n";
}

// ============ Ввод информации о группе с клавиатуры ==========
void InputGroup(GROUP *Group)
{
	cout << "Введите название группы (цифры и русские буквы, не превышающее 5 знаков) ===> ";
	cin >> Group->Name;
	if (Group->Name.size()>5){ cout << "Неккоректный ввод" << endl; exit(-1); }
	for (int i = 0; i < Group->Name.size(); i++) {
		if (Group->Name[i] < '0' || Group->Name[i] > '9') {
			if (Group->Name[i] < 'А' || Group->Name[i] > 'я') {
				cout << "Неккоректный ввод" << endl;	 exit(-1);
			}
		}
	}

	cout << "Введите количество студентов (натуральное число, не более "
		<< MAX_STUDENT << ") ===> ";
	cin >> Group->N;
	if(atoi(Group->N.c_str())> 30 || atoi(Group->N.c_str())<0) { cout << "Неккоректный ввод" << endl; exit(-1); }
	for (int i = 0; i < Group->N.size(); i++) {
		if (Group->N[i] < '0' || Group->N[i] > '9') {
			cout << "Неккоректный ввод" << endl;	 exit(-1);
		}
	}
	for (int i = 0; i < atoi(Group->N.c_str()); i++)
	{
		cout << "Введите информацию о " << (i + 1) << "-ом студенте\n";
		Group->Student[i] = InputStudent();
	}
}

// ============ Вывод информации о группе на экран =============
void OutputGroup(GROUP Group)
{
	cout << "Список группы " << Group.Name << "\n";
	for (int i = 0; i < atoi(Group.N.c_str()); i++) OutputStudent(Group.Student[i]);
}

// ===================== конец программы =======================
