#include "Employee.h"
#include "Login.h"
#include "Permissions.h"
#include "EmployeesList.h"
#include "Menu.h"
#include <iostream>




int main() {
    std::cout << "Employee Management System running..." << std::endl;
    EmployeesList employees;
    std::string command = "exit";

    do // main event loop
    {
        Login login;
        // returns -2 (exit) or 1 (a user has logged in)
        if (login.ProcessLogin(employees) != 1) {break;} 
        Menu menu(login.GetUserIn());
        do
        {
            menu.PrintMenu();
            command = menu.GetMenuSelection();
            if (command == "exit"){break;};
            menu.ProcessSelectedCommand(command, login, employees);

        } while (true);
        
        std::cout << "After the erase\n";
        employees.PrintEmployeesListShort(employees.GetEmployees());




    } while (command != "exit");
    
    std::cout << "Thank you for running the EMS. Bye!\n\n";
    return 0;
}