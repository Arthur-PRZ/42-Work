#include "Array.hpp"
#include <iostream>

template <typename T>
Array<T>::Array()
{
    array = new T[0];
    length = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    length = n;
    array = new T[n];
}

template <typename T>
Array<T>::Array(const Array &copy) : length(copy.length)
{
    array = new T[length];
    for (unsigned int i = 0; i < length; i++)
        array[i] = copy.array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &copy)
{
    if (this != &copy)
    {
        delete[] array;
        length = copy.length;
        array = new T[length];
        for (unsigned int i = 0; i < length; i++)
            array[i] = copy.array[i];
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int n)
{
    if (n >= length)
        throw OutOfBounds();
    return array[n];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return length;
}

template <typename T>
Array<T>::~Array<T>()
{
    delete[] array;
}

