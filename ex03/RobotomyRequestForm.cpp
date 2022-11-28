#include "RobotomyRequestForm.hpp"
#include <random>

RobotomyRequestForm::RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string name)
:Form(name, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &data)
:Form(data.getName(), data.getNeedGradeToSign(), data.getNeedGradeToExec())

{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm & RobotomyRequestForm::operator= (const RobotomyRequestForm &data)
{
    (void)data;
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getNeedGradeToExec())
        throw Form::GradeTooLowException();
    else if (!this->getIsSign())
        throw Form::FormNotSignedException();
    std::cout << "drilling !!!........." << std::endl;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 99);

    if (dis(gen) % 2 == 0)
        std::cout << this->getName() << " has been robotomized!" << std::endl;
    else
        std::cout << this->getName() << " has been failed to robotomized!" << std::endl;
}