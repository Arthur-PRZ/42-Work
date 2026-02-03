#ifndef _ITER_HPP_
#define _ITER_HPP_

template <typename T, typename F>
void iter(T *array, const int length, F func)
{
    for (int i = 0; i < length; i++)
        func(array[i]);
}

#endif