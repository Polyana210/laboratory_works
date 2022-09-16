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

void Input(int** arrayPtr, int n, int m) {
    string s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> s;
            Check_Num(s, -10000, 10000);
            arrayPtr[i][j] = atoi(s.c_str());
        }
    }
}
// очистка памяти
void Delete(int** arrayPtr, int n, int m) {
    for (int i = 0; i < n; i++) {
        delete[]arrayPtr[i];
    }
    delete[]arrayPtr;
}

// вывод матрицы
void Output(int** arrayPtr, int n, int m) {
  cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(5) << arrayPtr[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

class Array {
    int n;
    int m;
};


void Task1() {
    cout << " 12.147. Дан двумерный массив целых чисел. В каждом его столбце найти:"<< endl
        << " а) первый нечетный элемент(принять, что нечетные элементы есть в каждом столбце)" <<endl<<
          " 6) последний положительный элемент(принять, что положительные элементы ссть в каждом столбце). " << endl;
    string S;
    cout << " Введите количество строк n = ";
    cin >> S;
    Check_Num(S, 1, 1000);
    int n = atoi(S.c_str());
    cout << " Введите количество столбцов m = ";
    cin >> S;
    Check_Num(S, 1, 1000);
    int m = atoi(S.c_str());

    int** matrix = new  int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }
    Input(matrix, n, m);
    Output(matrix, n, m);
    int k = 0; int p=0;
    for (int j = 0; j < m; j++) {
        cout << j+1<<" столбец "<< endl;

        for (int i = 0; i < n; i++) {
            int x = matrix[i][j];
            if (x < 0) x = -1 * x;
            if ( x % 2 == 1) {
                cout << "первый нечетный элемент a[" << i << "][" << j << "]" << endl;
                k++;
                break;
            }
        }
        if(k==0) cout << "нечетных элементов нет" << endl;
        for (int i = n - 1; i >= 0; i--) {
            if (matrix[i][j] > 0) {
                cout << "последний положительный элемент a[" << i << "][" << j << "]" << endl; p++;
                break;
            }
        }
        if (p == 0) cout << "положительных элементов нет" << endl;
    }

    Delete(matrix, n, m);

}

void Input1(double** arrayPtr, int n, int m) {
    string s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> s;
            Check_123(s, -10000, 100000);
            arrayPtr[i][j] = stod(s);
        }
    }
}
// очистка памяти
void Delete1(double** arrayPtr, int n, int m) {
    for (int i = 0; i < n; i++) {
        delete[]arrayPtr[i];
    }
    delete[]arrayPtr;
}

// вывод матрицы
void Output1(double** arrayPtr, int n, int m) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(5) << arrayPtr[i][j];
        }
        cout << endl;
    }
    cout << endl;
}


class Array1
{
    double arr1[15][10];
    double arr2[15];
};

void Task2() {
    cout << " 12.163 a) Дан двумерный размером n x n сформировать" << endl
        << " а) одномерный массив из элементов, расположенных над главной диагональю" << endl;
    string S;
    cout << " Введите количество строк n = ";
    cin >> S;
    Check_Num(S, 1, 1000);
    int n = atoi(S.c_str());
    
    double** matrix = new double* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new double[n];
    }
    Input1(matrix, n, n);
    Output1(matrix, n, n);

    int N=0; int u=n;
    while (u != 0) {
        u = u - 1;
        N = N + u;
    }

    double* arr = new double [N];
    cout << " Составленный массив: ";
    int l = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            arr[l] = matrix[i][j];
            cout << arr[l] << " ";
            l++;
        }
    }

    delete[] arr;
    Delete1(matrix, n, n);
}

class avtomibili {
    double vid;
    double count;
};

void Task3() {
    cout << " 13.28 Известны данные о стоимости 15-ти моделей автомобилей и их типе (грузовой или легковой)" << endl
        << " Найти среднюю стоимость легковых автомобилей" << endl;
    string S;
    cout << "0-легковой автомобиль, 1- грузовой" << endl;
    int vid[15];
    double count[15];
    for (int i = 0; i < 15; i++) {
        cout << " Введите информацию о " << i + 1 << " автомобиле:" << endl;
        cout << " Вид (0/1):";
        cin >> S;
        Check_Num(S, 0, 1);
        vid[i] = atoi(S.c_str());
        cout << " Стоимость:";
        cin >> S;
        Check_123(S, 0, 10000000);
        count[i] = stod(S);
    }
    double sum=0;
    for (int i = 0; i < 15; i++) {
        if (vid[i] == 0) {
            sum += count[i];
       }
    }

    cout << " Средняя стоимость легковых автомобилей равна " << sum / 15 << endl;

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
