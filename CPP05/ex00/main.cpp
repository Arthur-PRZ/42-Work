#include "Bureaucrat.hpp"

int main()
{   
    std::cout << "-----------------------" << std::endl;
    std::cout << "TRYING BASIC CONSTRUCTOR/DESTRUCTOR" << std::endl;
    std::cout << "-----------------------" << std::endl << std::endl;

    std::cout << "-----------------------" << std::endl;
    std::cout << "Default constructor" << std::endl;
    Bureaucrat defaultBur;
    std::cout << defaultBur << std::endl;
    
    std::cout << "-----------------------" << std::endl;
    std::cout << "Constructor" << std::endl;
    Bureaucrat G("Gustave", 42);
    std::cout << G << std::endl;

    std::cout << "-----------------------" << std::endl;
    std::cout << "Copy constructor" << std::endl;
    Bureaucrat copy(G);
    std::cout << copy << std::endl;

    std::cout << "-----------------------" << std::endl;
    std::cout << "Operator = (Gustave = default)" << std::endl;
    G = defaultBur;
    std::cout << G << std::endl << std::endl;

    std::cout << "-----------------------" << std::endl;
    std::cout << "TRYING EXCEPTIONS" << std::endl;
    std::cout << "-----------------------" << std::endl << std::endl;
    try
    {
        std::cout << "-----------------------" << std::endl;
        std::cout << "Constructor too low" << std::endl;
        Bureaucrat g("TooLow", 151);
        std::cout << g;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        std::cout << "-----------------------" << std::endl;
    }

    try
    {
        std::cout << "-----------------------" << std::endl;
        std::cout << "Constructor too high" << std::endl;
        Bureaucrat("TooHigh", -1);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        std::cout << "-----------------------" << std::endl;
    }

    try
    {
        std::cout << "-----------------------" << std::endl;
        std::cout << "Increment too low" << std::endl;
        Bureaucrat L("IncrementTooLow", 150);
        L.decrement();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        std::cout << "-----------------------" << std::endl;
    }

    try
    {
        std::cout << "-----------------------" << std::endl;
        std::cout << "Increment too high" << std::endl;
        Bureaucrat H("IncrementTooHigh", 1);
        std::cout << H << std::endl;
        H.increment();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        std::cout << "-----------------------" << std::endl;
    }

    G.increment();
    G.decrement();
    std::cout << G << std::endl;
}