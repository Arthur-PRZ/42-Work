#include "../inc/Intern.hpp"
#include "../inc/AForm.hpp"

Intern::Intern()
{
    std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern& copy)
{
    std::cout << "Intern copy constructor called" << std::endl;
    (void)copy;
}

Intern &Intern::operator=(const Intern& copy)
{
    std::cout << "Intern operator = called" << std::endl;
    (void)copy;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

AForm* makeForm(std::string formName, std::string formTarget)
{
    
}

