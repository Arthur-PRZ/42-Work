#ifndef _SHRUBBERYCREATIONFORM_HPP_
#define _SHRUBBERYCREATIONFORM_HPP_

#include "AForm.hpp"
#include <fstream>


class ShrubberyCreationForm : public AForm
{
    private :

    std::string _target;

    public :

    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm &copy);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm &shrub);
    ~ShrubberyCreationForm();

    void execute(Bureaucrat const& executor) const;
};

#endif