#pragma once
#include <string>
#include <vector>
#include "Employee.h"

class Login
{
    private:

    
    public:
        int ProcessAuthentication(EmployeesList employees,
                std::string username, std::string pwd) const;
        Login(){};

};