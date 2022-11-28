#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Form f;
	Bureaucrat b("jam", 80);
	b.signForm(f);

	Form f1("form2", 80, 50);
	b.signForm(f1);
}