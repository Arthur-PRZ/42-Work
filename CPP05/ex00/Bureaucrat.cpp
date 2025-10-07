#include <Bureaucrat.hpp>
#include <iostream>

Bureaucrat::Bureaucrat() : name("Benjamin"), grade (150)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bur)
{
    if (this != &bur)
    {
        grade = bur.grade;
    }
    return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bur) : name(bur.name), grade(bur.grade)
{
}

Bureaucrat::Bureaucrat(std::string newName, int newGrade) : name(newName), grade(newGrade)
{
    try
    {
        if (grade < 1)
            throw GradeTooHightException();
        else if (grade > 150)
            throw GradeTooLowException(); 
    }
    catch (const Bureaucrat::GradeTooHightException& execpt)
    {
        std::cout << execpt.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& execpt)
    {
        std::cout << execpt.what() << std::endl;
    }
}

Bureaucrat::~Bureaucrat()
{
}

    // std::string Bureaucrat::getName();
    // int Bureaucrat::getGrade();

    // void Bureaucrat::increment(Bureaucrat& bur);
    // void Bureaucrat::decrement(Bureaucrat& bur);