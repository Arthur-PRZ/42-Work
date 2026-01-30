#ifndef _SERIALIZER_HPP_
#define _SERIALIZER_HPP_

#include <stdint.h>

typedef struct sData
{
    int i;
    char a;
} Data;

class Serializer
{
    private :

    Serializer();
    Serializer(const Serializer &copy);
    Serializer &operator=(const Serializer &copy);
    ~Serializer();
    
    public :

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif