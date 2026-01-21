#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main()
{   
    std::cout << "-----------------------" << std::endl;
    std::cout << "TRYING EXCEPTIONS" << std::endl;
    std::cout << "-----------------------" << std::endl << std::endl;
    try
    {
        std::cout << "-----------------------" << std::endl;
        std::cout << "Constructor required grade to signed to low" << std::endl;
        Form formA("TooLow", 151, 1, false);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        std::cout << "-----------------------" << std::endl;
    }

    try
    {
        std::cout << "-----------------------" << std::endl;
        std::cout << "Constructor required grade to execute to low" << std::endl;
        Form L("TooLow", 150, 151, false);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        std::cout << "-----------------------" << std::endl;
    }

    try
    {
        std::cout << "-----------------------" << std::endl;
        std::cout << "Constructor required grade to signed to high" << std::endl;
        Form TL("TooHigh", -1, 4, 0);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        std::cout << "-----------------------" << std::endl;
    }

    try
    {
        std::cout << "-----------------------" << std::endl;
        std::cout << "Constructor required grade to signed to high" << std::endl;
        Form TooLow("TooLow", 1, -4, 0);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        std::cout << "-----------------------" << std::endl;
    }

    try
    {
        std::cout << "-----------------------" << std::endl;
        std::cout << "Grade not enougth to sign" << std::endl;

        Form C("ContactForm", 100, 100, 0);
        Bureaucrat J("Jade", 142);

        J.signForm(C);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        std::cout << "-----------------------" << std::endl;
    }


    std::cout << "---------" << std::endl;
    std::cout << "TRYING IT" << std::endl;
    std::cout << "---------" << std::endl << std::endl;

    std::cout << "-----------------------" << std::endl;

    Form C("JoinForm", 5, 7, 0);
    Bureaucrat A("Aurore", 1);
    std::cout << "-----------------------" << std::endl;

    A.signForm(C);
    std::cout << "-----------------------" << std::endl;

}