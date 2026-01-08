#ifndef _PRESIDENTIALPARDONFORM_HPP_
#define _PRESIDENTIALPARDONFORM_HPP_

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private :

    std::string _target;

    public :

    PresidentialPardonForm();
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(PresidentialPardonForm &copy);
    PresidentialPardonForm &operator=(PresidentialPardonForm &PPF);
    ~PresidentialPardonForm();

    void execute(Bureaucrat const & executor) const;
};

#endif