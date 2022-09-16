#ifndef IOLESSON_H
#define IOLESSON_H
#include <iostream>
#include "lessons.h"
using namespace std;
#include <string>

// Ввод информации о уроке из входного потока
istream& operator >> (istream& in, LESSON& lesson);
// Вывод информации о уроке в выходной поток
ostream& operator <<(ostream& out, LESSON Lesson);
// Ввод информации о дне из входного потока
istream& operator >>(istream& in, DAY& Day);
// Вывод информации о дне в выходной поток
ostream& operator <<(ostream& out, DAY Day);
#endif
// =============== конец заголовочного файла  ==================

#pragma once
