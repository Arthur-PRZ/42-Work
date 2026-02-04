#ifndef _EASYFIND_HPP_
#define _EASYFIND_HPP_

#include <algorithm>

template <typename T>
int easyfind(T &t, int n)
{
    typename T::iterator it;

    it = std::find(t.begin(), t.end(), n);

    if (it == t.end())
        return -1;
    else
        return *it;
}

#endif