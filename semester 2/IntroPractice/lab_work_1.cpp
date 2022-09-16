#include <windows.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

class Kvadrat {
    double SQUARE;
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
    if (atoi(b.c_str()) > n || atoi(b.c_str()) < k) { throw  "Неккоректный ввод"; }
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

double Perimetr(double S) {
    double P;
    P = sqrt(S) * 4;
    cout << "Периметр квадрата равен " << P;
    return P;
}

double Task1() {
    cout << endl << "1.2.7.Площадь квадрата равна S кв.м.Найти периметр квадрата. " << endl;
    string S;
    cout << "Введите площадь квадрата: ";
    cin >> S;
    Check_123(S, 0, 10000);
    double n = std::stod(S);;
    return Perimetr(n);
}

void Summ_Proizv_Num(int N) {
    int Summ=0; int Proizv=1; int n;
    for (int i = 1; i <= 4; i++) {
        n = N % 10;
        N /= 10;
        Summ += n;
        Proizv *= n;
    }
    cout << endl << "Сумма цифр числа равна: " << Summ<< endl;
    cout << "Произведение цифр числа равно: " << Proizv << endl;
}

void Task2() {
    cout << endl << "Дано четырехзначное число. Найти сумму и произведение его цифр " << endl;
    string N;
    cout << "Введите четырехзначное число: ";
    cin >> N;
    Check_Num(N, 999, 9999);
    return Summ_Proizv_Num(atoi(N.c_str()));
}

void Task3() {
    cout << endl << "В трехзначном числе зачеркнули его вторую цифру."
        << endl << " К полученному двузначному числу приписали слева вычеркнутую цифру, получилось число n;  "
        << endl << " Найти исходное число " << endl;
    string N;
    cout << "Введите трехзначное число: ";
    cin >> N;
           Check_Num(N, 99, 999);
        int k = 0;
        k = N[1];
        N[1] = N[0];
        N[0] = k;
        cout << N;
    
}

int main() {
    try {
        setlocale(LC_ALL, "rus");
      // Task1();
       //Task2();
      Task3();
     

    }

catch (const char* exception)
{
    std::cerr << "Error: " << exception << '\n';
}
return 0;
}
