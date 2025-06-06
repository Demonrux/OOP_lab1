#ifndef MENUCOMMANDS_H
#define MENUCOMMANDS_H

#include <map>
#include <functional>
#include "figurecollection.h"

using MenuCommands = std::function<void(FigureCollection&)>;

extern std::map<float, MenuCommands> menuCommands;

void initializeMenuCommands();
void commandInterface();
double getValidNumber();
int getValidCommand();

#endif // MENUCOMMANDS_H
