/*Задание 2. Разработайте информационную систему в соответствии с вариантом
задания. Реализуйте функции для ввода, вывода данных, упорядочения по некоторому
признаку, формирования нового списка.

10. РАСПИСАНИЕ ЗАНЯТИЙ: день недели, номер пары, название
дисциплины, Фамилия И.О. преподавателя. Упорядочьте по возрастанию номера
пары. Сформируйте расписание на указанный день недели.*/
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
        cout << "Из какого файла вводить данные?\n";
        cin.getline(FileName, sizeof(FileName));
        DAY Day;
        // создать поток для ввода данных из файла
        ifstream fin(FileName);
        if (fin.is_open()) {
            // прочитать день из этого потока
            fin >> Day;
            // закрыть поток
            fin.close();
            // упорядочить день
            Day.sort();
            // вывести день в поток cout (на экран)
            cout << Day;
            cout << "В какой файл выводить данные?\n";
            cin.getline(FileName, sizeof(FileName));
            // создать поток для вывода данных в файл
            ofstream fout(FileName);
            if (fout.is_open())
            {
                // записать группу в этот файл
                fout << Day;
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
    }
    catch (const char* exeption) {
        cerr << "ERROR:" << exeption << '\n';;
    }
    return 0;
}
// ===================== конец программы =======================
