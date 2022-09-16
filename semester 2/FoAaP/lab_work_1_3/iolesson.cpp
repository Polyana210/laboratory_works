#include "iolesson.h"

  // ======= Ввод информации о уроке из входного потока =======
istream& operator >> (istream& in, LESSON& lesson)
{
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
    out << Lesson.LessonName << " "
        << Lesson.FirstName << " "
        << Lesson.MiddleName[0] << ". "
        << Lesson.LastName[0] << ".\n";
    return out;
}

// ======= Ввод информации о дне из входного потока =========
istream& operator >>(istream& in, DAY& Day)
{
    in >> Day.Name;
    in >> Day.N;
    int Num = Day.N;
    Day.Lesson = new LESSON[Num];
    for (int i = 0; i < Num; i++)
    {
        in >> Day.Lesson[i];
    }
    return in;
}


// ====== Вывод информации о дне в выходной поток ===========
ostream& operator <<(ostream& out, DAY Day)
{
    out << " Расписание на  "<< Day.Name <<endl;

        for (int i = 0; i < Day.N; i++) {
        out << i + 1 << ". " << Day.Lesson[i];
    }
        return out;
}
// ====================== конец модуля =========================
