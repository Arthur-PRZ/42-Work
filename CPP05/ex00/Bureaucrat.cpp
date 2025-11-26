#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : name("Benjamin"), grade (150)
{
    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bur)
{
    std::cout << "Operator = called" << std::endl;
    if (this != &bur)
    {
        grade = bur.grade;
    }
    return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bur) : name(bur.name), grade(bur.grade)
{
    std::cout << "Copy onstructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string newName, int newGrade) : name(newName), grade(newGrade)
{
    std::cout << "Constructor called" << std::endl;
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException(); 
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called" << std::endl;
}

std::string Bureaucrat::getName()
{
    return name;
}

int Bureaucrat::getGrade()
{
    return grade;
}

void Bureaucrat::increment()
{
    grade--;
    if (grade <= 0)
        throw GradeTooHighException();
}

void Bureaucrat::decrement()
{
    grade++;
    if (grade >= 151)
        throw GradeTooLowException();
}