/***************************************************************
  * Файл     : main.cpp                                         *
  * Описание : главный файл проекта для демонстрации            *
 *            потокового ввода-вывода структурных типов        *
 *            данных STUDENT (Студент) и GROUP (Группа)        *
***************************************************************/


/*Задание 1. Изучите пример обработки структурных типов данных.Подготовьте
приложение, убедитесь в его работоспособности.*/


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
    cout << "Из какого файла вводить данные?\n";
    cin.getline(FileName, sizeof(FileName));
    GROUP Group;
    // создать поток для ввода данных из файла
    ifstream fin(FileName);
    if (fin.is_open()) {
        // прочитать группу из этого потока
        ReadGroup(fin, &Group);
        // закрыть поток
        fin.close();
        // вывести группу в поток cout (на экран)
        WriteGroup(cout, Group);
        cout << "В какой файл выводить данные?\n";
        cin.getline(FileName, sizeof(FileName));
        // создать поток для вывода данных в файл
        ofstream fout(FileName);
        if (fout.is_open())
        {
            // записать группу в этот файл
            WriteGroup(fout, Group);
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
    return 0;
}
// ===================== конец программы =======================
