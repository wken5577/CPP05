#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{

private:
    PresidentialPardonForm();

public:
    PresidentialPardonForm(std::string name);
    PresidentialPardonForm(const PresidentialPardonForm & data);
    ~PresidentialPardonForm();

    PresidentialPardonForm & operator= (const PresidentialPardonForm &data);

    void execute(Bureaucrat const & executor) const;

};

#endif