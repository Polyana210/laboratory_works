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

 // --------- ����� "�����" ---------------

class Point {
    double x, y; // ���������� �����
public:
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
};

// --------- ����� "������" --------------

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

#endif

// =============== ����� ������������� �����  ==================
