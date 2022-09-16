/***************************************************************
 *                                                             *
 * ����     : geometry.cpp                                     *
 *                                                             *
 * �������� : ������, ���������� ���������� ������� �������    *
 *            ��� ������� �������������� �����                 *
 *                                                             *
 ***************************************************************/

#include <math.h>
#include <iostream>
#include "geometry.h"

 // -------------------------------------------------------------
 //       ������ ������ "�����" 
 // -------------------------------------------------------------

// �����������: ����� �������� ������ ������������
Point::Point(double X, double Y) {
    x = X; y = Y;
}

// ��������� ���������� �
double Point::getX() {
    return x;
}

// ��������� ���������� �
double Point::getY() {
    return y;
}

// -------------------------------------------------------------
//       ������ ������ "����������" 
// -------------------------------------------------------------

// �����������: ���������� �������� ������� � ��������
Circle::Circle(Point Center, double R) :center(Center) {
    r = R;
}

// ��������� ����� ����������
Point Circle::getCenter() {
    return center;
}

// ��������� ������ ����������
double Circle::getR() {
    return r;
}


 


// -------------------------------------------------------------
//       ������ ������ "������" 
// -------------------------------------------------------------

// �����������: ������ �������� ������ ��������������
Line::Line(double a, double b, double c) {
    A = a; B = b; C = c;
}

// �����������: ������, ������� �������� ����� ��� �������� �����
Line::Line(Point p1, Point p2) {
    A = p2.getY() - p1.getY();
    B = p1.getX() - p2.getX();
    C = -A * p1.getX() - B * p1.getY();
}

// ����� ����� ����������� � �������� ������
Point Line::getIntersect(Line line) {
    double d = A * line.B - B * line.A,
        d1 = -(C * line.B - B * line.C),
        d2 = -(A * line.C - C * line.A);
    return Point(d1 / d, d2 / d);
}

// ��������� ���������������� ������, ���������� ����� �������� �����
Line Line::getPerpendicular(Point p) {
    return Line(B, -A, -B * p.getX() + A * p.getY());
}

// -------------------------------------------------------------
//       ������ ������ "�������" 
// -------------------------------------------------------------

// �����������: ������� �������� ����� �������
Segment::Segment(Point p1, Point p2) {
    x1 = p1.getX(); y1 = p1.getY();
    x2 = p2.getX(); y2 = p2.getY();
}

// ����� �������� �������
Point Segment::getMidpoint() {
    return Point((x1 + x2) / 2, (y1 + y2) / 2);
}

// ����� ����� �������
double Segment::getLength() {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}



// -------------------------------------------------------------
//       ������ ������ "������" 
// -------------------------------------------------------------

 // ����������� ������
Vector::Vector(double X, double Y) {
    x = X; y = Y;
}      

// ������ ���� X
double Vector:: getX() {
    return x;
}                    

double Vector:: getY() {
    return y;
}                    // ������ ���� Y

Vector Vector:: add(Vector Slag) {
    Vector result(x,y);
    result.x = x + Slag.x;
    result.y = y + Slag.y;
    return result;
}           // ��������

Vector Vector::  subtraction(Vector Vich) {
    Vector result(x,y);
    result.x = x - Vich.x;
    result.y = y - Vich.y;
    return result;
}   //��������� 

double Vector:: scal(Vector V2) {
    return x * V2.x + y * V2.y;
}       //��������� ������������

Vector Vector:: proizv_na_scal(double d2) {
    Vector result(x,y);
    result.x = x *d2;
    result.y = y *d2;
    return result;
}  //������������ �� ������

// ============== ����� ������ =================================