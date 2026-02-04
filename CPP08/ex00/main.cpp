#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> vec;
    vec.push_back(3);
    vec.push_back(23);
    vec.push_back(42);
    vec.push_back(9);

    int found = easyfind(vec, 42);
    std::cout << found << std::endl;

    int notFound = easyfind(vec, 0);
    std::cout << notFound << std::endl;
}