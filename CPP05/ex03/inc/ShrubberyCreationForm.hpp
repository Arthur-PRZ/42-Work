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
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &copy);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &shrub);
    ~ShrubberyCreationForm();

    void execute(Bureaucrat const& executor) const;
};

#endif