#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Employee.h"
#include "Login.h"
#include "Permissions.h"
#include "EmployeesList.h"
#include "Menu.h"


int main() {
    // Classic entry poin for the program

    std::cout << "Employee Management System running..." << std::endl;
    EmployeesList employees;
    std::string command = "exit";

    // seeds the random number generator
    std::srand(std::time(nullptr));

    do // main event loop
    {
        Login login;
        // returns -2 (exit) or 1 (a user has logged in)
        if (login.ProcessLogin(employees) != 1) {break;} 
        Menu menu(login.GetUserIn());
        do  // Main session loop
        {
            menu.PrintMenu();
            command = menu.GetMenuSelection();
            if (command == "logout") {break;};
            if (command == "exit"){break;};
            menu.ProcessSelectedCommand(command, login, employees);

        } while (true);
    } while (command != "exit");
    
    std::cout << "Thank you for running the EMS. Bye!\n\n";
    return(0);
};

// © Mary E Tyler 2026