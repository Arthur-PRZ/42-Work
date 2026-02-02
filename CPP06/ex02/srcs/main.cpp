#include "../incs/A.hpp"
#include "../incs/B.hpp"
#include "../incs/C.hpp"
#include "../incs/Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate(void)
{
    std::srand(std::time(0));
    int r = std::rand() % 3;

    if (r == 0)
        return new A();
    else if (r == 1)
        return new B();
    else
        return new C();    
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base &p)
{
    try
    {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    catch (...)
    {
    }
    try
    {
        dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    catch (...)
    {
    }
    try
    {
        dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    }
    catch (...)
    {
    }
}

int main()
{
    Base *base;

    base = generate();
    identify(base);
    identify(*base);
    delete base;
}