#include "Permissions.h"


Permissions::Permissions(bool mview, bool mviewo, bool msearch, bool madd, bool mmod, bool mrem)
{   // Constructor with individual settings

    viewself = mview;
    viewother = mviewo;
    search = msearch;
    add = madd;
    modify = mmod;
    remove = mrem;
};

Permissions::Permissions()
{   // default constructor only permits viewself

    viewself = true;
    viewother = false;
    search = false;
    add = false;
    modify = false;
    remove = false;
};

std::ostream& operator<<(std::ostream& out, const Permissions& perms)
{   // operator override to print permissions

    out << "\tView Self: " << (perms.MayViewSelf() ? "yes" : "no") << "\n\t\t\t"
        << "Search: " << (perms.MaySearch() ? "yes" : "no") << "\t"
        << "View Other: " << (perms.MayViewOther() ? "yes" : "no") << "\n\t\t\t"
        << "Add: " << (perms.MayAdd() ? "yes" : "no") << "\t\t"
        << "Modify: " << (perms.MayModify() ? "yes" : "no") << "\t\t"
        << "Remove: " << (perms.MayRemove() ? "yes" : "no")
        << "\n";

    return out;
};

// © Mary E Tyler 2026