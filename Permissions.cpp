#include "Permissions.h"

bool Permissions::MayView()     const { return view; }
bool Permissions::MaySearch()   const { return search; }
bool Permissions::MayAdd()      const { return add; }
bool Permissions::MayModify()   const { return modify; }
bool Permissions::MayRemove()   const { return remove; }

Permissions::Permissions(bool mview, bool msearch, bool madd, bool mmod, bool mrem)
{
    view = mview;
    search = msearch;
    add = madd;
    modify = mmod;
    remove = mrem
    
}
