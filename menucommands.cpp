#include "menuCommands.h"
#include <iostream>
#include <sstream>
#include <limits>
#include <algorithm>
#include <cctype>

std::map<float, MenuCommands> menuCommands;

std::string getName() {
    std::string input;
    std::string name;

    while (true) {
        std::getline(std::cin, input);
        std::istringstream iss(input);

        if ((iss >> name) && !std::getline(iss, input)) {
            return name;
        } else {
            std::getline(iss, input);
            std::wcerr << L"Неправильный ввод, введите другое значение:  ";
        }
    }

}

double getValidNumber() {
    std::string input;
    double value;

    while (true) {
        std::getline(std::cin, input);
        std::istringstream iss(input);

        if ((iss >> value) && !std::getline(iss, input)) {
            return value;
        } else {
            std::getline(iss, input);
            std::wcerr << L"Неправильный ввод, введите другое значение:  ";
        }
    }
}

int getValidCommand() {
    float command;
    std::string input;
    while (true) {
        std::getline(std::cin, input);
        if (std::cin.fail() || input.size() > 3 ||(input[1] == ' ' || input[1] == '.') ) {
            std::cin.clear();
            std::wcout << L"Некорректный ввод. Введите команду повторно\n";
        } else {
            if (input.empty() || input.find_first_not_of(' ') == std::string::npos) {
                std::wcerr << L"Ошибка: Ввод не может быть пустым. Пожалуйста, введите число\n";
                continue;
            }

            std::istringstream iss(input);
            if (iss >> command) {
                return command;
            } else {
                std::wcerr << L"Ошибка: Некорректный ввод. Пожалуйста, введите число\n";
            }
        }
    }
}

void initializeMenuCommands() {
    menuCommands[COMMAND_ONE] = [](FigureCollection& collection) {
        std::string name;
        double centerX, centerY, radius;
        std::wcout << (L"Введите имя:");
        name = getName();
        std::wcout << (L"Введите центр X:");
        centerX = getValidNumber();
        std::wcout << (L"Введите центр Y:");
        centerY = getValidNumber();
        std::wcout << (L"Введите радиус:");
        radius = getValidNumber();

        try {
            collection.addFigure(Circle(name, centerX, centerY, radius));
        } catch (const std::exception& e) {
            std::wcerr << L"Ошибка: " << e.what() << "\n";
        }
    };

    menuCommands[COMMAND_TWO] = [](FigureCollection& collection) {
        std::string name;
        double topLeftX, topLeftY, bottomRightX, bottomRightY;
        std::wcout << L"Введите имя: ";
        name = getName();
        std::wcout << L"Введите верхняя левая X: ";
        topLeftX = getValidNumber();
        std::wcout << L"Введите верхняя-левая Y: ";
        topLeftY = getValidNumber();
        std::wcout << L"Введите нижняя-правая X: ";
        bottomRightX = getValidNumber();
        std::wcout << L"Введите нижняя-правая Y: ";
        bottomRightY = getValidNumber();

        try {
            collection.addFigure(Rectangle(name, topLeftX, topLeftY, bottomRightX, bottomRightY));
        } catch (const std::exception& e) {
            std::wcerr << L"Ошибка: " << e.what() << "\n";
        }
    };

    menuCommands[COMMAND_THREE] = [](FigureCollection& collection) {
        std::string name;
        double x1, y1, x2, y2, x3, y3;
        std::wcout << L"Введите имя: ";
        name = getName();
        std::wcout << L"Введите x1: ";
        x1 = getValidNumber();
        std::wcout << L"Введите y1: ";
        y1 = getValidNumber();
        std::wcout << L"Введите x2: ";
        x2 = getValidNumber();
        std::wcout << L"Введите y2: ";
        y2 = getValidNumber();
        std::wcout << L"Введите x3: ";
        x3 = getValidNumber();
        std::wcout << L"Введите y3: ";
        y3 = getValidNumber();

        try {
            collection.addFigure(Triangle(name, x1, y1, x2, y2, x3, y3));
        } catch (const std::exception& e) {
            std::wcerr << L"Ошибка: " << e.what() << "\n";
        }
    };

    menuCommands[COMMAND_FOUR] = [](FigureCollection& collection) { collection.printFigures(); };
    menuCommands[COMMAND_FIVE] = [](FigureCollection& collection) { collection.printAreas(); };
    menuCommands[COMMAND_SIX] = [](FigureCollection& collection) { std::wcout << L"Cумарная площадь: " << collection.sumArea() << "\n"; };
    menuCommands[COMMAND_SEVEN] = [](FigureCollection& collection) { collection.sortByArea(); std::wcout << L"Фигуры отсортированы\n"; };
    menuCommands[COMMAND_EIGHT] = [](FigureCollection& collection) {
        size_t index;
        std::wcout << L"Введите номер фигуры: ";
        index = getValidNumber();
        collection.removeFigure(index - 1);
    };

    menuCommands[COMMAND_NINE] = [](FigureCollection& collection) {
        double area;
        std::wcout << L"Введите площадь: ";
        area = getValidNumber();
        collection.removeFiguresByArea(area);
    };
}

void commandInterface() {
    std::wcout << L"Выберите команду :\n";
    std::wcout << L"1. Добавить круг\n";
    std::wcout << L"2. Добавить прямоугольник\n";
    std::wcout << L"3. Добавить треугольник\n";
    std::wcout << L"4. Вывести список фигур\n";
    std::wcout << L"5. Вывести список площадей\n";
    std::wcout << L"6. Вывести суммарную площадь\n";
    std::wcout << L"7. Отсортировать фигуры по площади\n";
    std::wcout << L"8. Удалить фигуру по номеру\n";
    std::wcout << L"9. Удалить фигуры, у которых площадь больше заданной\n";
    std::wcout << L"0. Выход\n";
}
