#include <iostream>
using namespace std;

class Chast_summa {
    double eps;
    double x;
public:
    Chast_summa(double X, double Eps);
    double getEps();
    double getX();
    double Slag(int n, double x);
};

 Chast_summa::Chast_summa(double X, double Eps) {
     x = X; eps = Eps; 
}

double Chast_summa:: getX() {
    return x;
}

double Chast_summa::getEps() {
    return eps;
}

//  1 ������
long double fac(int N)
{
    if (N < 0) // ���� ������������ ���� ������������� �����
        return 0; // ���������� ����
    if (N == 0) // ���� ������������ ���� ����,
        return 1; // ���������� ��������� �� ���� - �� �����������, �� ��� 1 =)
    else // �� ���� ��������� �������
        return N * fac(N - 1); // ������ ��������.
}

//  2 ������
//long double fac(int N)
//{
//    if (N < 0)  return 0;
//    if (N == 0) return 1;
//    else  return N * fac(N - 1);
//}


double Chast_summa::Slag(int n, double x) {
    double a;
    a = pow(-1, n) * pow(x, 2 * n) / fac(2 * n);
    return a;
}

double sum(double x, double eps) {
    double sum = 0;
    Chast_summa S(x, eps);
    double cos1;
    cos1 = cos(x);
    int i = 0;
    while (fabs(sum - cos1) > S.getEps()) {
        sum += S.Slag(i, S.getX());
        i++;
    }
    return sum;
}


int main()
{
    setlocale(0, "");
    double X=5, 
           EPS=0.1,
           sum1;
    cout << "������� x:   "; cin >> X;
    cout << "������� �������� (eps>0 � eps<=0.1):  "; cin >> EPS;
    if (EPS < 0 || EPS >0.1) {
        cout << "�������� ������������";
        exit(-1);
    }


    sum1= sum(X, EPS);

    cout <<"��������� �����: " << sum1;

    return 0;
}