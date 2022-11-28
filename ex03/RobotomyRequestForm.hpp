#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{

private:
    RobotomyRequestForm();

public:
    RobotomyRequestForm(std::string name);
    RobotomyRequestForm(const RobotomyRequestForm & data);
    ~RobotomyRequestForm();

    RobotomyRequestForm & operator= (const RobotomyRequestForm &data);

    void execute(Bureaucrat const & executor) const;

};

#endif