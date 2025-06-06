#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"

class Rectangle : public Figure {
public:
    double topLeftX, topLeftY;
    double bottomRightX, bottomRightY;

    Rectangle(const std::string& name, double topLeftX, double topLeftY, double bottomRightX, double bottomRightY);
    double get_area() const;
    void show() const;
};

#endif // RECTANGLE_H
