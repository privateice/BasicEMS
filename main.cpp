#include "Employee.h"
#include "Login.h"
#include "Permissions.h"
#include "EmployeesList.h"
#include <iostream>




int main() {
    std::cout << "Employee Management System running..." << std::endl;
    EmployeesList employees;

    do
    {
        Login login;
        // returns -2 (exit) or 1 (a user has logged in)
        if (login.ProcessLogin(employees) != 1) {break;} 



    } while (true);
    
    std::cout << "Thank you for running the EMS. Bye!\n\n";
    return 0;
}