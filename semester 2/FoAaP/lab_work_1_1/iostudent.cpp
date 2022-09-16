/***************************************************************
  * ����     : iostudent.cpp                                    *
  * �������� : ���������� ������� ��� ����������� ����������    *
 *            �����-������ ���������� ����������� �����        *
 *            ������ STUDENT (�������) � GROUP (������)        *
  ***************************************************************/
#include "iostudent.h"
  // ======= ���� ���������� � �������� �� �������� ������ =======
STUDENT ReadStudent(istream& in)
{
    STUDENT student;
    in >> student.LastName;
    in >> student.FirstName;
    in >> student.MiddleName;
    in >> student.Number;
    return student;
}
// ======= ����� ���������� � �������� � �������� ����� ========
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
// ======= ���� ���������� � ������ �� �������� ������ =========
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

// ====== ����� ���������� � ������ � �������� ����� ===========
void WriteGroup(ostream& out, GROUP Group)
{
    out << "������ ������ " << Group.Name << endl;
    for (int i = 0; i < Group.N; i++) WriteStudent(out, Group.Student[i]);
}
// ====================== ����� ������ =========================
