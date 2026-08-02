#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <optional>
#include "Employee.h"
#include "EmployeesList.h"

class Login
{   // processed employee login and maintains record of what employee
    // is logged in. 
    private:
        std::optional<Employee> userin = std::nullopt;
    
    public:
        int ProcessAuthentication(EmployeesList emp,
                std::string username, std::string pwd);
        int ProcessLogin(EmployeesList emp);
        Employee GetUserIn() const {return(userin.value());};
        
        Login(){};

};

// © Mary E Tyler 2026