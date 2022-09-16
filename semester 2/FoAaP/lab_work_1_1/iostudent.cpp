/***************************************************************
  * Файл     : iostudent.cpp                                    *
  * Описание : реализация функций для организации потокового    *
 *            ввода-вывода переменных структурных типов        *
 *            данных STUDENT (Студент) и GROUP (Группа)        *
  ***************************************************************/
#include "iostudent.h"
  // ======= Ввод информации о студенте из входного потока =======
STUDENT ReadStudent(istream& in)
{
    STUDENT student;
    in >> student.LastName;
    in >> student.FirstName;
    in >> student.MiddleName;
    in >> student.Number;
    return student;
}
// ======= Вывод информации о студенте в выходной поток ========
ostream& WriteStudent(ostream& out, STUDENT Student)
{
    out.width(8);
    out.fill('0');
    out << Student.Number << " "
        << Student.LastName << " "
        << Student.FirstName[0] << ". "
        << Student.MiddleName[0] << ".\n";
    return out;
}
// ======= Ввод информации о группе из входного потока =========
istream&  ReadGroup(istream& in, GROUP* Group)
{
    in >> Group->Name;
    in >> Group->N;
    Group->Student = new STUDENT[Group->N];
    for (int i = 0; i < Group->N; i++)
    {
        Group->Student[i] = ReadStudent(in);
    }
    return in;
}

// ====== Вывод информации о группе в выходной поток ===========
void WriteGroup(ostream& out, GROUP Group)
{
    out << "Список группы " << Group.Name << endl;
    for (int i = 0; i < Group.N; i++) WriteStudent(out, Group.Student[i]);
}
// ====================== конец модуля =========================
