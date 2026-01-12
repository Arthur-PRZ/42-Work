#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

Form::Form() : _name("default"), _gradeRequiredToSign(50), _gradeRequiredToExe(100), _isSigned(false)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form& Form::operator=(const Form &form)
{
    std::cout << "Form operator = called" << std::endl;
    if (this != &form)
    {
        _isSigned = form._isSigned;
    }
    return *this;
}

Form::Form(Form &copy) : _name(copy._name), _gradeRequiredToSign(copy._gradeRequiredToSign), _gradeRequiredToExe(copy._gradeRequiredToExe), _isSigned(copy._isSigned)
{
    std::cout << "Form copy constructor called" << std::endl;
}

Form::Form(std::string name, int gradeRequiredToSign, int gradeRequiredToExe, bool isSigned) : _name(name), _gradeRequiredToSign(gradeRequiredToSign), _gradeRequiredToExe(gradeRequiredToExe), _isSigned(isSigned)
{
    std::cout << "Constructor called" << std::endl;
    if (gradeRequiredToExe < 1 || gradeRequiredToSign < 1)
        throw GradeTooHighException();
    else if (gradeRequiredToExe > 150 || gradeRequiredToSign > 150)
        throw GradeTooLowException(); 
}

Form::~Form()
{
    std::cout << "Form Destructor called" << std::endl;
}

const std::string &Form::getName()
{
    return _name;
}

int Form::getGradeRequiredToSign()
{
    return _gradeRequiredToSign;
}

int Form::getGradeRequiredTeExe()
{
    return _gradeRequiredToExe;
}

bool Form::getIsSigned()
{
    return  _isSigned;
}

bool Form::beSigned(Bureaucrat &bur)
{
    if (bur.getGrade() <= _gradeRequiredToSign && _isSigned == false)
    {
        _isSigned = true;
        return true;
    }
    else if (bur.getGrade() > _gradeRequiredToSign)
    {
        throw Form::GradeTooLowException();
    }
    return false;
}

std::ostream &operator<<(std::ostream &out, Form &form)
{
    out << form.getName() <<  ", form  grade required to sign it " << form.getGradeRequiredToSign()
        << ", form grade required to execute it " << form.getGradeRequiredTeExe()
        << (form.getIsSigned() ? ", the form is signed" : ", the form is not signed") << std::endl;
    return out;
}
