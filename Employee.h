#include <string>;
#include "Permissions.h"
using namespace std;

class Employee
{
    private:
        string name, username, password;
        int ID;
        Permissions permissions;
        
    public:
        string GetUsername() const;
        string GetName() const;
        string GetPassword() const;
        int GetID()const;
        bool GetPermissions() const;

        Employee(string pname, string puser, string ppwd, 
                int pID, Permissions pperms);


}