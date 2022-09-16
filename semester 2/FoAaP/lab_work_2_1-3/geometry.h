/***************************************************************
 *                                                             *
 * ����     : geometry.h                                       *
 *                                                             *
 * �������� : ������������ ���� � ��������� ������ �������     *
 *            ��� ������� �������������� �����                 *
 *                                                             *
 ***************************************************************/

#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <iostream>

 // --------- ����� "�����" ---------------

class Point {
public:
    double x, y; // ���������� �����
    Point(double X, double Y); // ����������� ������
    double getX();             // ������ ���� X
    double getY();             // ������ ���� Y
};


// --------- ����� "����������" ----------

class Circle {
    Point center; // ����� ����������
    double r;     // ������ ����������
public:
    Circle(Point Center, double R);   // ����������� ������
    Point getCenter();                // ������ ���� Center
    double getR();                    // ������ ���� R
    friend std::ostream& operator<< (std::ostream& out, const Circle& circle1)
    {
        out << "����� ���������� ����� � ����� (" << circle1.center.x << ", " << circle1.center.y << "). ������ ���������� ����� " << circle1.r;
       return out;
    }
};

class Line {
    double A, B, C; // ������������ ������
public:
    Line(double a, double b, double c); // ����������� ������
    Line(Point p1, Point p2);          // ��� ���� �����������
    Point getIntersect(Line line);    // ����� ����� ����������� � �������� ������
    Line getPerpendicular(Point p);   // ����� ���������������� ������,
                                      // ���������� ����� �������� �����
};

// --------- ����� "�������" -------------

class Segment {
    double x1, y1, x2, y2; // ���������� ������ �������
public:
    Segment(Point p1, Point p2);       // ����������� ������
    Point getMidpoint();              // ����� �������� �������
    double getLength();               // ����� ����� �������
};

// --------- ����� "������" -------------

class Vector {
    double x;
    double y;
public:
    Vector(double X, double Y);        // ����������� ������
    double getX();                     // ������ ���� X
    double getY();                     // ������ ���� Y
    Vector add(Vector Slag);           // ��������
    Vector subtraction(Vector Vich);   //��������� 
    double scal(Vector V2);            //��������� ������������
    Vector proizv_na_scal(double d2);  //������������ �� ������

};
#endif

// =============== ����� ������������� �����  ==================
