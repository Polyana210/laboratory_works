#pragma once
#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <iostream>


class Cylinder {
    double radius;
    double height;
public:
    Cylinder() = default;
    Cylinder(double Radius, double Height);
    double getRadius();
    double getHeight();
    double Square();
};


class Cone : public Cylinder {
    double forming;
public:
    Cone(double Forming);
    double Square(Cylinder& C);

};

#endif

