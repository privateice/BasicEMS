#pragma once
#include <string>
#include <functional>
#include <iostream>
#include <ostream>
#include <string>
#include "Permissions.h"

class Employee
{   // The basic employee record
    private:
        std::string name, username;
        size_t password;
        int ID;
        Permissions permissions;
        
    public:
        // Username functions
        std::string GetUsername() const{ return(username);};
        void SetUsername(std::string newuser){username = newuser;};

        // Name functions
        std::string GetName() const{ return(name);};
        void SetName(std::string newname){name = newname;};

        // Password functions
        size_t GetPassword() const{ return(password);};
        static std::string GeneratePassword(int length = 8);
        bool CheckPassword(std::string pwd) const;

        // Permissions functions
        Permissions GetPermissions() const {return(permissions);};
        void SetPermissions(Permissions newperms){permissions = newperms;};
        bool CheckPermissions(std::string command) const;

        // ID, print, Constructor functions
        int GetID() const{ return(ID);};
        void PrintShortEmployee() const;
        Employee(std::string pname, std::string puser, std::string ppwd, 
                int pID, Permissions pperms);
};

// operator overload for printing an employee
std::ostream& operator<<(std::ostream& out, const Employee& employee);

// © Mary E Tyler 2026