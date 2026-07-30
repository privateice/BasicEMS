#include "Menu.h"


Menu::Menu(Employee userin)
{   
    menustr = "";
    Permissions perms = userin.GetPermissions();
    if (perms.MayView()){menustr += "To view your record, type 'view'\n";}
    if (perms.MaySearch()){menustr += "To search employees, type 'search'\n";}
    if (perms.MayAdd()){menustr += "To add an employee, type 'add'\n";}
    if (perms.MayModify()){menustr += "To modify an employee, type 'modify'\n";}
    if (perms.MayRemove()){menustr += "To remove an employee, type 'remove'\n";}

};

void Menu::PrintMenu() const
{
    std::cout << menustr << "Please enter a command:\n\n";
};