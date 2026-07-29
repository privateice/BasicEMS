#include "Permissions.h"

bool Permissions::mayView()     const { return view; }
bool Permissions::maySearch()   const { return search; }
bool Permissions::mayAdd()      const { return add; }
bool Permissions::mayModify()   const { return modify; }
bool Permissions::mayRemove()   const { return remove; }
