#pragma once
#include <iostream>
#include <ostream>

class Permissions
{
private:
    bool viewself;
    bool viewother;
    bool search;
    bool add;
    bool modify;
    bool remove;

public:
    bool MayViewSelf() const;
    bool MayViewOther() const;
    bool MaySearch() const;
    bool MayAdd() const;
    bool MayModify() const;
    bool MayRemove() const;
    Permissions(bool mview, bool mviewo, bool msearch, bool madd, bool mmod, bool mrem);
    Permissions();
    static Permissions HRPerms()
        {return Permissions(true, true, true, true, true, true);};
    static Permissions ManagerPerms()
        {return Permissions(true, true, true, false, false, false);};
    static Permissions EmployeePerms()
        {return Permissions(true, false, false, false, false, false);};
};

std::ostream& operator<<(std::ostream& out, const Permissions& perms);
