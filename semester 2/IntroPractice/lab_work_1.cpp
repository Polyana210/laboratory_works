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

double Perimetr(double S) {
    double P;
    P = sqrt(S) * 4;
    cout << "�������� �������� ����� " << P;
    return P;
}

double Task1() {
    cout << endl << "1.2.7.������� �������� ����� S ��.�.����� �������� ��������. " << endl;
    string S;
    cout << "������� ������� ��������: ";
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
    cout << endl << "����� ���� ����� �����: " << Summ<< endl;
    cout << "������������ ���� ����� �����: " << Proizv << endl;
}

void Task2() {
    cout << endl << "���� �������������� �����. ����� ����� � ������������ ��� ���� " << endl;
    string N;
    cout << "������� �������������� �����: ";
    cin >> N;
    Check_Num(N, 999, 9999);
    return Summ_Proizv_Num(atoi(N.c_str()));
}

void Task3() {
    cout << endl << "� ����������� ����� ���������� ��� ������ �����."
        << endl << " � ����������� ����������� ����� ��������� ����� ����������� �����, ���������� ����� n;  "
        << endl << " ����� �������� ����� " << endl;
    string N;
    cout << "������� ����������� �����: ";
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
