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

void Input(double** arrayPtr, int n, int m) {
    string s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout  << i + 1 << " магазин " << j + 1 << " день  ";
            cin >> s;
            Check_123(s, 0, 10000);
            arrayPtr[i][j]= atoi(s.c_str());
        }
    }
}
// очистка памяти
void Delete(double** arrayPtr, int n, int m) {
    for (int i = 0; i < n; i++) {
        delete[]arrayPtr[i];
    }
    delete[]arrayPtr;
}

// вывод матрицы
void Output(double** arrayPtr, int n, int m) {
  /*  cout << setw(5) << "          ";
    for (int j = 1; j <= m; j++) {
        cout << setw(6) << j;
    }*/
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(5) <<"Магазин " << i+1;
        for (int j = 0; j < m; j++) {
            cout << setw(5) << arrayPtr[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

class Num {
    int a;
};

void Task1() {
    cout << " Даны натуральное число m и целые числа a1, a2, ..., am." << endl
        << " Выяснить, верно ли что количество тех ai, которые больше m, кратно целому числу p " << endl;
    string s;
    cout << " Введите число m = ";
    cin >> s;
    Check_Num(s, 1, 1000);
    int m = atoi(s.c_str());
    int* Arr = new int[m];
    int count = 0;
    for (int i = 0; i < m; i++) {
        cout << " a" << i + 1 << " = ";
        cin >> s;
        Check_Num(s, -10000, 10000);
        Arr[i] = atoi(s.c_str());
        if (Arr[i] > m) count++;
    }
    cout << " Введите число p = ";
    cin >> s;
    Check_Num(s, -1000, 1000);
    int p = atoi(s.c_str());
    if (p == 0)throw "Неккоректный ввод";
    if ((count / p) * p == count) cout << " Утверждение верно "; else cout << " Утверждение неверно ";
    delete[] Arr;
}

class shop {
    int days;
    int count;
};

void Task2() {
    cout << " Фирма имеет 3 магазина. Известен доход каждого в каждый из 10 дней" << endl
        << " Организовать ввод информации по таблице и определить: " << endl
        << " a) Для каждого магазина день максимального дохода " << endl
        << " б) Для каждого дня магазин с максимальным доходом " << endl;
    double** matrix = new  double* [3];
    for (int i = 0; i < 3; i++) {
        matrix[i] = new double[10];
    }
    Input(matrix, 3, 10);
    Output(matrix, 3, 10);

    double max1 = 0, max2 = 0;
    for (int i = 0; i < 3; i++) {
        cout << setw(5) << " Магазин " << i + 1 << " - день с максимальной прибылью: ";
        for (int j = 0; j < 10; j++) {
            if (matrix[i][j] > max1) {
                max1 = matrix[i][j]; max2 = j + 1;
          };
        }
        cout << max2<< endl;
        max1 = 0; max2 = 0;
    }

    for (int j = 0; j < 10; j++) {
        cout << setw(5) << "День" << j + 1 << " - магазин с максимальной прибылью: ";
        for (int i = 0; i < 3; i++) {
            if (matrix[i][j] > max1) {
                max1 = matrix[i][j]; max2 = i+ 1;
            };
        }
        cout << max2 << endl;
        max1 = 0; max2 = 0;
    }

}

class sentences {
    string s;
    int n;
};

void Task3() {
    cout << " Определить количество слов в строке" << endl;
    char s[16000];
    int slovo, count = 0;
    cout << " Введите строку: " << endl;
    cin.get(s, 16000);
    int i = 0;
    while (s[i] == ' ' && s[i] != '\0')
        i++;
    slovo = 0;
    while (s[i] != '\0') {
        if (s[i] != ' ' && slovo == 0)
        {
            slovo = 1;
            count++;
        }
        else if (s[i] == ' ')
            slovo = 0;
        i++;
    }
    cout << " Количество слов в строке " << count<< endl;
    cin.get(); cin.get();

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
