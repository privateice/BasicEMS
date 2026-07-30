#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <optional>
#include "Employee.h"
#include "EmployeesList.h"

class Login
{
    private:

    
    public:
        std::pair<int, std::optional<Employee>> ProcessAuthentication(EmployeesList emp,
                std::string username, std::string pwd) const;
        
        Login(){};

};