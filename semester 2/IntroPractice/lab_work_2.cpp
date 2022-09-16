#include <windows.h>
#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

class Year {
    double Num;
};

class Chisla {
    double N1;
    double N2; 
    double N3;
};

class Triangle {
    double a;
    double b;
    double c;
};

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
    if (atoi(b.c_str()) > n || atoi(b.c_str()) <= k) { throw  "Неккоректный ввод"; }
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

int Year(int S) {
    if (S % 4 == 0) {
        if (S % 100 == 0 && S % 400 != 0) {
            cout << "Не высокосный 365 дней"; return 365;
        }
        cout << "Высокосный 366 дней"; return 366;
    }
    else {
        cout << "Не высокосный 365 дней";
        return 365;
    }
}

void Task1() {
    string S;
    cout << " Дан номер года. Определить количество дней в этом году. " << endl;
    cout << " Введите номер года" << endl;
    cin >> S;
    Check_Num(S, 0, 2022);
    Year(atoi(S.c_str()));
}

void Task2() {
    string S1;
    string S2;
    string S3;
    cout << " Даны три вещеcтвенных числа. Возвести в квадрат те из них, которые неотрицательны " << endl;
    cout << " Введите первое число" << endl;
    cin >> S1;
    Check_123(S1, -10000, 10000);
    cout << " Введите второе число" << endl;
    cin >> S2;
    Check_123(S2, -10000, 10000);
    cout << " Введите третье число" << endl;
    cin >> S3;
    Check_123(S3, -10000, 10000);
    if (S1[0] != '-') {
        double n = stod(S1);
        cout << "N1^2 =" << n * n << endl;
    }
    if (S2[0] != '-') {
        double n1 = stod(S2);
        cout << "N2^2 =" << n1 * n1 << endl;
    }
    if (S3[0] != '-') {
        double n2 = stod(S3);
        cout << "N3^2 =" << n2 * n2 << endl;
    }
}

void Task3() {
    string S1;
    string S2;
    string S3;
    cout << " Даны три вещеcтвенных числа a, b, c. Определить является ли треугольник со сторонами a, b, c прямоугольным " << endl;
    cout << " Введите число a = ";
    cin >> S1;
    Check_123(S1, 0, 10000);
    cout << " Введите число b = ";
    cin >> S2;
    Check_123(S2, 0, 10000);
    cout << " Введите число c = ";
    cin >> S3;
    Check_123(S3, 0, 10000);
    double A, B, C;
    A = stod(S1);
    B = stod(S2);
    C = stod(S3);
    double temp;
    if (B > A && B >= C) { temp = A; A = B; B = temp; }
    if (C > A && C >= B) { temp = A; A = C; C = temp; }
    if (A >= B + C) throw "Треугольника не существует";
    A = A * A;
    B = B * B;
    C = C * C;
    if (A == B + C) cout << " Треугольник прямоугольный"; else cout << " Треугольник не прямоугольный";
}

int main() {
    try {
        setlocale(LC_ALL, "rus");
       // Task1();
        // Task2();
        Task3();
    }

    catch (const char* exception)
    {
        std::cerr << "Error: " << exception << '\n';
    }
    return 0;
}
