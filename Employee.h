#pragma once
#include <string>
#include <functional>
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
        bool CheckPassword(std::string pwd) const;

        Employee(std::string pname, std::string puser, std::string ppwd, 
                int pID, Permissions pperms);


};