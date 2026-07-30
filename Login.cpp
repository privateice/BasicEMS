#include "Login.h"

int ProcessAuthentication( EmployeesList emp,
                    std::string username, 
                    std::string pwd) 
{
    int userindex = emp.FindUser(username);
    if (userindex > -1 ) {
        return(emp.GetEmployees()[userindex].CheckPassword(pwd));
    };
    return(-1);
};