#include "Menu.h"
#include "EmployeesList.h"

Menu::Menu(Employee userin)
{   
    menustr = "";
    Permissions perms = userin.GetPermissions();
    if (perms.MayViewSelf()){menustr += "viewself - view your record\n";}
    if (perms.MayViewOther()){menustr += "viewother - view another employee's record\n";}
    if (perms.MaySearch()){menustr += "search - search employees\n";}
    if (perms.MayAdd()){menustr += "add - add an employee\n";}
    if (perms.MayModify()){menustr += "modify - modify an employee\n";}
    if (perms.MayRemove()){menustr += "remove - remove an employee\n";}
    menustr += "logout - Log out of your account\nexit - exit the program\n\n";

};

void Menu::PrintMenu() const 
    { std::cout << menustr;};

std::string Menu::GetMenuSelection() const
{   // reads a command, checks if valid, returns a valid command
    // "valid" does not necessary mean "user has permissions."

    bool valid = false; 
    std::string command = "exit";
    do
    {
        std::cout << "Please enter a valid command:\n";
        std::cin >> command;
        valid = allvalidcommands.count(command);
        if (!valid) {std::cout << "That is not a valid command.\n";}
    } while (!valid);
    return(command);
};

int Menu::ProcessSelectedCommand(std::string command, Login login, EmployeesList& employees)
{   
    if (login.GetUserIn().CheckPermissions(command))
    {
        if (command == "viewself") {employees.ViewSelf(login); return(0);};
        if (command == "viewother") {employees.ViewOther(); return(0);};
        if (command == "search") {employees.Search(); return(0);};
        if (command == "add") {employees.Add(); return(0);};
        if (command == "modify") {employees.Modify(); return(0);};
        if (command == "remove") {employees.Remove(); return(0);};
        // std::cout << "Process commands will happen here.\n";
    }
    else 
    { 
        std::cout << "Sorry, you lack permissions to run the " 
            << command <<" command!\n\n"
            << "You may run the following commands:\n";
    };
    return(0);
};