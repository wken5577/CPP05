#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &data)
{
	(void) data;
}

Intern::~Intern(){}

Intern & Intern::operator = (const Intern &data)
{
	(void) data;
	return *this;
}

Form * Intern::makeForm(std::string formName, std::string target)
{
	const std::string forms[3] = {"shrubbery", "robotomy", "presidential"};
	int n = -1;
	for(int i = 0; i < 3; i++)
	{
		if(formName == forms[i])
		{
			n = i;
			break;
		}
	}
	switch(n)
	{
		case 0:
			std::cout << "Intern create ShrubberyCreationForm" << std::endl;
			return new ShrubberyCreationForm(target);
		case 1:
			std::cout << "Intern create RobotomyRequestForm" << std::endl;
			return new RobotomyRequestForm(target);
		case 2:
			std::cout << "Intern create PresidentialPardonForm" << std::endl;
			return new PresidentialPardonForm(target);
		default:
			std::cout << "create from failed" << std::endl;
			return NULL;
	}
}
