#include <iostream>
#include <windows.h>
#include <string>
#include <locale.h>
#include <cctype>
#include "Header.h"
using namespace std;

void OutputDay(DAY Day)
{
	cout << "\n –асписание на ";
	if (atoi(Day.Name.c_str()) == 1) cout << "понедельник:" << endl;
	if (atoi(Day.Name.c_str()) == 2) cout << "вторник:" << endl;
	if (atoi(Day.Name.c_str()) == 3) cout << "среду:" << endl;
	if (atoi(Day.Name.c_str()) == 4) cout << "четверг:" << endl;
	if (atoi(Day.Name.c_str()) == 5) cout << "п€тницу:" << endl;
	if (atoi(Day.Name.c_str()) == 6) cout << "субботу:" << endl;
	if (atoi(Day.Name.c_str()) == 7) cout << "воскресенье:" << endl;
	for (int i = 0; i < atoi(Day.N.c_str()); i++) {
		cout << i + 1 << ". "; OutputLesson(Day.Lesson[i]);
	}
}