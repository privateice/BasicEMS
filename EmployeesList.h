#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <limits>
#include "Utilities.h"
#include "Employee.h"
#include "Permissions.h"

class Login;

class EmployeesList
{
    private:
        std::vector<Employee> employees;
        char AddPreflight(Login login) const;
        std::string GetUniqueUsername(bool allowSkip = false) const;
        int GetUniqueID() const;
        Permissions GetPermissionsPreset() const;
        std::string GetConfirmedName(bool allowSkip = false) const;

    public:
        int FindUserbyUsername(std::string username) const;
        int FindUserbyID(int id) const;
        int FindbyUsernameorID(std::string searchterm)const;
        std::vector<Employee> FindbyName(std::string searchterm)const;
        void PrintEmployeesListShort(const std::vector<Employee>& empstoprint) const;
        void MakeSomeEmployees();
        EmployeesList();
        std::vector<Employee> GetEmployees() const {return(employees);};
        void ViewSelf(const Login& login) const;
        void ViewOther() const;
        void Search() const;
        void Add(Login login);
        void Modify(Login login);
        void Remove();
};

