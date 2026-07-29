#pragma once

class Permissions
{
private:
    bool view;
    bool search;
    bool add;
    bool modify;
    bool remove;

public:
    bool MayView() const;
    bool MaySearch() const;
    bool MayAdd() const;
    bool MayModify() const;
    bool MayRemove() const;
    Permissions(bool mview, bool msearch, bool madd, bool mmod, bool mrem);

};