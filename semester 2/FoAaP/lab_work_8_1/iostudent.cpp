/***************************************************************
  * ����     : iostudent.cpp                                    *
  * �������� : ���������� ���������� ��� ����������� ���������� *
 *            �����-������ ���������� ��������� �����          *
 *            ������ STUDENT (�������) � GROUP (������)        *
 *                                                             *
 ***************************************************************/
#include "iostudent.h"
#include "string"
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
istream& operator >> (istream& in, STUDENT& Student) {
    string Numbetr;
    in >> Student.LastName;
    in >> Student.FirstName;
    in >> Student.MiddleName;
    in >> Numbetr;
    Check_123(Numbetr, 0, 99999999);
    Student.Number = atoi(Numbetr.c_str());
    return in;
}
// ======= ����� ���������� � �������� � �������� ����� ========
ostream& operator << (ostream& out, STUDENT Student) {
    // ��������������� ����� ����� �������
    out.width(8);
    out.fill('0');
    out << Student.Number << " "
        << Student.LastName << " "
        << Student.FirstName[0] << ". "
        << Student.MiddleName[0] << ".";
    return out;
}
// ======= ���� ���������� � ������ �� �������� ������ =========
istream& operator >> (istream& in, GROUP& Group) {
    in >> Group.Name;
    Group.Students.clear();
    // ���� ������ ��������� � �������������� ����������
    istream_iterator<STUDENT> in_iter(in);
    istream_iterator<STUDENT> in_end;
    while (in_iter != in_end) {
        STUDENT stud = *in_iter;
        Group.Students.push_back(stud);
        in_iter++;
    }
    return in;
}
// ====== ����� ���������� � ������ � �������� ����� ===========
ostream& operator << (ostream& out, GROUP Group) {
    out << "������ ������ " << Group.Name << endl;
    // ����� ������ ��������� � �������������� ����������
    vector<STUDENT>::iterator iter;
    iter = Group.Students.begin();
    while (iter != Group.Students.end()) {
        out << *iter << endl;
        iter++;
    }
    return out;
}
// ====================== ����� ������ =========================

