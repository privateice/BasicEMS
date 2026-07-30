#include "Login.h"

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