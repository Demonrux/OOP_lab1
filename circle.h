#ifndef CIRCLE_H
#define CIRCLE_H

#include "figure.h"

class Circle : public Figure {
private:
    double centerX, centerY;
    double radius;
public:
    Circle(const std::string& name, double centerX, double centerY, double radius);
    double get_area() const;
    void show() const;
};

#endif // CIRCLE_H
