#ifndef _BUREAUCRAT_HPP_
#define _BUREAUCRAT_HPP_

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat
{
    private :

    const std::string name;
    int grade;

    public :

    Bureaucrat();
    Bureaucrat(const Bureaucrat& bur);
    Bureaucrat(std::string newName, int newGrade);
    Bureaucrat& operator=(const Bureaucrat& bur);
    ~Bureaucrat();

    std::string getName();
    int getGrade();

    void increment();
    void decrement();

    class GradeTooHighException : public std::exception
    {
        public :

        virtual const char* what() const throw()
        {
            return "Grade too hight !";
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

std::ostream &operator<<(std::ostream out,)
#endif