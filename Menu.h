#pragma once
#include <iostream>
#include <set>
#include "Login.h"
#include "Employee.h"

class EmployeesList;
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
            "remove",
            "logout"
        };
    public:
        void PrintMenu() const;
        std::string GetMenuSelection() const;
        int ProcessSelectedCommand(std::string command, 
                Login login, EmployeesList& employees);
        Menu(Employee userin);
};