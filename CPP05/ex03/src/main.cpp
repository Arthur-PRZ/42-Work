#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/Intern.hpp"

int main()
{   
    Intern intern;

    std::cout << "-------------------------------" << std::endl;
    std::cout << "TRYING PRESIDENTIAL PARDON FORM" << std::endl;
    std::cout << "-------------------------------" << std::endl << std::endl;

    intern.makeForm("president request", "Damien");
    AForm *presidentialForm = intern.makeForm("presidential request", "Damien");
    if (presidentialForm)
    {
        delete presidentialForm;
    }

    std::cout << "----------------------------" << std::endl;
    std::cout << "TRYING ROBOTOMY REQUEST FORM" << std::endl;
    std::cout << "----------------------------" << std::endl << std::endl;

    intern.makeForm("robot request", "Ellen");
    AForm *robotomyForm = intern.makeForm("robotomy request", "Ellen");
    if (robotomyForm)
    {
        delete robotomyForm;
    }

    std::cout << "------------------------------" << std::endl;
    std::cout << "TRYING SHRUBBERY CREATION FORM" << std::endl;
    std::cout << "------------------------------" << std::endl << std::endl;

    intern.makeForm("shrub request", "Maxime");
    AForm *shrubberyForm = intern.makeForm("shrubbery request", "Maxime");
    if (shrubberyForm)
    {
        delete shrubberyForm;
    }

    std::cout << "----------" << std::endl;
    std::cout << "DESTRUCTOR" << std::endl;
    std::cout << "----------" << std::endl << std::endl;

}