#include <iostream>
#include <windows.h>
#include <string>
#include <locale.h>
#include <cctype>
#include "Header.h"
using namespace std;



int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	DAY Day;
	InputDay(&Day);
	OutputDay(Day);

	return 0;
}