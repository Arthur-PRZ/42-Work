#ifndef _BUREAUCRAT_HPP_
#define _BUREAUCRAT_HPP_

#include "AForm.hpp"
#include <string>
#include <exception>
#include <iostream>

class AForm;

class Bureaucrat
{
    private :

    const std::string _name;
    int _grade;

    public :

    Bureaucrat();
    Bureaucrat(const Bureaucrat& bur);
    Bureaucrat(std::string newName, int newGrade);
    Bureaucrat& operator=(const Bureaucrat& bur);
    ~Bureaucrat();

    const std::string &getName() const;
    int getGrade() const;

    void increment();
    void decrement();

    void signForm(AForm &form);
    void executeForm(AForm const &form) const;

    class GradeTooHighException : public std::exception
    {
        public :

        virtual const char* what() const throw()
        {
            return "Grade too high !";
        }
    };

    class GradeTooLowException : public std::exception
    {
        public :

        virtual const char* what() const throw()
        {
            return "Grade too low !";
        }
    };
};

std::ostream &operator<<(std::ostream &out, Bureaucrat &bur);
#endif