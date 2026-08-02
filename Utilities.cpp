#include "Utilities.h"

std::string ToLower(std::string s)
{   // It shocks me in this day and age that you still have to write
    // random string utility functions that should be part of the standard
    //library. This converts a string to all lower case.

    std::transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c)
        {
            return std::tolower(c);
        });

    return s;
};

std::string Trim(std::string s)
{   // This trims white space from the ront and back of a string.
    
    while (!s.empty() && std::isspace(s.front()))
        s.erase(s.begin());

    while (!s.empty() && std::isspace(s.back()))
        s.pop_back();

    return s;
};