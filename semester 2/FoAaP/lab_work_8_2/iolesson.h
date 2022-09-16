#ifndef IOLESSON_H
#define IOLESSON_H

#include "lessons.h"
  // Ввод информации о студенте из потока
 istream& operator >> (istream& in, LESSON& Lesson);
// Вывод информации о студенте в выходной поток
 ostream& operator << (ostream& out, LESSON Lesson);
// Ввод информации о группе из входного потока
 istream& operator >> (istream& in, DAY& Day);
// Вывод информации о группе в выходной поток
 ostream& operator << (ostream& out, DAY Day);
// =============== конец заголовочного файла  ==================
 bool Check_123(string b, int k, int n);
#endif
