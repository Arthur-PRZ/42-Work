#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("Benjamin"), _grade (150)
{
    std::cout << " Bureaucrat default constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bur)
{
    std::cout << "Bureaucrat operator = called" << std::endl;
    if (this != &bur)
    {
        _grade = bur._grade;
    }
    return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bur) : _name(bur._name), _grade(bur._grade)
{
    std::cout << "Bureaucrat copy onstructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string newName, int newGrade) : _name(newName), _grade(newGrade)
{
    std::cout << "Bureaucrat constructor called" << std::endl;
    if (_grade < 1)
        throw GradeTooHighException();
    else if (_grade > 150)
        throw GradeTooLowException(); 
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
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

void Bureaucrat::signForm(Form &form)
{
    if (form.beSigned(*this) == true)
    {
        std::cout << _name << " signed " << form.getName() << std::endl;           
    }
    else
    {
        std::cout << _name << " couldn't sign " << form.getName() << " because this form is already signed." << std::endl;
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