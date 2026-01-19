#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

AForm::AForm() : _name("default"), _gradeRequiredToSign(50), _gradeRequiredToExe(100), _isSigned(false)
{
    std::cout << "AForm Default constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm &AForm)
{
    std::cout << "AForm operator = called" << std::endl;
    if (this != &AForm)
    {
        _isSigned = AForm._isSigned;
    }
    return *this;
}

AForm::AForm(const AForm &copy) : _name(copy._name), _gradeRequiredToSign(copy._gradeRequiredToSign), _gradeRequiredToExe(copy._gradeRequiredToExe), _isSigned(copy._isSigned)
{
    std::cout << "AForm Copy constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeRequiredToSign, int gradeRequiredToExe, bool isSigned) : _name(name), _gradeRequiredToSign(gradeRequiredToSign), _gradeRequiredToExe(gradeRequiredToExe), _isSigned(isSigned)
{
    std::cout << "Aform Constructor called" << std::endl;
    if (gradeRequiredToExe < 1 || gradeRequiredToSign < 1)
        throw GradeTooHighException();
    else if (gradeRequiredToExe > 150 || gradeRequiredToSign > 150)
        throw GradeTooLowException(); 
}

AForm::~AForm()
{
    std::cout << "AForm Destructor called" << std::endl;
}

const std::string &AForm::getName() const
{
    return _name;
}

int AForm::getGradeRequiredToSign() const
{
    return _gradeRequiredToSign;
}

int AForm::getGradeRequiredTeExe() const
{
    return _gradeRequiredToExe;
}

bool AForm::getIsSigned() const
{
    return  _isSigned;
}

void AForm::beSigned(Bureaucrat &bur)
{
    if (bur.getGrade() >= _gradeRequiredToSign)
        throw AForm::GradeTooLowException();
    _isSigned = true;
}

std::ostream &operator<<(std::ostream &out, AForm &AForm)
{
    out << AForm.getName() <<  ", AForm  grade required to sign it " << AForm.getGradeRequiredToSign()
        << ", AForm grade required to execute it " << AForm.getGradeRequiredTeExe()
        << (AForm.getIsSigned() ? ", the AForm is signed" : ", the AForm is not signed") << std::endl;
    return out;
}
