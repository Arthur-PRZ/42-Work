#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int main()
{   
    Bureaucrat lumian("Lumian", 2);
    Bureaucrat louis("Louis", 146);

    std::cout << "-------------------------------" << std::endl;
    std::cout << "TRYING PRESIDENTIAL PARDON FORM" << std::endl;
    std::cout << "-------------------------------" << std::endl << std::endl;

    PresidentialPardonForm Pform;

    louis.signForm(Pform);
    lumian.executeForm(Pform);
    lumian.signForm(Pform);
    lumian.executeForm(Pform);

    std::cout << "----------------------------" << std::endl;
    std::cout << "TRYING ROBOTOMY REQUEST FORM" << std::endl;
    std::cout << "----------------------------" << std::endl << std::endl;

    RobotomyRequestForm Rform("Jade");

    louis.signForm(Rform);
    lumian.executeForm(Rform);
    lumian.signForm(Rform);
    lumian.executeForm(Rform);

    std::cout << "------------------------------" << std::endl;
    std::cout << "TRYING SHRUBBERY CREATION FORM" << std::endl;
    std::cout << "------------------------------" << std::endl << std::endl;

    ShrubberyCreationForm Sform;

    louis.signForm(Sform);
    lumian.executeForm(Sform);
    lumian.signForm(Sform);
    lumian.executeForm(Sform);

    std::cout << "-----------" << std::endl;
    std::cout << "DESTRUCTORS" << std::endl;
    std::cout << "-----------" << std::endl << std::endl;

}