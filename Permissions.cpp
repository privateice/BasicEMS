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

std::ostream& operator<<(std::ostream& out, const Permissions& perms)
{
    out << "View Self: " << (perms.MayViewSelf() ? "yes" : "no")
        << " View Other: " << (perms.MayViewOther() ? "yes" : "no")
        << " Search: " << (perms.MaySearch() ? "yes" : "no")
        << " Add: " << (perms.MayAdd() ? "yes" : "no")
        << " Modify: " << (perms.MayModify() ? "yes" : "no")
        << " Remove: " << (perms.MayRemove() ? "yes" : "no")
        << "\n";

    return out;
}