#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("Benjamin"), _grade (150)
{
    std::cout << "Bur Default constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bur)
{
    std::cout << "Operator = called" << std::endl;
    if (this != &bur)
    {
        _grade = bur._grade;
    }
    return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bur) : _name(bur._name), _grade(bur._grade)
{
    std::cout << "Copy onstructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string newName, int newGrade) : _name(newName), _grade(newGrade)
{
    std::cout << "Bur Constructor called" << std::endl;
    if (_grade < 1)
        throw GradeTooHighException();
    else if (_grade > 150)
        throw GradeTooLowException(); 
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bur Destructor called" << std::endl;
}

const std::string &Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::increment()
{
    if (_grade - 1 <= 0)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::executeForm(AForm const &form) const
{
    try 
    {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    }
    catch (const std::exception &execpt)
    {
        std::cout << _name << " couldn't execute " << form.getName() << " because " << execpt.what() << std::endl;
    }
}


void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }           
    catch (const std::exception &execpt)
    {
        std::cout << _name << " couldn't sign " << form.getName() << " because " << execpt.what() << std::endl;
    }
}

void Bureaucrat::decrement()
{
    if (_grade + 1 >= 151)
        throw GradeTooLowException();
    _grade++;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &bur)
{
    out << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".";
    return out;
}