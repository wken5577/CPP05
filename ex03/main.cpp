#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "Form.hpp"
#include "Intern.hpp"

int main()
{
	Intern i;
	Bureaucrat b1("bur", 137);
	// Form *shrubberyForm = i.makeForm("shrubbery", "sur");
	// if (shrubberyForm)
	// {
	// 	b1.signForm(shrubberyForm);
	// 	b1.executeForm(*shrubberyForm);
	// }

	Bureaucrat b2("bur2", 45);
	Form *robotomyForm = i.makeForm("robotomy", "robo");
	b2.signForm(robotomyForm);
	b2.executeForm(*robotomyForm);

}