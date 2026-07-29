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
    bool mayView() const;
    bool maySearch() const;
    bool mayAdd() const;
    bool mayModify() const;
    bool mayRemove() const;
};