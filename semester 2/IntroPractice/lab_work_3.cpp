#include <windows.h>
#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

class Otvet {
    bool Da;
    bool Net;
};

class Model {
    double p;
 };

class Osadki {
    double n;
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

void Task1() {
 
    cout << "������!" << endl << "�� ���� ������� ������? (D/N)"<< endl;
    string S;
    cin >> S;
    if (S == "D") cout << " ������ �������!"; else
        if (S == "N") cout << " � ��������� ������� �����!"; else throw "������������ ����"; }

void Task2() {
    cout <<  " �������� ������ � �������� ��������� 30 ������� �������� �����������." << endl
        << " ��������, ���� �� ����� ��� ������ � ���������, ����������� 200��" << endl;
    double Arr[30]; string S; int T = 0;
    for (int i = 0; i < 30; i++) {
        cout << " ������� " << i+1 << " �������� �������� ";
        cin >> S;
        Check_123(S, 0, 10000);
        Arr[i] = stod(S);
        if (Arr[i] > 200) T = 1;
    }
    if (T == 1) cout << " ���������� ��������, ����������� 200";
    else cout << " �������, � ���������, ����������� 200, ���";
}

void Task3() {
    cout <<  " �������� ������ � ���������� �������, �������� � ������ ���� ������." << endl
        << " ������ ����� ������ ����� ������� ���������� �������? " << endl;

    string S;
    cout << " ������� ����� ������ ";
    cin >> S;
    Check_Num(S, 1, 12);
    int N = atoi(S.c_str());
    int n = 0;
    if (N == 1 || N == 3 || N == 5 || N == 7 || N == 8 || N == 10 || N == 12) n = 31;
    else if (N == 2) n = 28; else  n = 30;
    double* Arr = new double[n];
    for (int i = 0; i < n; i++) {
        cout << " ������� ���������� ������� " << i + 1 << "."<< N << " ";
        cin >> S;
        Check_123(S, 0, 10000);
        Arr[i] = stod(S);
    }
    double Max = Arr[n - 1]; int O = 0;
    for (int i = n-1; i >= 0; i--) {
        if (Arr[i] > Max) {
            Max = Arr[i]; O = i;
        }
    }
    cout << "����, ����� ������ ������������ ���������� �������: " << O+1 << "." << N;

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
