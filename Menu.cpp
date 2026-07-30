#include "Menu.h"


void Menu::PrintMenu(Employee userin) const
{
    Permissions perms = userin.GetPermissions();
    if (perms.MayView()){std::cout << "To view your record, type 'view'\n";}
    if (perms.MaySearch()){std::cout << "To search employees, type 'search'\n";}
    if (perms.MayAdd()){std::cout << "To add an employee, type 'add'\n";}
    if (perms.MayModify()){std::cout << "To modify an employee, type 'modify'\n";}
    if (perms.MayRemove()){std::cout << "To remove an employee, type 'remove'\n";}
    std::cout << "Please enter a command:\n";
};