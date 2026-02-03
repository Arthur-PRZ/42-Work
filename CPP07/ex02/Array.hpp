#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_

#include <exception>

template <typename T>
class Array
{
    private :

    T* array;
    unsigned int length;

    public :

    Array();
    Array(unsigned int n);
    Array(const Array &copy);
    Array &operator=(const Array &copy);
    T &operator[](unsigned int n);
    ~Array();

    unsigned int size() const;

    class OutOfBounds : public std::exception
    {
        public :

        const char* what() const throw()
        {
            return "Index out of bounds";
        }
    };
};

#include "Array.tpp"

#endif