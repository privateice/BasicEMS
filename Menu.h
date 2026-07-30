#pragma once
#include <iostream>
#include "Employee.h"

class Menu{

    private:
        std::string menustr;
    public:
        void PrintMenu() const;
        Menu(Employee userin);
};