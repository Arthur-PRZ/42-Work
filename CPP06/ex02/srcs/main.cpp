#include "../incs/A.hpp"
#include "../incs/B.hpp"
#include "../incs/C.hpp"
#include "../incs/Base.hpp"
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
    std::srand(std::time(nullptr));
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
    
}
int main()
{

}