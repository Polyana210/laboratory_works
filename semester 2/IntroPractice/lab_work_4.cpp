#include <windows.h>
#include <iostream>
#include <string>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

// ====== �������� �� ����� �����  ===========
bool Check_Num(string b, int k, int n) {
    if (atoi(b.c_str()) > n || atoi(b.c_str()) < k) { throw  "������������ ����"; }
    int i = 0;
    if (b[0] == '-')  i = 1;
    for (i; i < b.size(); i++) {
        if (b[i] < '0' || b[i] > '9') {
            throw "������������ ����";
        }
    }
    return 1;
}

// ====== �������� �� ������� �����  ===========
bool Check_123(string b, int k, int n) {
    if (atoi(b.c_str()) > n || atoi(b.c_str()) < k) { throw  "������������ ����"; }
    int i = 0;
    if (b[0] == '-')  i = 1;
    int count = 0;
    for (i; i < b.size(); i++) {
        if (b[i] < '0' || b[i] > '9') {
            if (b[i] != '.') {
                throw "������������ ����";
            }
        }
        if (b[i] == '.')count++;
    }
    if (count > 1)throw "������������ ����";
    return 1;
}

void Input(double** arrayPtr, int n, int m) {
    string s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout  << i + 1 << " ������� " << j + 1 << " ����  ";
            cin >> s;
            Check_123(s, 0, 10000);
            arrayPtr[i][j]= atoi(s.c_str());
        }
    }
}
// ������� ������
void Delete(double** arrayPtr, int n, int m) {
    for (int i = 0; i < n; i++) {
        delete[]arrayPtr[i];
    }
    delete[]arrayPtr;
}

// ����� �������
void Output(double** arrayPtr, int n, int m) {
  /*  cout << setw(5) << "          ";
    for (int j = 1; j <= m; j++) {
        cout << setw(6) << j;
    }*/
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(5) <<"������� " << i+1;
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
    cout << " ���� ����������� ����� m � ����� ����� a1, a2, ..., am." << endl
        << " ��������, ����� �� ��� ���������� ��� ai, ������� ������ m, ������ ������ ����� p " << endl;
    string s;
    cout << " ������� ����� m = ";
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
    cout << " ������� ����� p = ";
    cin >> s;
    Check_Num(s, -1000, 1000);
    int p = atoi(s.c_str());
    if (p == 0)throw "������������ ����";
    if ((count / p) * p == count) cout << " ����������� ����� "; else cout << " ����������� ������� ";
    delete[] Arr;
}

class shop {
    int days;
    int count;
};

void Task2() {
    cout << " ����� ����� 3 ��������. �������� ����� ������� � ������ �� 10 ����" << endl
        << " ������������ ���� ���������� �� ������� � ����������: " << endl
        << " a) ��� ������� �������� ���� ������������� ������ " << endl
        << " �) ��� ������� ��� ������� � ������������ ������� " << endl;
    double** matrix = new  double* [3];
    for (int i = 0; i < 3; i++) {
        matrix[i] = new double[10];
    }
    Input(matrix, 3, 10);
    Output(matrix, 3, 10);

    double max1 = 0, max2 = 0;
    for (int i = 0; i < 3; i++) {
        cout << setw(5) << " ������� " << i + 1 << " - ���� � ������������ ��������: ";
        for (int j = 0; j < 10; j++) {
            if (matrix[i][j] > max1) {
                max1 = matrix[i][j]; max2 = j + 1;
          };
        }
        cout << max2<< endl;
        max1 = 0; max2 = 0;
    }

    for (int j = 0; j < 10; j++) {
        cout << setw(5) << "����" << j + 1 << " - ������� � ������������ ��������: ";
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
    cout << " ���������� ���������� ���� � ������" << endl;
    char s[16000];
    int slovo, count = 0;
    cout << " ������� ������: " << endl;
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
    cout << " ���������� ���� � ������ " << count<< endl;
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
