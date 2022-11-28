#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "Form.hpp"

class Intern
{

public:
	Intern();
	Intern(const Intern &data);
	~Intern();

	Intern & operator= (const Intern &data);

	Form *makeForm(std::string formName, std::string target);
};

#endif
