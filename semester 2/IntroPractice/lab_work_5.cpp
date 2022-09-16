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
class slova {
    string Stroka;
    int N;
};

void Task1() {
    cout << " 9.86) Дана последовательность слов" << endl
        << " Проверить правильность написания жи/ши " << endl;
    char s[1000000];
    cout << "Введите строку: " << endl;
    cin.get(s, 1000000);
    int i = 0;
    int k = 0;
    while (s[i] != '\0') {
        if (s[i] == 'ж' || s[i] == 'Ж' || s[i] == 'ш' || s[i] == 'Ш') {
            i++;
            if (s[i] != '\0') {
                if (s[i] == 'ы' || s[i] == 'Ы') k++;
            }
        }
        i++;
    }
    if (k != 0) {
        cout << "Есть ошибки в написании "; exit(0);
    }
    else{ cout << "Ошибок нет "; exit(0);
    }
    cin.get(); cin.get();

}
class Predlozenie{
    string Stroka;
    int N;
};

void Task2() {
    cout << " 9.173) Дано предложение. Напечатать его самое длинное слово. " << endl
        << " Принять, что такое слово единственное. " << endl;
    char s[1000000];
    cout << "Введите строку: " << endl;
    cin.get(s, 1000000);
    int slovo;
    int k1 = 0, k2 = 0;
    int i = 0; int j=0;
    while (s[i] == ' ' && s[i] != '\0')
        i++;
    slovo = 0;
    while (s[i] != '\0') {
        if (s[i] != ' ' && slovo == 0)
        {
            slovo = 1;
        }
        else if (s[i] == ' ') {
            slovo = 0;
            if (k1 > k2) {
                k2 = k1; j = i - k1;
            } k1 = 0;
        }
        if (slovo == 1)k1++;
        i++;
    } 
    int k3;
    cout << "Cамое длинное слово в строке: ";
    if (k1 > k2) k3 = k1; else k3 = k2;
    for (int m = j; m <= k3 + j; m++) {
        cout << s[m];
    }
    cout << endl;
    cin.get(); cin.get();

}

class Triangle {
    double a;
    double b;
    double c;
};

bool check_triangle(double A, double B, double C) {
    double temp;
    if (B > A && B >= C) { temp = A; A = B; B = temp; }
    if (C > A && C >= B) { temp = A; A = C; C = temp; }
    if (A >= B + C) throw "Треугольника не существует";
    return true;
}
double S(double A, double B, double C, double p) {
    int S; p = p / 2;
    S = sqrt(p * ( p - A) * (p - B) * (p - C));
    return S;
}

void Task3() {
    string S1;
    double A, B, C;
    double A1, B1, C1;
    cout << " Даны стороны двух треугольников. Найти сумму их периметров и площадей " << endl;
    cout << " Введите стороны первого треугольника ";
    cout << "  a1 = ";
    cin >> S1;
    Check_123(S1, 0, 10000);
    A = stod(S1);
    cout << "  b1 = ";
    cin >> S1;
    Check_123(S1, 0, 10000);
    B = stod(S1);
    cout << "  c1 = ";
    cin >> S1;
    Check_123(S1, 0, 10000);
    C = stod(S1);
    check_triangle(A, B, C);
    cout << " Введите стороны второго треугольника ";
    cout << "  a2 = ";
    cin >> S1;
    Check_123(S1, 0, 10000);
    A1 = stod(S1);
    cout << "  b2 = ";
    cin >> S1;
    Check_123(S1, 0, 10000);
    B1 = stod(S1);
    cout << "  c2 = ";
    cin >> S1;
    Check_123(S1, 0, 10000);
    C1 = stod(S1);
    check_triangle(A1, B1, C1);
    double p1 = A + B + C;
    double p2 = A1 + B1 + C1;
    cout << " Сумма периметров равна " << p1 + p2 << endl;
    cout << " Сумма площадей равна " << S(A, B, C, p1) + S(A1, B1, C1, p2) << endl;     
}

int main() {
    try {
        setlocale(LC_ALL, "rus");

        SetConsoleCP(1251);
        SetConsoleOutputCP(1251); 
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
