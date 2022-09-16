#include "iolesson.h"

  // ======= ���� ���������� � ����� �� �������� ������ =======
istream& operator >> (istream& in, LESSON& lesson)
{
    in >> lesson.LessonName;   // ������� �������������
    in >> lesson.FirstName;    // ��� �������������
    in >> lesson.MiddleName;   // �������� �������������
    in >> lesson.LastName;     // �������� ����������
    return in;
}

// ======= ����� ���������� � ����� � �������� ����� ========
ostream& operator <<(ostream& out, LESSON Lesson)
{
    setlocale(LC_ALL, "rus");
    out << Lesson.LessonName << " "
        << Lesson.FirstName << " "
        << Lesson.MiddleName[0] << ". "
        << Lesson.LastName[0] << ".\n";
    return out;
}

// ======= ���� ���������� � ��� �� �������� ������ =========
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


// ====== ����� ���������� � ��� � �������� ����� ===========
ostream& operator <<(ostream& out, DAY Day)
{
    out << " ���������� ��  "<< Day.Name <<endl;

        for (int i = 0; i < Day.N; i++) {
        out << i + 1 << ". " << Day.Lesson[i];
    }
        return out;
}
// ====================== ����� ������ =========================
