#include "iolesson.h"
#include <iterator>
using namespace std;

bool Check_123(string b, int k, int n) {
    if (atoi(b.c_str()) > n || atoi(b.c_str()) < k) { throw  "������������ ����"; }
    for (int i = 0; i < b.size(); i++) {
        if (b[i] < '0' || b[i] > '9') {
            throw "������������ ����";
        }
    }
    return 1;
}

// ======= ���� ���������� � �������� �� �������� ������ =======
istream& operator >> (istream& in, LESSON& lesson)
{
    string Numbetr;
    in >> Numbetr;
    Check_123(Numbetr, 0, 10);
    lesson.Number = atoi(Numbetr.c_str());

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
    out << Lesson.Number << ") "
        << Lesson.LessonName << " "
        << Lesson.FirstName << " "
        << Lesson.MiddleName[0] << ". "
        << Lesson.LastName[0] << ". ";
    return out;
}

// ======= ���� ���������� � ������ �� �������� ������ =========
istream& operator >> (istream& in, DAY& Day) {
    in >> Day.Name;
    Day.Lesson.clear();
    // ���� ������ ��������� � �������������� ����������
    istream_iterator<LESSON> in_iter(in);
    istream_iterator<LESSON> in_end;
    while (in_iter != in_end) {
        LESSON les = *in_iter;
         Day.Lesson.push_back(les);
        in_iter++;
    }
    return in;
}

// ====== ����� ���������� � ������ � �������� ����� ===========
ostream& operator << (ostream& out, DAY Day) {
    out << " ���������� ��  " << Day.Name << endl;
    // ����� ������ ��������� � �������������� ����������
    vector<LESSON>::iterator iter;
    iter = Day.Lesson.begin();
    while (iter != Day.Lesson.end()) {
        out << *iter << endl;
        iter++;
    }
    return out;
}

// ====================== ����� ������ =========================

