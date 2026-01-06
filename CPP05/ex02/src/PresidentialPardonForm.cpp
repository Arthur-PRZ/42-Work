#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("defaultPPF", 25, 5, false), _target("defaultTarget")
{
    std::cout << "PPF default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string &target) : AForm("PPF", 25, 5 ,false) , _target(target)
{
    std::cout << "PPF constructor called" << std::endl;
}


PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &PPF)
{
    std::cout << "PPF copy constructor called" << std::endl;
    AForm::operator=(PPF);
    _target = PPF._target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &PPF)
{
    std::cout << "PPF operator = called" << std::endl;
    if (this != &PPF)
    {
        AForm::operator=(PPF);
        _target = PPF._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PPF destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->getGradeRequiredTeExe())
        throw GradeTooLowException();
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}