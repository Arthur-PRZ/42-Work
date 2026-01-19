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

    try
    {
        louis.signForm(Pform);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Pform.execute(lumian);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    lumian.signForm(Pform);
    lumian.signForm(Pform);
    lumian.executeForm(Pform);

    std::cout << "----------------------------" << std::endl;
    std::cout << "TRYING ROBOTOMY REQUEST FORM" << std::endl;
    std::cout << "----------------------------" << std::endl << std::endl;

    RobotomyRequestForm Rform("Jade");

    try
    {
        louis.signForm(Rform);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Rform.execute(lumian);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    lumian.signForm(Rform);
    lumian.signForm(Rform);
    lumian.executeForm(Rform);

    std::cout << "-----------------------" << std::endl;
    std::cout << "TRYING SHRUBBERY CREATION FORM" << std::endl;
    std::cout << "-----------------------" << std::endl << std::endl;

    ShrubberyCreationForm Sform;

    try
    {
        louis.signForm(Sform);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Sform.execute(lumian);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }


    lumian.signForm(Sform);
    lumian.signForm(Sform);
    lumian.executeForm(Sform);

    // std::cout << "----------" << std::endl;
    // std::cout << "DESTRUCTOR" << std::endl;
    // std::cout << "----------" << std::endl << std::endl;

}