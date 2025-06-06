#include "figureCollection.h"
#include <algorithm>
#include <iostream>

void FigureCollection::addFigure(const FigureVariant& figure) {
    figures.push_back(figure);
}

void FigureCollection::printFigures() const {
    if(figures.size()) {
        for (size_t i = 0; i < figures.size(); ++i) {
            std::cout << i + 1 << ". ";
            std::visit([](const auto& figure) {
                figure.show();
            }, figures[i]);
        }
    }
    else
        std::wcout << L"Фигуры отсутствуют\n";
}

void FigureCollection::printAreas() const {
    if(figures.size()) {
        for (size_t i = 0; i < figures.size(); ++i) {
            std::cout << i + 1 << ". ";
            std::visit([](const auto& figure) {
                figure.show();
                std::wcout << L"Площадь: " << figure.get_area() << "\n";
                std::cout <<"___________________\n";
            }, figures[i]);
        }
    }
    else
        std::wcout << L"Фигуры отсутствуют\n";
}

double FigureCollection::sumArea() const {
    double sum = 0;
    for (size_t i = 0; i < figures.size(); ++i) {
        std::visit([&sum](const auto& figure) {
            sum += figure.get_area();
        }, figures[i]);
    }
    if(figures.size())
        return sum;
    else
        return 0;
}

void FigureCollection::removeFiguresByArea(double area) {
    figures.erase(std::remove_if(figures.begin(), figures.end(), [area](const FigureVariant& figure) {
                      return std::visit([area](const auto& s) {
                          return s.get_area() > area;
                      }, figure);
                  }), figures.end());
}

void FigureCollection::sortByArea() {
    std::sort(figures.begin(), figures.end(), [](const FigureVariant& one, const FigureVariant& two) {
        double areaOne = std::visit([](const auto& one) {
            return one.get_area();
        }, one);
        double areaTwo = std::visit([](const auto& two) {
            return two.get_area();
        }, two);
        return areaOne < areaTwo;
    });
}

void FigureCollection::removeFigure(size_t number) {
    if (number < figures.size()) {
        auto iter = figures.begin() + number;
        figures.erase(iter);
    }
    else
        throw std::out_of_range("Index out of range");
}
