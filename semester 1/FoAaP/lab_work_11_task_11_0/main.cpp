#include <iostream>
#include <windows.h>
#include <string>
#include <locale.h>
#include <cctype>
#include "header.h"
using namespace std;

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



