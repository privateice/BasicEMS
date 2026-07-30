#include "EmployeesList.h"

EmployeesList::EmployeesList() 
{
    MakeSomeEmployees();
};

int EmployeesList::FindUser(std::string username) const
{
    // loop through the employees
    for (size_t i = 0; i < employees.size(); i++)
    {   // look for the username and return the index
        if (employees[i].GetUsername() == username) {return (i)}
    }
    return(-1); //return -1 if not found
};

void EmployeesList::MakeSomeEmployees() 
{   //just makes some dummy employees for testing
    employees.push_back(
        Employee("Renee Resource", "renee", "passwordHR", 1001, 
            Permissions(true, true, true, true, true)));

    employees.push_back(
        Employee("Manny Manager", "manny", "passwordM", 1002, 
            Permissions(true, true, false, false, false)));

    employees.push_back(
        Employee("Emmiline Employee", "emmy", "passwordE", 1003, 
            Permissions(true, false, false, false, false)));
};