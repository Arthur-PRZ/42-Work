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
    AForm(const AForm &copy);
    AForm(std::string name, int gradeRequiredToSign, int gradeRequiredToExe, bool isSigned);
    AForm &operator=(const AForm &form);
    virtual ~AForm();

    const std::string &getName() const;
    int getGradeRequiredToSign() const;
    int getGradeRequiredTeExe() const;
    bool getIsSigned() const;

    void beSigned(Bureaucrat &bur);
    virtual void execute(Bureaucrat const& executor) const = 0;

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

    class FormNotSignedException : public std::exception
    {
        public :

        virtual const char* what() const throw()
        {
            return "Form not signed !";
        }
    };
};

std::ostream &operator<<(std::ostream &out, AForm &form);

#endif