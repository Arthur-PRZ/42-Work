#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("Benjamin"), _grade (150)
{
    std::cout << "Default constructor called" << std::endl;
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
    std::cout << "Constructor called" << std::endl;
    if (_grade < 1)
        throw GradeTooHighException();
    else if (_grade > 150)
        throw GradeTooLowException(); 
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called" << std::endl;
}

const std::string &Bureaucrat::getName()
{
    return _name;
}

int Bureaucrat::getGrade()
{
    return _grade;
}

void Bureaucrat::increment()
{
    if (_grade - 1 <= 0)
        throw GradeTooHighException();
    _grade--;

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