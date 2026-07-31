#pragma once
#include <iostream>
#include <set>
#include "Employee.h"

class Menu{

    private:
        std::string menustr;
        const std::set<std::string> allvalidcommands = {
            "exit",
            "viewself",
            "viewother",
            "search",
            "add",
            "modify",
            "remove"
        };
    public:
        void PrintMenu() const;
        std::string GetMenuSelection() const;
        int ProcessSelectedCommand(std::string command, Employee userin) const;
        Menu(Employee userin);
};