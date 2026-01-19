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
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &copy);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &RRF);
    ~RobotomyRequestForm();

    void execute(Bureaucrat const & executor) const;
};

#endif