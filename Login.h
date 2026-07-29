#pragma once
#include <string>
#include <vector>
#include "Employee.h"

class Login
{
    private:
        int FindUser(std::string username, 
                    std::vector<Employee> employees) const;
        int CheckPassword(std::string pwd, Employee emp) const;
    
    public:
        int ProcessLogin( std::vector<Employee> employees,
                                std::string username, 
                                std::string pwd
                                ) const;
        Login(std::vector<Employee> employees);


};