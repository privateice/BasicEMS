#pragma once
#include <string>
#include <functional>
#include <iostream>
#include <ostream>
#include <string>
#include "Permissions.h"

class Employee
{
    private:
        std::string name, username;
        size_t password;
        int ID;
        Permissions permissions;
        
    public:
        std::string GetUsername() const;
        std::string GetName() const;
        size_t GetPassword() const;
        int GetID()const;
        Permissions GetPermissions() const;
        bool CheckPermissions(std::string command) const;
        bool CheckPassword(std::string pwd) const;
        void PrintShortEmployee() const;
        

        Employee(std::string pname, std::string puser, std::string ppwd, 
                int pID, Permissions pperms);

};

std::ostream& operator<<(std::ostream& out, const Employee& employee);
