#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"

class Triangle : public Figure {
public:
    double a, b ,c;
    double x1, y1, x2, y2, x3, y3;

    Triangle(const std::string& name, double x1, double y1, double x2, double y2, double x3, double y3);
    double get_area() const;
    void show() const;
};

#endif // TRIANGLE_H
