#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{


private:
    ShrubberyCreationForm();
    void drawAsciiTree(std::string filename) const;
    void drawALineOfFoliage(int trHight, int brLine) const;
    void drawTrunk(int trHgt) const;

public:
    ShrubberyCreationForm(std::string name);
    ShrubberyCreationForm(const ShrubberyCreationForm & data);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm & operator= (const ShrubberyCreationForm &data);

    void execute(Bureaucrat const & executor) const;

};

#endif