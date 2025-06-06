#include "circle.h"
#include <cmath>
#include <iostream>
#include <locale.h>

Circle::Circle(const std::string& name, double centerX, double centerY, double radius)
    : Figure(name), centerX(centerX), centerY(centerY), radius(radius)  {
    if (radius <= 0 || (radius < 1e-10)) {
        throw std::invalid_argument("Incorrect radius");
    }
}

double Circle::get_area() const {
    return M_PI * radius * radius;
}

void Circle::show() const {
    setlocale(LC_ALL, "Russian");
    std::wcout << L"Круг: ";
    std::cout << name ;
    std::wcout << L" (Центр: (" << centerX << ", " << centerY << L"), Радиус: " << radius << ")\n";
}
