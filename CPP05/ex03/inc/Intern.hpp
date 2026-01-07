#ifndef _INTERN_HPP_
#define _INTERN_HPP_

#include "AForm.hpp"

class AForm;

class Intern
{
    public :

    Intern();
    Intern(const Intern& copy);
    Intern &operator=(const Intern& copy);
    ~Intern();

    AForm *makeForm(std::string formName, std::string formTarget);
};

#endif