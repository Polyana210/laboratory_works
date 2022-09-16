// ----------------------------------------------------------------------------------
//   �������. � ������� 1- 10 ���������� ����������� ������������ ����, ����������
//   �������� �������� �� ���� �������, ���������� ������� ��� ����� � ������
//   ���������� �������� � ��������� �������� �������.����������� ������� �
//   ������ ������ ���������� � ��������� �����.
//   ��������� ���������, ��������������� ������ � ������ �� ��������������
//   �������.������� ����� � �������; ����������� ����� � �����; ������� - �������
//   �����������.
// ------------------------------------------------------------------------------------



#define _USE_MATH_DEFINES
#include <math.h>

#include <windows.h>
#include "classes.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "rus");
    double radius, height;
    cout << "������� ������ �������� ===> ";
    cin >> radius;
    cout << "������� ������ �������� ===> ";
    cin >> height;
    
    if (radius <= 0 || height <= 0) {
        cout << "������������ ������"; exit(-1);
    }

    Cylinder cylinder(radius, height);
    double forming;

    forming = sqrt(radius * radius + height * height);
    Cone cone(forming);

    cout << "������� ������ ����������� �������� ����� "<< cylinder.Square()<<endl;
    cout << "������� ������ ����������� ������ ����� " << cone.Square(cylinder) << endl;
 
    return 0;
}



