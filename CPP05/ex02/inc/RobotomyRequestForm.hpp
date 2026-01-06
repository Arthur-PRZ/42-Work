#ifndef _ROBOTOMYREQUESTFORM_HPP_
#define _ROBOTOMYREQUESTFORM_HPP_

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
    private :

    std::string _target;

    public :

    RobotomyRequestForm();
    RobotomyRequestForm(std::string &target);
    RobotomyRequestForm(RobotomyRequestForm &copy);
    RobotomyRequestForm &operator=(RobotomyRequestForm &RRF);
    ~RobotomyRequestForm();

    void execute(Bureaucrat const & executor) const;
};

#endif