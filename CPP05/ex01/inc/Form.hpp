#ifndef _FORM_HPP_
#define _FORM_HPP_

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private :

    const std::string _name;
    const int _gradeRequiredToSign;
    const int _gradeRequiredToExe;
    bool _isSigned;

    public :

    Form();
    Form(Form &copy);
    Form(std::string name, int gradeRequiredToSign, int gradeRequiredToExe, bool isSigned);
    Form &operator=(const Form &form);
    ~Form();

    const std::string &getName();
    int getGradeRequiredToSign();
    int getGradeRequiredTeExe();
    bool getIsSigned();

    void beSigned(Bureaucrat &bur);

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

std::ostream &operator<<(std::ostream &out, Form &form);

#endif