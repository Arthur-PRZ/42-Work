#ifndef _FORM_HPP_
#define _FORM_HPP_

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private :

    const std::string _name;
    const int _gradeRequiredToSign;
    const int _gradeRequiredToExe;
    bool _isSigned;

    public :

    AForm();
    AForm(Form &copy);
    AForm(std::string name, int gradeRequiredToSign, int gradeRequiredToExe, bool isSigned);
    AForm &operator=(const AForm &form);
    virtual ~AForm();

    const std::string &getName();
    int getGradeRequiredToSign();
    int getGradeRequiredTeExe();
    bool getIsSigned();

    bool beSigned(Bureaucrat &bur);
    virtual void execute(Bureaucrat const& executor) const = 0;

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

std::ostream &operator<<(std::ostream &out, Form &form);

#endif