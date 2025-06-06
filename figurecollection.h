#ifndef FIGURECOLLECTION_H
#define FIGURECOLLECTION_H

#include <vector>
#include <variant>
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

typedef enum{
    COMMAND_ZERO ,
    COMMAND_ONE ,
    COMMAND_TWO,
    COMMAND_THREE,
    COMMAND_FOUR,
    COMMAND_FIVE,
    COMMAND_SIX,
    COMMAND_SEVEN,
    COMMAND_EIGHT,
    COMMAND_NINE
} commands;

using FigureVariant = std::variant<Circle, Rectangle, Triangle>;

class FigureCollection {
private:
    std::vector<FigureVariant> figures;

public:
    void addFigure(const FigureVariant& figure);
    void printFigures() const;
    void printAreas() const;
    double sumArea() const;
    void sortByArea();
    void removeFigure(size_t index);
    void removeFiguresByArea(double area);
};
#endif // FIGURECOLLECTION_H
