#include <iostream>
#include <string>
#include "header.h"
using namespace std;
// ============ ����� ���������� � ������ �� ����� =============
void OutputGroup(GROUP Group)
{
	cout << "������ ������ " << Group.Name << "\n";
	for (int i = 0; i < atoi(Group.N.c_str()); i++) OutputStudent(Group.Student[i]);
}

