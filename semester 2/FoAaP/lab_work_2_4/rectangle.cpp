//*****************************************************************************
//  10. ��������� �������������, ���� ��������, ��� ��������� ������ ����
//  ���������� ����� ������ R, � ��������� ��� �������� ������� ����������� �
//  ������(x1, y1) �(x2, y2).
//*****************************************************************************

#include <windows.h>
#include "geometry.h"
#include <iostream>
using namespace std;
int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "rus");

    // ----- ���� �������� ������ -----
    double x1, y1, x2, y2, x01, y01, d, h, x02, y02, r ;
    cout << "������� ���������� ������ ����� ===> ";
    cin >> x1 >> y1;
    cout << "������� ���������� ������ ����� ===> ";
    cin >> x2 >> y2;
    cout << "������� ������ ���������� ===> ";
    cin >> r ;
    if (r <= sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)) / 2 || r>=1000) {
        cout << "������ �����������." << endl;
            exit(-1);
    }

    if(x1==x2 && y1==y2) {
        cout << " �� ����� ���� �����." << endl;
        exit(-1);
    }
    d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        h = sqrt(r * r - (d / 2) * (d / 2));

        x01 = x1 + (x2 - x1) / 2 + h * (y2 - y1) / d;
        y01 = y1 + (y2 - y1) / 2 - h * (x2 - x1) / d;

        x02 = x1 + (x2 - x1) / 2 - h * (y2 - y1) / d;
        y02 = y1 + (y2 - y1) / 2 + h * (x2 - x1) / d;
       
    // ----- �������� ����� - ������ �������������� -----
    Point A = Point(x1, y1),
          B = Point(x2, y2);

    // ----- �������� ����� - ������� ����������� -----
    Point O1 = Point(x01, y01),
          O2 = Point(x02, y02);
 
    // ----- �������� ������, ���������� ����� ������� �������������� -----
    Line lineAB = Line(A, B);
       
    // ----- �������� ��������������� � ���� ������� ... -----
    Line perpendicular1 = lineAB.getPerpendicular(A);
    Line perpendicular2 = lineAB.getPerpendicular(B);

    // ----- �������� ������, ���������� ����� ������ ����������� �  ��������� ����� ��������������
    Line lineAO1 = Line(A, O1);
    Line lineAO2 = Line(A, O2);
    Line lineBO1 = Line(O1, B);
    Line lineBO2 = Line(O2, B);

    // ----- ���������� ����������� ����� ��������������
    Point C1 = lineAO1.getIntersect(perpendicular2);
    Point C2 = lineAO2.getIntersect(perpendicular2);
    Point D1 = lineBO1.getIntersect(perpendicular1);
    Point D2 = lineBO2.getIntersect(perpendicular1);

    // ----- ����� ���������� -----
    cout << endl << "�������� ��� �������� ������������ ��������������: " << endl << endl;
    cout << "������� 1" << endl << "������������� � ��������� � ������: "
        << endl << " A( " << A.getX() << " ; " << A.getY() << " )"
        << endl << " B( " << B.getX() << " ; " << B.getY() << " )"
        << endl << " C( " << C1.getX() << " ; " << C1.getY() << " )"
        << endl << " D( " << D1.getX() << " ; " << D1.getY() << " )" << endl << endl;
    cout << "������� 2" << endl << "������������� � ��������� � ������: "
        << endl << " A( " << A.getX() << " ; " << A.getY() << " )"
        << endl << " B( " << B.getX() << " ; " << B.getY() << " )"
        << endl << " C( " << C2.getX() << " ; " << C2.getY() << " )"
        << endl << " D( " << D2.getX() << " ; " << D2.getY() << " )" << endl << endl;

   
    return 0;
}

// ================= ����� ��������� ===========================
