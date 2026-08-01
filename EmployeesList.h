#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Employee.h"

class Login;

class EmployeesList
{
    private:
        std::vector<Employee> employees;
    public:
        int FindUserbyUsername(std::string username) const;
        int FindUserbyID(int id) const;
        int FindbyUsernameorID(std::string searchterm)const;
        int FindbyName(std::string searchterm)const;
        void PrintEmployeesListShort(const std::vector<Employee>& empstoprint) const;
        void MakeSomeEmployees();
        EmployeesList();
        std::vector<Employee> GetEmployees() const {return(employees);};
        void ViewSelf(const Login& login) const;
        void ViewOther() const;
        void Search() const;
        void Add();
        void Modify();
        void Remove();
};

