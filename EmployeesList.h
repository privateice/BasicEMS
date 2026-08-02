#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <limits>
#include "Utilities.h"
#include "Employee.h"
#include "Permissions.h"

// forward declaration for Login to prevent circular .h references
class Login;
class EmployeesList
{   // Class definition for the list of all employees
    // This is where the magic happens!
    private:
        std::vector<Employee> employees;
        int currMaxID;  // the current max ID, used by Add()

        char AddPreflight() const;
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

