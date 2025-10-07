#ifndef _BUREAUCRAT_HPP_
#define _BUREAUCRAT_HPP_

#include <string>
#include <exception>

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

    void increment(Bureaucrat& bur);
    void decrement(Bureaucrat& bur);

    class GradeTooHightException : public std::exception
    {
        public :

        const char* what() const noexcept override
        {
            return "Grade too hight !";
        }
    };

    class GradeTooLowException : public std::exception
    {
        public :

        const char* what() const noexcept override
        {
            return "Grade too low !";
        }
    };
};

#endif