#include <windows.h>
#include <iostream>
#include <string>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

// ====== Проверка на целое число  ===========
bool Check_Num(string b, int k, int n) {
    if (atoi(b.c_str()) > n || atoi(b.c_str()) < k) { throw  "Неккоректный ввод"; }
    int i = 0;
    if (b[0] == '-')  i = 1;
    for (i; i < b.size(); i++) {
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

class Array {
    int arr[5];
};

void Task1() {
    cout << " 11.73) Дан массив целых чисел. Определить количество четных элементов " << endl
        << " Определить количество элементов, заканчивающихся на 5 " << endl;

    string S;
    cout << " Введите количество элементов ";
    cin >> S;
    Check_Num(S, 1, 1000); 
    int N = atoi(S.c_str());
    int* Arr = new int[N];
    for (int i = 0; i < N; i++) {
        cout << " Введите a[" << i << "] = ";
        cin >> S;
        Check_Num(S, -10000, 10000);
        Arr[i] = atoi(S.c_str());
    }

    double chet = 0, d5=0;
    for (int i = N - 1; i >= 0; i--) {
        if (Arr[i] % 2 == 0) chet++;
        if (Arr[i] % 5 == 0 && Arr[i] % 10 != 0) d5++;
    }
    cout << " Количество четных элементов: " << chet << endl;
    cout << " Количество элементов, заканчивающихся на 5: " << d5 << endl;
    delete[] Arr;
}

class Array1
{
    int arr1[15];
}; 

void Task2() {
    cout << " 11.189) Дан массив целых чисел. Напечатать все элементы, следующие за последним элементом, оканчивающимся на 7" << endl
        << " Если элементов, оканчивающихся на 7 нет, то ни одно число не должно быть напечатано " << endl;

    string S;
    cout << " Введите количество элементов ";
    cin >> S;
    Check_Num(S, 1, 1000);
    int N = atoi(S.c_str());
    int* Arr = new int[N];
    for (int i = 0; i < N; i++) {
        cout << " Введите a[" << i << "] = ";
        cin >> S;
        Check_Num(S, -10000, 10000);
        Arr[i] = stod(S);
    }

    int ch = -1;
    for (int i = N - 1; i >= 0; i--) {
        if ((Arr[i] / 10) * 10 + 7 == Arr[i]) { ch = i; break; }
    }
    for (int i = ch+1; i <N; i++) {
        cout << Arr[i]<< " ";
    }
    if (ch == -1) cout << "нет таких элементов";
    delete[] Arr;
}

class parallelepiped {
    double a;
    double b;
    double c;
};

void Task3() {
    cout << " 11.234 а) размеры 15 параллепипедов хранятся в трех массивах " << endl
        << " Определить максимальный объем фигуры: " << endl;
    double a[15], b[15], c[15];
    string S;
    for (int i = 0; i < 15; i++) {
        cout << " Введите размеры " << i + 1 << " параллелепипеда: " << endl;
        cout << " a = ";
        cin >> S;
        Check_123(S, 0, 10000);
        a[i] = stod(S);
        cout << " b = ";
        cin >> S;
        Check_123(S, 0, 10000);
        b[i] = stod(S);
        cout << " c = ";
        cin >> S;
        Check_123(S, 0, 10000);
        c[i] = stod(S);
    }

    // использованием доп. массива
    double max=0;
    double v[15];
    for (int i = 0; i < 15; i++) {
        v[i] = a[i] * b[i] * c[i];
        if (v[i] > max)max = v[i];
    }
    cout << "C использованием дополнительного массива максимальный объем равен "<< max << endl;
    // без использования доп. массива
    for (int i = 0; i < 15; i++) {
        if (a[i] * b[i] * c[i] > max) max = a[i] * b[i] * c[i];
    }

    cout << "Без использования дополнительного массива максимальный объем равен "<< max << endl;
}

int main() {
    try {
        setlocale(LC_ALL, "rus");

        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
         //Task1();
        // Task2();
         Task3();
    }

    catch (const char* exception)
    {
        std::cerr << "Error: " << exception << '\n';
    }
    return 0;
}
