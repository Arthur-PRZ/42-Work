#ifndef _INTERN_HPP_
#define _INTERN_HPP_

#include "AForm.hpp"

class Intern
{
    private :

    AForm *CreateRobotomy(const std::string &target);
    AForm *CreateShrubbery(const std::string &target);
    AForm *CreatePresident(const std::string &target);

    public :

    Intern();
    Intern(const Intern& copy);
    Intern &operator=(const Intern& copy);
    ~Intern();

    AForm *makeForm(std::string requestName, std::string requestTarget);
};

#endif