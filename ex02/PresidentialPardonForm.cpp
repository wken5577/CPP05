#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string name)
:Form(name, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &data)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm & PresidentialPardonForm::operator= (const PresidentialPardonForm &data)
{
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getNeedGradeToExec())
        throw Form::GradeTooLowException();
    else if (!this->getIsSign())
        throw Form::FormNotSignedException();
    std::cout << this->getName() << " > has been pardoned by Zaphod Beeblebrox." << std::endl;

}