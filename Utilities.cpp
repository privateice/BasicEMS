#include "Utilities.h"

std::string ToLower(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c)
        {
            return std::tolower(c);
        });

    return s;
};

std::string Trim(std::string s)
{
    while (!s.empty() && std::isspace(s.front()))
        s.erase(s.begin());

    while (!s.empty() && std::isspace(s.back()))
        s.pop_back();

    return s;
};