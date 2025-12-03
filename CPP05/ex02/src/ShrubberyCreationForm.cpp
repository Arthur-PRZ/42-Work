#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("defaultSCR", 145, 137, false), _target("defaultTarget") 
{
    std::cout << "SCF default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("SCR", 145, 137, false), _target(target)
{
    std::cout << "SCF constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &copy)
{
    std::cout << "SCF copy constructor called" << std::endl;
    AForm::operator=(copy);
    _target = copy._target;
}


ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &shrub)
{
    std::cout << "SCF opetato = called" << std::endl;
    if (this != &shrub)
    {
        AForm::operator=(shrub);
        _target = shrub._target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    if (getIsSigned() == false)
    {

    }
}