#include "../inc/Intern.hpp"
#include "../inc/AForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"


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

AForm *Intern::CreateRobotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
};

AForm *Intern::CreatePresident(const std::string &target)
{
    return new PresidentialPardonForm(target);
};

AForm *Intern::CreateShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
};

AForm* Intern::makeForm(std::string requestName, std::string requestTarget)
{
    
    struct FormRequest
    {
        std::string formName;
        AForm *(*create)(const std::string& target);
    };
    
    FormRequest findRequest[] =
    {
        {"robotomy request", &Intern::CreateRobotomy},
        {"presidential request", &Intern::CreatePresident},
        {"shrubbery request", &Intern::CreateShrubbery},
    };

    for (int i = 0; i < 3; i++)
    {
        if (findRequest[i].formName == requestName)
        {
            std::cout << "Intern creates " << requestName << std::endl;
            return findRequest[i].create(requestTarget);
        }
    }

    std::cout << requestName << " not found" << std::endl;
    return NULL;
}

