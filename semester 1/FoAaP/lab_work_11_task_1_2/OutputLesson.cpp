#include <iostream>
#include <windows.h>
#include <string>
#include <locale.h>
#include <cctype>
#include "Header.h"
using namespace std;

void OutputLesson(LESSON Lesson)
{
	setlocale(LC_ALL, "rus");

	cout << Lesson.LessonName << " "
		<< Lesson.LastName << " "
		<< Lesson.FirstName[0] << ". "
		<< Lesson.MiddleName[0] << ".\n";
}