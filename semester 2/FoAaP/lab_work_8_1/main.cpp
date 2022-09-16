/***************************************************************
  * ����     : main.cpp                                         *
  * �������� : ������� ���� ������� �������������� �������      *
 *            �� ������ ����������� ����������� � ����������   *
  ***************************************************************/
#include <iostream>
#include <fstream>
#include <windows.h>
#include "students.h"
#include "iostudent.h"
int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    try {
        char FileName[100];
        cout << "�� ������ ����� ������� ������?\n";
        cin.getline(FileName, sizeof(FileName));
        GROUP Group;
        // ������� ����� ��� ����� ������ �� �����
        ifstream fin(FileName);
        if (fin.is_open()) {
            // ��������� ������ �� ����� ������
            fin >> Group;
            // ������� �����
            fin.close();
            // ����������� ������
            Group.sort();
            // ������� ������ � ����� cout (�� �����)
            cout << Group;
            cout << "� ����� ���� �������� ������?\n";
            cin.getline(FileName, sizeof(FileName));
            // ������� ����� ��� ������ ������ � ����
            ofstream fout(FileName);
            if (fout.is_open())
            {
                // �������� ������ � ���� ����
                fout << Group;
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
    } catch (const char* exception)
    {
        std::cerr << "Error: " << exception << '\n';
    }
    return 0;
}
// ===================== ����� ��������� =======================
