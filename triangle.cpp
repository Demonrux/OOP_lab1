#include "triangle.h"
#include <cmath>
#include <iostream>

Triangle::Triangle(const std::string& name, double x1, double y1, double x2, double y2, double x3, double y3)
    : Figure(name), x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {
    a = std::sqrt(std::pow(x2-x1,2) + std::pow(y2-y1,2));
    b = std::sqrt(std::pow(x3-x2,2) + std::pow(y3-y2,2));
    c = std::sqrt(std::pow(x3-x1,2) + std::pow(y3-y1,2));
    if((a <= 0 || b <= 0 || c <= 0))
        throw std::invalid_argument("Incorrect coordinates");
    else if(a < 1.e-10 || b < 1.e-10 || c < 1.e-10)
        throw std::invalid_argument("Coordinates to small");
    else if(((a + b) < c || (b + c) < a || (a + c) < b)) {
        throw std::invalid_argument("Triange is convex");
    }
}

double Triangle::get_area() const {
    return std::abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2);
}

void Triangle::show() const {
    std::wcout << L"Треугольник: ";
    std::cout << name;
    std::wcout << L" (Вершины: (" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << "), (" << x3 << ", " << y3 << "))\n";

}
