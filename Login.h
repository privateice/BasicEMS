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
        std::optional<Employee> userin = std::nullopt;
    
    public:
        int ProcessAuthentication(EmployeesList emp,
                std::string username, std::string pwd);
        int ProcessLogin(EmployeesList emp);
        Employee GetUserIn() const {return(userin.value());};
        
        Login(){};

};