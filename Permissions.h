#pragma once
#include <iostream>
#include <ostream>

class Permissions
{   // Controls what employees may do in the system.

    private:
        bool viewself;
        bool viewother;
        bool search;
        bool add;
        bool modify;
        bool remove;

    public:
        bool MayViewSelf()     const { return viewself; };
        bool MayViewOther()     const { return viewother; };
        bool MaySearch()   const { return search; };
        bool MayAdd()      const { return add; };
        bool MayModify()   const { return modify; };
        bool MayRemove()   const { return remove; };

        Permissions(bool mview, bool mviewo, bool msearch, bool madd, bool mmod, bool mrem);
        Permissions();

        static Permissions HRPerms()
            {return Permissions(true, true, true, true, true, true);};
        static Permissions ManagerPerms()
            {return Permissions(true, true, true, false, false, false);};
        static Permissions EmployeePerms()
            {return Permissions(true, false, false, false, false, false);};
};

// operator overload for printing permissions
std::ostream& operator<<(std::ostream& out, const Permissions& perms);
