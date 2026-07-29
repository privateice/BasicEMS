#include "Employee.h"
#include <functional>
#include <string>



Employee::Employee(string pname, string puser, string ppwd, int pID, Permissions pperms)
{
    std::hash<std::string> hasher;
    name = pname;
    username = puser;
    password = hasher(ppwd);
    ID = pID;
    permissions = pperms;
};

string Employee::GetUsername() const{ return(username);};
string Employee::GetName() const{ return(name);};
string Employee::GetPassword() const{ return(password);};
int Employee::GetID()const{ return(ID);};
