#include "iolesson.h"

  // ======= ���� ���������� � ����� �� �������� ������ =======
LESSON ReadLesson(istream& in)
{
    LESSON lesson;
    in >> lesson.LessonName;     // ������� �������������
    in >> lesson.FirstName;    // ��� �������������
    in >> lesson.MiddleName;   // �������� �������������
    in >> lesson.LastName;   // �������� ����������
    return lesson;
}
// ======= ����� ���������� � ����� � �������� ����� ========
ostream& WriteLesson(ostream& out, LESSON Lesson)
{
    setlocale(LC_ALL, "rus");
    out << Lesson.LessonName << " "
        << Lesson.FirstName << " "
        << Lesson.MiddleName[0] << ". "
        << Lesson.LastName[0] << ".\n";
    return out;
}

// ======= ���� ���������� � ��� �� �������� ������ =========
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


// ====== ����� ���������� � ��� � �������� ����� ===========
void WriteDay(ostream& out, DAY Day)
{
    out << " ���������� ��  "<< Day.Name<<endl;

        for (int i = 0; i < Day.N; i++) {
        cout << i + 1 << ". ";  WriteLesson(out, Day.Lesson[i]);
    }
}
// ====================== ����� ������ =========================
