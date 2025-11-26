#include "Bureaucrat.hpp"

int main()
{   
    std::cout << "-----------------------" << std::endl;
    std::cout << "TRYING BASIC CONSTRUCTOR/DESTRUCTOR" << std::endl;
    std::cout << "-----------------------" << std::endl << std::endl;

    std::cout << "-----------------------" << std::endl;
    std::cout << "Default constructor" << std::endl;
    Bureaucrat defaultBur;
    std::cout << defaultBur.getName() << " est grade " << defaultBur.getGrade() << std::endl;
    
    std::cout << "-----------------------" << std::endl;
    std::cout << "Constructor" << std::endl;
    Bureaucrat G("Gustave", 42);
    std::cout << G.getName() << " est grade " << G.getGrade() << std::endl;

    std::cout << "-----------------------" << std::endl;
    std::cout << "Copy constructor" << std::endl;
    Bureaucrat copy(G);
    std::cout << copy.getName() << " est grade " << copy.getGrade() << std::endl;

    std::cout << "-----------------------" << std::endl;
    std::cout << "Operator = (Gustave = default)" << std::endl;
    G = defaultBur;
    std::cout << G.getName() << " est grade " << G.getGrade() << std::endl << std::endl;

    std::cout << "-----------------------" << std::endl;
    std::cout << "TRYING EXCEPTIONS" << std::endl;
    std::cout << "-----------------------" << std::endl << std::endl;
    try
    {
        std::cout << "-----------------------" << std::endl;
        std::cout << "Constructor too low" << std::endl;
        Bureaucrat("TooLow", 151);
    }
    catch (const Bureaucrat::GradeTooLowException& execpt)
    {
        std::cout << execpt.what() << std::endl;
        std::cout << "-----------------------" << std::endl;
    }

    try
    {
        std::cout << "-----------------------" << std::endl;
        std::cout << "Constructor too high" << std::endl;
        Bureaucrat("TooLow", -1);
    }
    catch (const Bureaucrat::GradeTooHighException& execpt)
    {
        std::cout << execpt.what() << std::endl;
        std::cout << "-----------------------" << std::endl;
    }

    try
    {
        std::cout << "-----------------------" << std::endl;
        std::cout << "Increment too low" << std::endl;
        Bureaucrat L("IncrementTooLow", 150);
        L.decrement();
    }
    catch (const Bureaucrat::GradeTooLowException& execpt)
    {
        std::cout << execpt.what() << std::endl;
        std::cout << "-----------------------" << std::endl;
    }

    try
    {
        std::cout << "-----------------------" << std::endl;
        std::cout << "Increment too high" << std::endl;
        Bureaucrat H("IncrementTooHigh", 1);
        H.increment();
    }
    catch (const Bureaucrat::GradeTooHighException& execpt)
    {
        std::cout << execpt.what() << std::endl;
        std::cout << "-----------------------" << std::endl;
    }
}