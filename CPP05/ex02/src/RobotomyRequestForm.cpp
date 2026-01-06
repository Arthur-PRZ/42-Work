#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("defaultRRF", 72, 45, false), _target("defaultTarget")
{
    std::cout << "RRF default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string &target) : AForm("defaultRRF", 72, 45, false), _target(target)
{
    std::cout << "RRF constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy)
{
    std::cout << "RRF copy constructeur called" << std::endl;
    AForm::operator=(copy);
    _target = copy._target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &RRF)
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
    if (executor.getGrade() > this->getGradeRequiredTeExe())
        throw GradeTooLowException();
    std::cout << "DDDDRRRRRRRRRRRRRR" << std::endl;
    bool sucess = rand() % 2;
    if (sucess == 0)
        std::cout << _target << " has been robotomized" << std::endl;
    else
        std::cout << "Robotomy failed" << std::endl;
}