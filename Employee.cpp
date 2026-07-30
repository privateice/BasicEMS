#include "Employee.h"


Employee::Employee(std::string pname, std::string puser, 
            std::string ppwd, int pID, Permissions pperms)
            : permissions(pperms)
{
    std::hash<std::string> hasher;
    name = pname;
    username = puser;
    password = hasher(ppwd);
    ID = pID;
};

std::string Employee::GetUsername() const{ return(username);};
std::string Employee::GetName() const{ return(name);};
size_t Employee::GetPassword() const{ return(password);};
int Employee::GetID() const{ return(ID);};
Permissions Employee::GetPermissions() const {return(permissions);};


bool Employee::CheckPassword(std::string pwd) const
{   // check if the password matches: true if yes, false if no
    std::hash<std::string> hasher;
    if (hasher(pwd) == password) {return(true);}
    return(false);
};
