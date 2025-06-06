#include "rectangle.h"
#include <iostream>

Rectangle::Rectangle(const std::string& name, double topLeftX, double topLeftY, double bottomRightX, double bottomRightY)
    : Figure(name), topLeftX(topLeftX), topLeftY(topLeftY), bottomRightX(bottomRightX), bottomRightY(bottomRightY) {
    if ((topLeftX >= bottomRightX || topLeftY <= bottomRightY) || (topLeftX < 1.e-10) || (topLeftY < 1.e-10) || (bottomRightX < 1.e-10) || (bottomRightX < 1.e-10)) {
        throw std::invalid_argument("Incorrect coordinates");
    }
}

double Rectangle::get_area() const {
    return (bottomRightX - topLeftX) * (topLeftY - bottomRightY);
}

void Rectangle::show() const {
    std::wcout << L"Прямоугольник: ";
    std::cout << name;
    std::wcout << L" (Верхняя-левая точка: (" << topLeftX << ", " << topLeftY << L"), Правая-нижняя точка: (" << bottomRightX << ", " << bottomRightY << "))\n";
}
