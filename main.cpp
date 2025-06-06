#include "menucommands.h"
#include <iostream>
#include <sstream>
#include <limits>
#include <locale.h>
#include <windows.h>

using MenuСommands = std::function<void(FigureCollection&)>;

int main() {
    setlocale(LC_ALL, "Russian");
    FigureCollection collection;
    initializeMenuCommands();

    float command;
    do {
        commandInterface();
        command = getValidCommand();
        try {
            auto it = menuCommands.find(command);
            if (it != menuCommands.end()) {
                it->second(collection);
            } else if (command == 0) {
                std::wcout << L"Выход...\n";
            } else {
                std::wcerr << L"Ошибка: Неизвестная команда. Введите еще раз\n";
            }
        } catch (const std::exception& e) {
            std::wcerr << L"Ошибка: " << e.what() << "\n";
        }
    } while (command != 0);

    return 0;
}
