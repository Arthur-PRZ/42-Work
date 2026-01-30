#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data data;
    Data *ptrData = &data;
    data.a = 'a';
    data.i = 42;

    std::cout << "Base value and address" << std::endl;
    std::cout << &data << std::endl;
    std::cout << data.a << std::endl;
    std::cout << data.i << std::endl << std::endl;

    uintptr_t ptr = Serializer::serialize(&data);

    std::cout << "Serialized address" << std::endl;
    std::cout << &ptr << std::endl << std::endl;

    ptrData = Serializer::deserialize(ptr);

    std::cout << "Deserialized value and address" << std::endl;
    std::cout << &ptrData << std::endl;
    std::cout << ptrData->a << std::endl;
    std::cout << ptrData->i << std::endl;
}