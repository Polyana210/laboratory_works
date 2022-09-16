#include <windows.h>
#include <iostream>
#include <string>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath>
#include <fstream>
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

// ====== Проверка на дробное число  ==========
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

void Task1() {
	ifstream f;
	
	double i, sum = 0;
	string s;

    cout << " Введите k1 = ";
    cin >> s;
    Check_Num(s, 0, 10000);
    int k1 = atoi(s.c_str());
    cout  << " Введите k2 = ";
    cin >> s;
    Check_Num(s, 0, 10000);
    int k2 = atoi(s.c_str());
    f.open("a.txt", ios::in);
    int count=0;
    double sum1 = 0, sum2 = 0; int d = 0;
    while (!f.eof())
    {
        f >> s;
        Check_123(s, -10000, 10000);
        int n = stod(s);
        if (count+1 == k1 || count+1 == k2)  sum += n;
        sum1 += n;
        if (n > 0) { sum2 += n; d++; }
        count++;
    }
    if(k1>count || k2>count) throw "Неккоректный ввод (чисел с таким номером нет)";
    cout << " б) Сумма к1 и к2 чисел файла: " << sum << endl;
    f.close();
	cout << " г) Сумма всех чисел файла: " << sum1<< endl;
    cout << " e) Среднее арифметическое положительных чисел файла: " << sum2/d << endl;
}

void Task2() {
    ifstream f;
    ofstream out;
    f.open("a.txt", ios::in);
    out.open("b.txt", ios::app);
    double i, s=20000;
    string S;
    int count = 0;
    while (!f.eof())
    {
        if (count != 1) {
            f >> S;
            Check_123(S, -10000, 10000);
            i = stod(S); 
            if (i == 0) count++;
            out << " " << i;
        }
        else {
            f >> S;
            Check_123(S, -10000, 10000);
            i = stod(S); count++;
        }
    }
    f.close();
    if(count ==0)throw "Нулевых элементов нет";

    out.close();
}
void Task3() {
    ifstream in1("in1.txt");
    ofstream out1("out1.txt");
    ofstream out2("out2.txt");
    if (in1 && out1 && out2)
    {
        string s;
        int n = 1;
        while (getline(in1, s))
        {
            if (n % 2)
                out1 << s << endl;
            else
                out2 << s << endl;
            n++;
        }
        in1.close();
        out1.close();
        out2.close();
    }
}

int main()
{
	setlocale(LC_ALL, "rus");
    try{
	//Task1();
    //Task2();
    Task3();
}

catch (const char* exception)
{
    std::cerr << "Error: " << exception << '\n';
}
	return 0;
}