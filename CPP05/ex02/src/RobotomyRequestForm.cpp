#include "../inc/RobotomyRequestForm.hpp"
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("defaultRRF", 72, 45, false), _target("defaultTarget")
{
    std::cout << "RRF default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("defaultRRF", 72, 45, false), _target(target)
{
    std::cout << "RRF constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target)
{
    std::cout << "RRF copy constructeur called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &RRF)
{
    std::cout << "RRF operator = called" << std::endl;
    if (this != &RRF)
    {
        AForm::operator=(RRF);
        _target = RRF._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RRF destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > this->getGradeRequiredTeExe())
        throw GradeTooLowException();
    std::cout << "DDDDRRRRRRRRRRRRRR" << std::endl;
    srand(std::time(NULL));
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized" << std::endl;
    else
        std::cout << "Robotomy failed" << std::endl;
}