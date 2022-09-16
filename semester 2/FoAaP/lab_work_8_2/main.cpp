/*������� 2. ������������ �������������� ������� � ������������ � ���������
�������. ���������� ������� ��� �����, ������ ������, ������������ �� ����������
��������, ������������ ������ ������.

10. ���������� �������: ���� ������, ����� ����, ��������
����������, ������� �.�. �������������. ����������� �� ����������� ������
����. ����������� ���������� �� ��������� ���� ������.*/
#include <iostream>
#include <fstream>
#include <windows.h>
#include "lessons.h"
#include "iolesson.h"
int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    try {
        char FileName[100];
        cout << "�� ������ ����� ������� ������?\n";
        cin.getline(FileName, sizeof(FileName));
        DAY Day;
        // ������� ����� ��� ����� ������ �� �����
        ifstream fin(FileName);
        if (fin.is_open()) {
            // ��������� ���� �� ����� ������
            fin >> Day;
            // ������� �����
            fin.close();
            // ����������� ����
            Day.sort();
            // ������� ���� � ����� cout (�� �����)
            cout << Day;
            cout << "� ����� ���� �������� ������?\n";
            cin.getline(FileName, sizeof(FileName));
            // ������� ����� ��� ������ ������ � ����
            ofstream fout(FileName);
            if (fout.is_open())
            {
                // �������� ������ � ���� ����
                fout << Day;
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
    }
    catch (const char* exeption) {
        cerr << "ERROR:" << exeption << '\n';;
    }
    return 0;
}
// ===================== ����� ��������� =======================
