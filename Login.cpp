#include <iostream>
#include "Login.h"
#include "Employee.h"
#include "EmployeesList.h"


int ProcessAuthentication( EmployeesList employees,
                    std::string username, 
                    std::string pwd) 
{
    int userindex = employees.FindUser(username);
    if (userindex > -1 ) {
        return(employees[userindex].CheckPassword(pwd));
    };
    return(-1);
};