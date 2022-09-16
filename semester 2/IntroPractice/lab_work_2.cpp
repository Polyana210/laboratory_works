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
    if (atoi(b.c_str()) > n || atoi(b.c_str()) <= k) { throw  "������������ ����"; }
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

int Year(int S) {
    if (S % 4 == 0) {
        if (S % 100 == 0 && S % 400 != 0) {
            cout << "�� ���������� 365 ����"; return 365;
        }
        cout << "���������� 366 ����"; return 366;
    }
    else {
        cout << "�� ���������� 365 ����";
        return 365;
    }
}

void Task1() {
    string S;
    cout << " ��� ����� ����. ���������� ���������� ���� � ���� ����. " << endl;
    cout << " ������� ����� ����" << endl;
    cin >> S;
    Check_Num(S, 0, 2022);
    Year(atoi(S.c_str()));
}

void Task2() {
    string S1;
    string S2;
    string S3;
    cout << " ���� ��� ����c������� �����. �������� � ������� �� �� ���, ������� �������������� " << endl;
    cout << " ������� ������ �����" << endl;
    cin >> S1;
    Check_123(S1, -10000, 10000);
    cout << " ������� ������ �����" << endl;
    cin >> S2;
    Check_123(S2, -10000, 10000);
    cout << " ������� ������ �����" << endl;
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
    cout << " ���� ��� ����c������� ����� a, b, c. ���������� �������� �� ����������� �� ��������� a, b, c ������������� " << endl;
    cout << " ������� ����� a = ";
    cin >> S1;
    Check_123(S1, 0, 10000);
    cout << " ������� ����� b = ";
    cin >> S2;
    Check_123(S2, 0, 10000);
    cout << " ������� ����� c = ";
    cin >> S3;
    Check_123(S3, 0, 10000);
    double A, B, C;
    A = stod(S1);
    B = stod(S2);
    C = stod(S3);
    double temp;
    if (B > A && B >= C) { temp = A; A = B; B = temp; }
    if (C > A && C >= B) { temp = A; A = C; C = temp; }
    if (A >= B + C) throw "������������ �� ����������";
    A = A * A;
    B = B * B;
    C = C * C;
    if (A == B + C) cout << " ����������� �������������"; else cout << " ����������� �� �������������";
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
