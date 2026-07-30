#include "Login.h"

std::pair ProcessAuthentication( EmployeesList emp,
                    std::string username, 
                    std::string pwd) 
{
    int userindex = emp.FindUser(username);
    if (userindex > -1 ) {
        Employee employee = emp.GetEmployees()[userindex];
        return{employee.CheckPassword(pwd),
               employee };
    };
    return(-1);
};