#ifndef IOSTUDENT_H
#define IOSTUDENT_H
#include <iostream>
#include "lessons.h"
using namespace std;
#include <string>

// Ввод информации о уроке из входного потока
LESSON ReadLesson(istream& in);
// Вывод информации о уроке в выходной поток
ostream& WriteLesson(ostream& out, LESSON lesson);
// Ввод информации о дне из входного потока
istream& ReadDay(istream& in, DAY* Day);
// Вывод информации о дне в выходной поток
void WriteDay(ostream& out, DAY Day);

#endif
// =============== конец заголовочного файла  ==================

