
#define _USE_MATH_DEFINES
#include <math.h>

#include <iostream>
#include "classes.h"

Cylinder::Cylinder(double Radius, double Height) {
    radius = Radius; height = Height;
}
double Cylinder::getRadius() {
    return radius;
}

double Cylinder::getHeight() {
    return height;
}

double Cylinder::Square() {
    return (2 * M_PI * radius * (radius + height));
}

Cone::Cone(double Forming){
    forming = Forming;
}

double Cone::Square(Cylinder & C) {
    return (M_PI  * C.getRadius() * (C.getRadius() + forming));
}



