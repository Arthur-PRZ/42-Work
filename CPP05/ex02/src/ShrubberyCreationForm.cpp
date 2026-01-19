#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("defaultSCR", 145, 137, false), _target("defaultTarget") 
{
    std::cout << "SCF default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("SCR", 145, 137, false), _target(target)
{
    std::cout << "SCF constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target)
{
    std::cout << "SCF copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &shrub)
{
    std::cout << "SCF opetato = called" << std::endl;
    if (this != &shrub)
    {
        AForm::operator=(shrub);
        _target = shrub._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "SCF destructor Called" << std::endl; 
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    if (!this->getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > this->getGradeRequiredTeExe())
        throw GradeTooLowException();

    std::string fileName = _target + "_shrubbery";
    std::ofstream file(fileName.c_str());
    if (!file)
        return ;
    file << "      *\n"
            "     ***\n"
            "    *****\n"
            "   *******\n"
            "  *********\n"
            "      |\n"
            "      |\n";
    file.close();
}
