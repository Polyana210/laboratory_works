/***************************************************************
 *                                                             *
 * Файл     : geometry.h                                       *
 *                                                             *
 * Описание : заголовочный файл с описанием набора классов     *
 *            для решения геометрических задач                 *
 *                                                             *
 ***************************************************************/

#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <iostream>

 // --------- Класс "Точка" ---------------

class Point {
public:
    double x, y; // координаты точки
    Point(double X, double Y); // конструктор класса
    double getX();             // чтение поля X
    double getY();             // чтение поля Y
};


// --------- Класс "Окружность" ----------

class Circle {
    Point center; // центр окружности
    double r;     // радиус окружности
public:
    Circle(Point Center, double R);   // конструктор класса
    Point getCenter();                // чтение поля Center
    double getR();                    // чтение поля R
    friend std::ostream& operator<< (std::ostream& out, const Circle& circle1)
    {
        out << "Центр окружности лежит в точке (" << circle1.center.x << ", " << circle1.center.y << "). Радиус окружности равен " << circle1.r;
       return out;
    }
};

class Line {
    double A, B, C; // коэффициенты прямой
public:
    Line(double a, double b, double c); // конструктор класса
    Line(Point p1, Point p2);          // еще один конструктор
    Point getIntersect(Line line);    // найти точку пересечения с заданной прямой
    Line getPerpendicular(Point p);   // найти перпендикулярную прямую,
                                      // проходящую через заданную точку
};

// --------- Класс "Отрезок" -------------

class Segment {
    double x1, y1, x2, y2; // координаты концов отрезка
public:
    Segment(Point p1, Point p2);       // конструктор класса
    Point getMidpoint();              // найти середину отрезка
    double getLength();               // найти длину отрезка
};

// --------- Класс "Вектор" -------------

class Vector {
    double x;
    double y;
public:
    Vector(double X, double Y);        // конструктор класса
    double getX();                     // чтение поля X
    double getY();                     // чтение поля Y
    Vector add(Vector Slag);           // сложение
    Vector subtraction(Vector Vich);   //вычитание 
    double scal(Vector V2);            //скалярное произведение
    Vector proizv_na_scal(double d2);  //произведение на скаляр

};
#endif

// =============== конец заголовочного файла  ==================
