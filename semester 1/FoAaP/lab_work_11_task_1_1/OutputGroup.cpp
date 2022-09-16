#include <iostream>
#include <windows.h>
#include <string>
#include <locale.h>
#include <cctype>
#include "Header.h"
using namespace std;

void OutputGroup(GROUP Group)
{
	cout << "Список группы " << Group.Name << "\n";
	for (int i = 0; i < atoi(Group.N.c_str()); i++) OutputStudent(Group.Student[i]);
}
