#include "iter.hpp"
#include "iostream"


template <typename T>
void increment(T &t)
{
    t++;
}

template <typename T>
void print(const T &t)
{
    std::cout << t;
}

int main()
{
    char str[] = "Bonjour";
    int   tab[] = {1, 4, 8, 4};

    iter(tab, 4, print<int>);
    std::cout << std::endl;
    iter(str, 7, print<char>);

    iter(tab, 4, increment<int>);
    iter(str, 7, increment<char>);
    std::cout << std::endl;

    iter(tab, 4, print<int>);
    std::cout << std::endl;
    iter(str, 7, print<char>);
    std::cout << std::endl;
}