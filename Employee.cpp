#include "Employee.h"


Employee::Employee(std::string pname, std::string puser, 
            std::string ppwd, int pID, Permissions pperms)
            : permissions(pperms)
{   // Employee Constructor, sets employee variables
    // password is stored as a hash
    std::hash<std::string> hasher;
    name = pname;
    username = puser;
    password = hasher(ppwd);
    ID = pID;
};

bool Employee::CheckPassword(std::string pwd) const
{   // check if the password matches: true if yes, false if no
    std::hash<std::string> hasher;
    if (hasher(pwd) == password) {return(true);}
    return(false);
};

void Employee::PrintShortEmployee() const
{   // prints the name, username and ID
    std::cout << "Name: " << GetName()
        << "\tUsername: " << GetUsername()
        << "\tEmployeeID: " << GetID()
        << "\n";
};

bool Employee::CheckPermissions(std::string command) const
{   // checks if an Employee may perform the requested command
    // does not include commands everyone may perform: exit, logout

    if (command == "viewself"){ return(permissions.MayViewSelf());};
    if (command == "viewother"){ return(permissions.MayViewOther());};
    if (command == "search"){ return(permissions.MaySearch());};
    if (command == "add"){ return(permissions.MayAdd());};
    if (command == "modify"){ return(permissions.MayModify());};
    if (command == "remove"){ return(permissions.MayRemove());};
    return(false);
};

std::ostream& operator<<(std::ostream& out, const Employee& employee)
{   // operator overload for printing an employee
    out << "Employee Record\n\tName: " << employee.GetName()
        << "\n\tUsername: " << employee.GetUsername()
        << "\n\tEmployeeID: " << employee.GetID()
        << "\n\tPermissions: " << employee.GetPermissions()
        << "\n";
    return out;
};

std::string Employee::GeneratePassword(int length)
{   //Randomly generates a short, strong password, default length = 8 char
    const std::string alphabet =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789"
        "!@#$%^&*()_+-=";

    std::string pwd;

    // production version would not use rand(), but okay for an assignment
    for (int i = 0; i < length; ++i)
        {pwd += alphabet[rand() % alphabet.size()];};
    std::cout << "Make a note of the temporary password for the employee.\n"
        << "Temporary password: " << pwd << "\n\n";
    return pwd;
};

// © Mary E Tyler 2026