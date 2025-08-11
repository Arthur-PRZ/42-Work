#pragma once

#include <string>
#include <iostream>

class Brain
{
    protected :

    std::string ideas[100];

    public :

    Brain();
    Brain(const Brain& brain);
    Brain operator=(const Brain& brain);
    ~Brain();
};