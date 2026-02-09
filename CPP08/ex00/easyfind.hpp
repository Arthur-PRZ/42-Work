#ifndef _EASYFIND_HPP_
#define _EASYFIND_HPP_

#include <algorithm>

class NoOccurrence : public std::exception
{
    const char* what() const throw()
    {
        return "No occurrence found.";
    }
};

template <typename T>
int easyfind(T &t, int n)
{
    typename T::iterator it;

    it = std::find(t.begin(), t.end(), n);

    if (it == t.end())
        throw NoOccurrence();
    else
        return *it;
}

#endif