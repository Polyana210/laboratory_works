/***************************************************************
  * Файл     : main.cpp                                         *
  * Описание : главный файл примера информационной системы      *
 *            на основе стандартных контейнеров и алгоритмов   *
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
        cout << "Из какого файла вводить данные?\n";
        cin.getline(FileName, sizeof(FileName));
        GROUP Group;
        // создать поток для ввода данных из файла
        ifstream fin(FileName);
        if (fin.is_open()) {
            // прочитать группу из этого потока
            fin >> Group;
            // закрыть поток
            fin.close();
            // упорядочить группу
            Group.sort();
            // вывести группу в поток cout (на экран)
            cout << Group;
            cout << "В какой файл выводить данные?\n";
            cin.getline(FileName, sizeof(FileName));
            // создать поток для вывода данных в файл
            ofstream fout(FileName);
            if (fout.is_open())
            {
                // записать группу в этот файл
                fout << Group;
                fout.close();
                cout << "Данные выведены в файл " << FileName << endl;
            }
            else
            {
                cout << "Ошибка записи в файл " << FileName << endl;
            }
        }
        else
        {
            cout << "Файл " << FileName << " не найден\n";
        }
        Sleep(7654);
    } catch (const char* exception)
    {
        std::cerr << "Error: " << exception << '\n';
    }
    return 0;
}
// ===================== конец программы =======================
