/***************************************************************
  * Файл     : iostudent.h                                      *
  * Описание : заголовочный файл, описывающий функции           *
 *            для организации потокового ввода-вывода          *
 *            переменных структурных типов данных              *
 *            STUDENT (Студент) и GROUP (Группа)               *
  ***************************************************************/
#ifndef IOSTUDENT_H
#define IOSTUDENT_H
#include <iostream>
#include "students.h"
using namespace std;
  // Ввод информации о студенте из входного потока
STUDENT ReadStudent(istream& in);
// Вывод информации о студенте в выходной поток
ostream& WriteStudent(ostream& out, STUDENT Student);
// Ввод информации о группе из входного потока
istream& ReadGroup(istream& in, GROUP* Group);
// Вывод информации о группе в выходной поток
void WriteGroup(ostream& out, GROUP Group);
#endif
// =============== конец заголовочного файла  ==================

