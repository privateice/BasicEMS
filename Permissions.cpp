#include "Permissions.h"

bool Permissions::MayViewSelf()     const { return viewself; };
bool Permissions::MayViewOther()     const { return viewother; };
bool Permissions::MaySearch()   const { return search; };
bool Permissions::MayAdd()      const { return add; };
bool Permissions::MayModify()   const { return modify; };
bool Permissions::MayRemove()   const { return remove; };

Permissions::Permissions(bool mview, bool mviewo, bool msearch, bool madd, bool mmod, bool mrem)
{
    viewself = mview;
    viewother = mviewo;
    search = msearch;
    add = madd;
    modify = mmod;
    remove = mrem;
};

Permissions::Permissions()
{
    viewself = true;
    viewother = false;
    search = false;
    add = false;
    modify = false;
    remove = false;
};

std::ostream& operator<<(std::ostream& out, const Permissions& perms)
{
    out << "\tView Self: " << (perms.MayViewSelf() ? "yes" : "no") << "\n\t\t\t"
        << "Search: " << (perms.MaySearch() ? "yes" : "no") << "\t"
        << "View Other: " << (perms.MayViewOther() ? "yes" : "no") << "\n\t\t\t"
        << "Add: " << (perms.MayAdd() ? "yes" : "no") << "\t\t"
        << "Modify: " << (perms.MayModify() ? "yes" : "no") << "\t\t"
        << "Remove: " << (perms.MayRemove() ? "yes" : "no")
        << "\n";

    return out;
}