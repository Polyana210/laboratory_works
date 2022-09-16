#include "iolesson.h"
#include <iterator>
using namespace std;

bool Check_123(string b, int k, int n) {
    if (atoi(b.c_str()) > n || atoi(b.c_str()) < k) { throw  "Неккоректный ввод"; }
    for (int i = 0; i < b.size(); i++) {
        if (b[i] < '0' || b[i] > '9') {
            throw "Неккоректный ввод";
        }
    }
    return 1;
}

// ======= Ввод информации о студенте из входного потока =======
istream& operator >> (istream& in, LESSON& lesson)
{
    string Numbetr;
    in >> Numbetr;
    Check_123(Numbetr, 0, 10);
    lesson.Number = atoi(Numbetr.c_str());

    in >> lesson.LessonName;   // Фамилия преподавателя
    in >> lesson.FirstName;    // Имя преподавателя
    in >> lesson.MiddleName;   // Отчество преподавателя
    in >> lesson.LastName;     // Название дисциплины
    return in;
}

// ======= Вывод информации о уроке в выходной поток ========
ostream& operator <<(ostream& out, LESSON Lesson)
{
    setlocale(LC_ALL, "rus");
    out << Lesson.Number << ") "
        << Lesson.LessonName << " "
        << Lesson.FirstName << " "
        << Lesson.MiddleName[0] << ". "
        << Lesson.LastName[0] << ". ";
    return out;
}

// ======= Ввод информации о группе из входного потока =========
istream& operator >> (istream& in, DAY& Day) {
    in >> Day.Name;
    Day.Lesson.clear();
    // ввод списка студентов с использованием итераторов
    istream_iterator<LESSON> in_iter(in);
    istream_iterator<LESSON> in_end;
    while (in_iter != in_end) {
        LESSON les = *in_iter;
         Day.Lesson.push_back(les);
        in_iter++;
    }
    return in;
}

// ====== Вывод информации о группе в выходной поток ===========
ostream& operator << (ostream& out, DAY Day) {
    out << " Расписание на  " << Day.Name << endl;
    // вывод списка студентов с использованием итераторов
    vector<LESSON>::iterator iter;
    iter = Day.Lesson.begin();
    while (iter != Day.Lesson.end()) {
        out << *iter << endl;
        iter++;
    }
    return out;
}

// ====================== конец модуля =========================

