#include "iolesson.h"

  // ======= Ввод информации о уроке из входного потока =======
LESSON ReadLesson(istream& in)
{
    LESSON lesson;
    in >> lesson.LessonName;     // Фамилия преподавателя
    in >> lesson.FirstName;    // Имя преподавателя
    in >> lesson.MiddleName;   // Отчество преподавателя
    in >> lesson.LastName;   // Название дисциплины
    return lesson;
}
// ======= Вывод информации о уроке в выходной поток ========
ostream& WriteLesson(ostream& out, LESSON Lesson)
{
    setlocale(LC_ALL, "rus");
    out << Lesson.LessonName << " "
        << Lesson.FirstName << " "
        << Lesson.MiddleName[0] << ". "
        << Lesson.LastName[0] << ".\n";
    return out;
}

// ======= Ввод информации о дне из входного потока =========
istream& ReadDay(istream& in, DAY* Day)
{
    in >> Day->Name;
    in >> Day->N;
    int Num = Day->N;
    Day-> Lesson = new LESSON[Num];
    for (int i = 0; i < Num; i++)
    {
        Day->Lesson[i] = ReadLesson(in);
    }
    return in;
}


// ====== Вывод информации о дне в выходной поток ===========
void WriteDay(ostream& out, DAY Day)
{
    out << " Расписание на  "<< Day.Name<<endl;

        for (int i = 0; i < Day.N; i++) {
        cout << i + 1 << ". ";  WriteLesson(out, Day.Lesson[i]);
    }
}
// ====================== конец модуля =========================
