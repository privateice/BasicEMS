#pragma once
#include "Employee.h"
#include "Manager.h"
#include "HR.h"
#include <iostream>

int main() {
    HR hr;
    Manager manager;
    hr.work();
    manager.work();
    std::cout << "Company simulation running." << std::endl;
    return 0;
}