#include "Menu.h"
#include "EmployeesList.h"

Menu::Menu(Employee userin)
{   // Sets the menu for a logged-in user (userin), taking into account
    // what permissions the user has. 

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

// Prints the permitted menu commands
// Probably could have been done with an operator override, but oh well...
void Menu::PrintMenu() const 
    { std::cout << menustr;};

std::string Menu::GetMenuSelection() const
{   // reads a command, checks if valid, returns a valid command
    // "valid" does not mean "user has permissions."

    bool valid = false; 
    std::string command = "exit";
    do
    {
        std::cout << "Please enter a valid command:\n";
        std::getline(std::cin >> std::ws, command);
        valid = allvalidcommands.count(command);
        if (!valid) {std::cout << "That is not a valid command.\n";}
    } while (!valid);
    return(command);
};

int Menu::ProcessSelectedCommand(std::string command, Login login, EmployeesList& employees)
{   // Checks permissions to execute the command
    // Processes command and calls appropriate command handler
    //In:   
    //  std::string command - the command
    //  Login login - the login object containing the 
    //      currently logged in employee
    //  EmployeesList employees - the current list of all employees
    if (login.GetUserIn().CheckPermissions(command))
    {
        if (command == "viewself") {employees.ViewSelf(login); return(0);};
        if (command == "viewother") {employees.ViewOther(); return(0);};
        if (command == "search") {employees.Search(); return(0);};
        if (command == "add") {employees.Add(login); return(0);};
        if (command == "modify") {employees.Modify(login); return(0);};
        if (command == "remove") {employees.Remove(); return(0);};
    }
    else 
    { 
        std::cout << "Sorry, you lack permissions to run the " 
            << command <<" command!\n\n"
            << "You may run the following commands:\n";
    };
    return(0);
};