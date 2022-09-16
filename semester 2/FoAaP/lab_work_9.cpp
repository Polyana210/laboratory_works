/*9.	Таксопарк. Определить иерархию легковых автомобилей. Создать таксопарк.
Рассчитать стоимость автопарка. Провести сортировку автомобилей парка по расходу топлива. 
Найти автомобиль в компании, соответствующий заданному диапазону параметров скорости.*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <windows.h>
using namespace std;

class gro1up {               // Контейнер (вектор) автомобилей
public:
    virtual int podchet() = 0; 
    virtual void sort() = 0;// Упорядочение списка автомобилей
};

class RATE {
    string Name; //имя вида
    double Toplivo; //расход топлива
    int num_avto; //количество автомобилей такого вида
    int n;     //стоимость одного автомобиля
    int speed; //скорость
public:
    int get_num_avto() {
        return num_avto;
    }
    int get_plata() {
        return Toplivo;
    }

    int get_stoimost()
    {
        return n;
    }

    int get_speed()
    {
        return speed;
    }
    friend ostream& operator << (ostream& out, RATE Rates);
    friend istream& operator >> (istream& in, RATE& Rates);
    friend bool operator < (RATE rat1, RATE rat2);
};

class GROUP:public gro1up {
    string Name;
    vector <RATE> Rates;
public:
     void sort() {
         std::sort(this->Rates.begin(), this->Rates.end());
     } 
     int podchet() {
         int Sum=0;
         for (unsigned i = 0; i < Rates.size(); i++) {
             Sum += Rates[i].get_num_avto() * Rates[i].get_stoimost();
         }
         return Sum;
    }

     void poisk_tarifa(int min, int max) {
         cout << " Автомобили, соответствующие требованиям: " << endl;
         int y = 0;
         for (unsigned i = 0; i < Rates.size(); i++) {
             if (Rates[i].get_speed() >= min && Rates[i].get_speed() <= max) { cout << Rates[i]<<endl; y++; }
         }
         if (y == 0)cout << "НЕ НАЙДЕНО";
     }
    friend ostream& operator << (ostream& out, GROUP Group);
    friend istream& operator >> (istream& in, GROUP& Group);
};


// Сравниваем по расходу топлива
bool operator < (RATE rat1, RATE rat2) {
    bool result = rat1.Toplivo < rat2.Toplivo;
    return result;
}

// ====== Проверка на целое число  ===========
bool Check_123(string b, int k, int n) {
    if (atoi(b.c_str()) > n || atoi(b.c_str()) < k) { throw  "Неккоректный ввод"; }
    for (int i = 0; i < b.size(); i++) {
        if (b[i] < '0' || b[i] > '9') {
            throw "Неккоректный ввод";
        }
    }
    return 1;
}

// ====== Ввод информации о авто  ===========
istream& operator >> (istream& in, RATE& Rates) {
    string Numbetr;
    in >> Rates.Name;
    in >> Rates.n;
    in >> Rates.num_avto;
    in >> Rates.speed;
    in >> Numbetr;
    Check_123(Numbetr, 0, 99999999);
    Rates.Toplivo = atoi(Numbetr.c_str());
    return in;
}

// ====== Вывод информации о авто  ===========
ostream& operator << (ostream& out, RATE Rates) {
    out << Rates.Name << ": "
        << Rates.Toplivo << " литров/100км   "
        << Rates.num_avto << " автомобилей  "
        << Rates.speed << " км/ч  "
        << Rates.n << " тыс долларов  ";
    return out;
}

// ====== Ввод информации компании  ===========
istream& operator >> (istream& in, GROUP& Group) {
    in >> Group.Name;
    Group.Rates.clear();
    istream_iterator<RATE> in_iter(in);
    istream_iterator<RATE> in_end;
    while (in_iter != in_end) {
        RATE rate = *in_iter;
        Group.Rates.push_back(rate);
        in_iter++;
    }
    return in;
}

// ====== Вывод информации о компании  ===========
ostream& operator << (ostream& out, GROUP Group) {
    out << "Таксопарк " << Group.Name << endl;
    out << "Общая стоимость: " << Group.podchet() << endl;
    // вывод списка студентов с использованием итераторов
    vector<RATE>::iterator iter;
    iter = Group.Rates.begin();
    while (iter != Group.Rates.end()) {
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
        cout << "Введите начало диапазона максимальной скорости: ";
        cin >> plata_min;
        cout << "Введите конец диапазона максимальной скорости: ";
        cin >> plata_max;
        Group.poisk_tarifa(plata_min, plata_max);


        Sleep(7654);
    } catch (const char* exception)
    {
        std::cerr << "Error: " << exception << '\n';
    }
    return 0;
}

