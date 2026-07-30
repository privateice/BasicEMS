#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Employee.h"
#include "EmployeesList.h"

class Login
{
    private:

    
    public:
        int ProcessAuthentication(EmployeesList employees,
                std::string username, std::string pwd) const;
        
        Login(){};

};