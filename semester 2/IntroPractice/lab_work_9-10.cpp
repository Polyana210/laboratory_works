/*9. Год. Определить иерархию года. Создать несколько объектов-месяцев.
Собрать год. Провести сортировку месяцев в году на основе средней температуры. 
Найти месяц в году, соответствующий заданному диапазону температур. */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <windows.h>
using namespace std;

class gro1up {               // Контейнер (вектор) месяцев
public:
    virtual double podchet() = 0;
    virtual void sort() = 0;// Упорядочение списка месяцев
};

class MONTH {
    string Name;   //имя месяца
    double tem;      //средняя температура
public:
   
    double get_tem()
    {
        return tem;
    }
    friend ostream& operator << (ostream& out, MONTH Month);
    friend istream& operator >> (istream& in, MONTH& Month);
    friend bool operator < (MONTH rat1, MONTH rat2);
};

class GROUP :public gro1up {
    string Name;
    vector <MONTH> Month;
public:
    void sort() {
        std::sort(this->Month.begin(), this->Month.end());
    }
    double podchet() {
        double Sum = 0;
        for (unsigned i = 0; i < Month.size(); i++) {
            Sum += Month[i].get_tem();
        }
        return Sum/12;
    }

    void poisk_mes(int min, int max) {
        cout << " Месяца, соответствующие требованиям: " << endl;
        int y = 0;
        for (unsigned i = 0; i < Month.size(); i++) {
            if (Month[i].get_tem() >= min && Month[i].get_tem() <= max) { cout << Month[i] << endl; y++; }
        }
        if (y == 0)cout << "НЕ НАЙДЕНО";
    }
    friend ostream& operator << (ostream& out, GROUP Group);
    friend istream& operator >> (istream& in, GROUP& Group);
};


// Сравниваем по средней температуре
bool operator < (MONTH rat1, MONTH rat2) {
    bool result = rat1.get_tem() < rat2.get_tem();
    return result;
}

bool Check_ABC(string b, int n) {
    if (b.size() > n ) { throw  "Неккоректный ввод"; }
    for (int i = 0; i < b.size(); i++) {
        if ('я' < b[i] || b[i] < 'А') {
            throw  "Неккоректный ввод";
        }
    }
    return 1;
}
// ====== Проверка на целое число  ===========
bool Check_NUM(string b, int k, int n) {
    if (atoi(b.c_str()) > n || atoi(b.c_str()) < k) { throw  "Неккоректный ввод"; }
    for (int i = 0; i < b.size(); i++) {
        if (b[i] < '0' || b[i] > '9') {
            throw "Неккоректный ввод";
        }
    }
    return 1;
}

// ====== Проверка на дробное число  ===========
bool Check_123(string b, int k, int n) {
    if (stod(b) > n || stod(b) <= k) { throw  "Неккоректный ввод"; }
    int i = 0;
    if (b[0] == '-')  i = 1;
    int count = 0;
    for (i; i < b.size(); i++) {
        if (b[i] < '0' || b[i] > '9') {
            if (b[i] != '.') {
                throw "Неккоректный ввод";
            }
        }
        if (b[i] == '.')count++;
    }
    if (count > 1)throw "Неккоректный ввод";
    return 1;
}

// ====== Ввод информации о авто  ===========
istream& operator >> (istream& in, MONTH& Month) {
    string S;
    in >> S;
    Check_ABC(S, 9);
   // if(S !="Январь" && S != "январь" && S != "февраль" && S != "Февраль" && S != "Март" && S != "март" && S != "Март" && S != "апрель" && S != "Апрель" && S != "май" && S != "Май" && S != "июнь" && S != "Июнь" && S != "июль" && S != "Июль" && S != "август" && S != "Август" && S != "сентябрь" && S != "Сентябрь" && S != "октябрь" && S != "Октябрь" && S != "ноябрь" && S != "Ноябрь" && S != "декабрь" && S != "Декабрь") throw "Неккоректный ввод";
    Month.Name=S;
    in >> S;
    if (S != "") {
        Check_123(S, -80, 80);
        Month.tem = stod(S.c_str());
    }
    return in;
}

// ====== Вывод информации о авто  ===========
ostream& operator << (ostream& out, MONTH Month) {
    out << Month.Name << ": "
        << Month.tem << " град. Цельсия";
    return out;
}

// ====== Ввод информации компании  ===========
istream& operator >> (istream& in, GROUP& Group) {
    string S;
    in >> S;
    Check_NUM(S, 0, 2022);
    Group.Name = S;
    Group.Month.clear();
    istream_iterator<MONTH> in_iter(in);
    istream_iterator<MONTH> in_end;
    while (in_iter != in_end) {
        MONTH rate = *in_iter;
        Group.Month.push_back(rate);
        in_iter++;
    }
    return in;
}

// ====== Вывод информации о компании  ===========
ostream& operator << (ostream& out, GROUP Group) {
    out << "Год " << Group.Name << endl;
    out << "Средняя годовая температура: " << Group.podchet() << endl;
    vector<MONTH>::iterator iter;
    iter = Group.Month.begin();
    while (iter != Group.Month.end()) {
        out << *iter << endl;
        iter++;
    }
    return out;
}



int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    try {
        char FileName[100];
        cout << "Из какого файла вводить данные?\n";
        cin.getline(FileName, sizeof(FileName));
        GROUP Group;
        ifstream fin(FileName);
        if (fin.is_open()) {
            fin >> Group;
            fin.close();
            Group.sort();
            cout << Group;
            cout << "В какой файл выводить данные?\n";
            cin.getline(FileName, sizeof(FileName));
            ofstream fout(FileName);
            if (fout.is_open())
            {
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

        int plata_min;
        int plata_max;
        cout << "Введите начало диапазона средней температуры: ";
        cin >> plata_min;
        cout << "Введите конец диапазона средней температуры: ";
        cin >> plata_max;
        Group.poisk_mes(plata_min, plata_max);


        Sleep(7654);
    }
    catch (const char* exception)
    {
        std::cerr << "Error: " << exception << '\n';
    }
    return 0;
}

