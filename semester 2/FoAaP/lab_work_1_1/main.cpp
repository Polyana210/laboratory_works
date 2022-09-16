/***************************************************************
  * ����     : main.cpp                                         *
  * �������� : ������� ���� ������� ��� ������������            *
 *            ���������� �����-������ ����������� �����        *
 *            ������ STUDENT (�������) � GROUP (������)        *
***************************************************************/


/*������� 1. ������� ������ ��������� ����������� ����� ������.�����������
����������, ��������� � ��� �����������������.*/


#include <iostream>
#include <fstream>
#include <windows.h>
#include "students.h"
#include "iostudent.h"
using namespace std;

int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char FileName[100];
    cout << "�� ������ ����� ������� ������?\n";
    cin.getline(FileName, sizeof(FileName));
    GROUP Group;
    // ������� ����� ��� ����� ������ �� �����
    ifstream fin(FileName);
    if (fin.is_open()) {
        // ��������� ������ �� ����� ������
        ReadGroup(fin, &Group);
        // ������� �����
        fin.close();
        // ������� ������ � ����� cout (�� �����)
        WriteGroup(cout, Group);
        cout << "� ����� ���� �������� ������?\n";
        cin.getline(FileName, sizeof(FileName));
        // ������� ����� ��� ������ ������ � ����
        ofstream fout(FileName);
        if (fout.is_open())
        {
            // �������� ������ � ���� ����
            WriteGroup(fout, Group);
            fout.close();
            cout << "������ �������� � ���� " << FileName << endl;
        }
        else
        {
            cout << "������ ������ � ���� " << FileName << endl;
        }
    }
    else
    {
        cout << "���� " << FileName << " �� ������\n";
    }
    Sleep(7654);
    return 0;
}
// ===================== ����� ��������� =======================
