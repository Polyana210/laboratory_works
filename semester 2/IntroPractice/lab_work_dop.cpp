#include <windows.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>  
#define _USE_MATH_DEFINES
#include <cmath>

#include "foo.h"

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


class shaxmati {
    char arr[8][8];
};
void Task1() {
    cout << " 3.35) Поле шахматной доски определяется парой натуральных чисел, каждое из которых не превосходит восьми :" << endl <<
        " первое число — номер вертикали(при счете слева направо), второе — номер горизонтали(при счете снизу вверх)." << endl <<
        " Даны натуральные числа а, b, с, d, е, каждое из которых не превосходит восьми" << endl <<
        " Записать условие, при котором белая фигура, расположенная на поле(а, b), может одним ходом пойти на поле(е, f), " << endl <<
        " не попав под удар черной фигуры, находящейся на поле(с,d).Рассмотреть варианты сочетаний белой и черной фигур" << endl <<
        " д) белая - ферзь, черная - ферзь" << endl <<
        " п) белая - слон, черная - конь" << endl;
    //int a, b, c, d, e, f;
    //srand(time(NULL));
    //a = 1 + rand() % 8;
    //b = 1 + rand() % 8;
    //c = 1 + rand() % 8;
    //d = 1 + rand() % 8;
    //e = 1 + rand() % 8;
    //f = 1 + rand() % 8;
    //cout << " a = " << a << "  ";
    //cout << " b = " << b << endl;
    //cout << " c = " << c << "  ";
    //cout << " d = " << d << endl;
    //cout << " e = " << e << "  ";
    //cout << " f = " << f << endl;
    string s;
    cout << " а = ";  cin >> s;
    Check_Num(s, 1, 8); int a = atoi(s.c_str());
    cout << " b = ";  cin >> s;
    Check_Num(s, 1, 8); int b = atoi(s.c_str());
    cout << " c = ";  cin >> s;
    Check_Num(s, 1, 8); int c = atoi(s.c_str());
    cout << " d = ";  cin >> s;
    Check_Num(s, 1, 8); int d = atoi(s.c_str());
    cout << " e = ";  cin >> s;
    Check_Num(s, 1, 8); int e = atoi(s.c_str());
    cout << " f = ";  cin >> s;
    Check_Num(s, 1, 8); int f = atoi(s.c_str());

    if (a == c && b == d)throw " Фигуры стоят на одной клетке";
    if (a == e && b == f) throw " Фигура уже стоит на нужной клетке";
    if (c == e && d == f) throw " Нужная клетка уже занята";
    
    cout << " д) белая - ферзь, черная - ферзь" << endl;
    if (e != a && f != b && fabs(a - e) != fabs(b - f)) cout << " Белая фигура никак не может ходить в клетку e, f" << endl; else {
        if (c == a || d == b || fabs(a - c) == fabs(b - d)) cout << "  Черный ферзь собьет белого ферзя" << endl;
        else if(c == e || d == f || fabs(e - c) == fabs(f - d)) cout << " Белая фигура может пойти, но там ее собьют" << endl;
        else cout << " черный ферзь не собьет белого ферзя и он сможет попасть в e, f" << endl;
    }
  

    cout << " п) белая - слон, черная - конь" << endl;
    if (fabs(a - e) != fabs(b - f)) cout << " Белая фигура никак не может ходить в клетку e, f" << endl; 
     else {
        if ((a == c + 2 || a == c - 2) &&( b == d - 1 || b == d + 1)) cout << " Черный конь собьет белого слона" << endl; 
        else if ((b == d + 2 || b == d - 2) && (a == c - 1 || a == c + 1)) cout << " Черный конь собьет белого слона" << endl;
        else  if ((e == c + 2 || e == c - 2 )&& (f == d - 1 || f == d + 1)) cout << " Белая фигура может пойти, но там ее собьют" << endl;
        else if ((f == d + 2 || f == d - 2) &&( e == c - 1 || e == c + 1)) cout << " Белая фигура может пойти, но там ее собьют" << endl;
        else cout << " Черный конь не собьет белого слона и он сможет попасть в e, f" << endl;
    }

}
     
        

void Task2() {
    int v;
    cin >> v;
      int q, w, e, r, t, y, u, i, o, p, z;
        z = 0;
        for (q = 0; q < 2; q++) {
            for (w = 0; w < 2; w++) {
                for (e = 0; e < 2; e++) {
                    for (r = 0; r < 2; r++) {
                        for (t = 0; t < 2; t++) {
                            for (y = 0; y < 2; y++) {
                                for (u = 0; u < 2; u++) {
                                    for (i = 0; i < 2; i++) {
                                        for (o = 0; o < 2; o++) {
                                            for (p = 0; p < 2; p++) {
                                                if (v == q * 100 + w * 200 + e * 300 + r * 500 + t * 1000 + y * 1200 + u * 1400 + i * 1500 + o * 2000 + p * 3000) {
                                                    z++;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("%d sposobov", z);
}


void Task3() {
    cout << " 11.234 а) размеры 15 параллепипедов хранятся в трех массивах " << endl
        << " Определить максимальный объем фигуры: " << endl;


   
}


class shaxmati1 {
    char arr[8][8];
};

void Task4() {
    cout << " 11.285 * Шахматную доску будем представлять в виле квадратного символьного массива размера 8х8." << endl <<
        " Даны натуральные числа v  и g , указывающие номера вертикали и горизонтали для поля, на котором стоит шахматная фигура." << endl <<
        " Необходимо найти поля, находящиеся под угрозой данной фигуры(КОНЬ), положить равными символу *, а остальные — символу 0;" << endl;

    char Arr[8][8];
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Arr[i][j] = '0';
        }
    }

    for (int j = 0; j <= 8; j++) {
        if(j==0) cout << setw(3) << " ";
        else cout << setw(3) << j;
    }
    cout << endl;
    for (int i = 0; i < 8; i++) {
        cout << setw(3)  << i + 1;
        for (int j = 0; j < 8; j++) {
            cout << setw(3) << Arr[i][j];
        }
        cout << endl;
    }
    cout << endl;

    string s;
    cout << " Введите номер строки v, накотором стоит конь: v = ";
    cin >> s;
    Check_Num(s, 1, 8);
    int v = atoi(s.c_str())-1;
    cout << " Введите номер столбца g, накотором стоит конь: g = ";
    cin >> s;
    Check_Num(s, 1, 8);
    int g = atoi(s.c_str())-1;
    Arr[v][g] = 'к';

    if (v - 2 >= 0) {
        if (g - 1 >= 0) Arr[v - 2][g - 1] = '*';
        if (g + 1 < 8) Arr[v - 2][g + 1] = '*';
    }

    if (v + 2 < 8) {
        if (g - 1 >= 0) Arr[v + 2][g - 1] = '*';
        if (g + 1 < 8) Arr[v + 2][g + 1] = '*';
    }

    if (g - 2 >= 0) {
        if (v-1>=0) Arr[ v- 1][g - 2] = '*';
        if (v + 1 < 8) Arr[v + 1][g - 2] = '*';
    }


    if (g + 2 < 8) {
        if (v - 1 >= 0) Arr[v - 1][g + 2] = '*';
        if (v + 1 < 8) Arr[v + 1][g + 2] = '*';
    }

    for (int j = 0; j <= 8; j++) {
        if (j == 0) cout << setw(3) << " ";
        else cout << setw(3) << j;
    }
    cout << endl;
    for (int i = 0; i < 8; i++) {
        cout << setw(3) << i + 1;
        for (int j = 0; j < 8; j++) {
            cout << setw(3) << Arr[i][j];
        }
        cout << endl;
    }
    cout << endl;

}


class shaxmati2 {
    char arr[8][8];
};

void Task5() {

    cout << " 16,25) Поле шахматной доски определяется парой натуральных чисел, каждое из которых не превосходит восьми :" << endl <<
        " первое число — номер вертикали(при счете слева направо), второе — номер горизонтали(при счете снизу вверх)." << endl <<
        " С помощью датчика случайных чисел получить натуральные числа а, b, с, d, е, каждое из которых не превосходит восьми" << endl <<
        " Пусть на (a, b) расположена белая фигура, на поле(с,d) — черная." << endl <<
        " Определить, может ли белая фигура пойти на поле (е, f), не попав при этом под удар черной фигуры." << endl <<
        " д) белая - ферзь, черная - ферзь" << endl <<
        " з) белая - ферзь, черная - слон" << endl;

    int a, b, c, d, e, f;
    srand(time(NULL));
    a = 1 +rand() % 8;
    b = 1 + rand() % 8;
    c = 1 + rand() % 8;
    d = 1 + rand() % 8;
    e = 1 + rand() % 8;
    f = 1 + rand() % 8;

    cout <<" a = " << a<< "  ";
    cout << " b = " << b << endl;
    cout << " c = " << c << "  ";
    cout << " d = " << d << endl;
    cout << " e = " << e << "  ";
    cout << " f = " << f << endl;

    if (a == c && b == d)throw " Фигуры стоят на одной клетке";
    if( a== e && b==f) throw " Фигура уже стоит на нужной клетке";
    if (c == e && d == f) throw " Нужная клетка уже занята";

    if (e != a && f != b && fabs(a - e) != fabs(b - f)) throw " Белая фигура никак не может ходить в клетку e, f";
    if (c == a || d == b || fabs(a - c) == fabs(b - d)) cout << " д) черный ферзь собьет белого ферзя" << endl;
    else cout << " д) черный ферзь не собьет белого ферзя и он сможет попасть в e, f" << endl;

    if (fabs(a - c) == fabs(b - d)) cout << " з) черный слон собьет белого ферзя"<< endl;
    else cout << " з) черный слон не собьет белого ферзя и он сможет попасть в e, f" << endl;        
}

int main() {
    try {
        setlocale(LC_ALL, "rus");

        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        // Task1();
         Task2();
        // Task3();
        // Task4();
        // Task5();
    }

    catch (const char* exception)
    {
        std::cerr << "Error: " << exception << '\n';
    }
    return 0;
}
