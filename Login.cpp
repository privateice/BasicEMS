#include "Login.h"
#include "Employees.h"

Login::Login(std::vector<Employee> employees)
{
   
};


int FindUser(std::string username, std::vector<Employee> employees)
{
    // loop through the employees
    for (size_t i = 0; i < employees.size(); i++)
    {   // look for the username and return the index
        if (employees[i].GetUsername == username) {return (i)}
    }
    return(-1) //return -1 if not found
};

int CheckPassword(std::string pwd, Employee emp)
{   // check if the password matches: true if yes, false if no
    std::hash<std::string> hasher;
    if (hasher(pwd) == emp.GetPassword()) {return(1);}
    return(0);
};

int ProcessLogin( std::vector<Employee> employees,
                    std::string username, 
                    std::string pwd) 
{
    i = FindUser(username, employees);
    if (i >= 0 ) {return(CheckPassword(pwd,employees[i]))};
    else (return(-1))
};