#include <iostream>
#include <string>
#include "header.h"
using namespace std;
// ============ Вывод информации о группе на экран =============
void OutputGroup(GROUP Group)
{
	cout << "Список группы " << Group.Name << "\n";
	for (int i = 0; i < atoi(Group.N.c_str()); i++) OutputStudent(Group.Student[i]);
}

