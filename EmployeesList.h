#pragma once
#include <string>
#include <vector>
#include "Employee.h"

class Login;

class EmployeesList
{
    private:
        std::vector<Employee> employees;
    public:
        int FindUser(std::string username) const;
        void MakeSomeEmployees();
        EmployeesList();
        std::vector<Employee> GetEmployees() const {return(employees);};
        void ViewSelf(const Login& login) const;
};

