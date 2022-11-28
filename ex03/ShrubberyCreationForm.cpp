#include "ShrubberyCreationForm.hpp"
#include <fstream>

#define BLANK " "
#define LEAF = "#"
#define WOOD = "|"

ShrubberyCreationForm::ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name)
:Form(name, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &data)
:Form(data.getName(), data.getNeedGradeToSign(), data.getNeedGradeToExec())
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm & ShrubberyCreationForm::operator= (const ShrubberyCreationForm &data)
{
    (void)data;
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getNeedGradeToExec())
        throw Form::GradeTooLowException();
    else if (!this->getIsSign())
        throw Form::FormNotSignedException();

    std::string filename = this->getName() + "_shrubbery";
    this->drawAsciiTree(filename);
}

void ShrubberyCreationForm::drawAsciiTree(std::string filename) const
{
    std::ofstream ofs(filename, std::ios::trunc | std::ios::out);

	if (!ofs.is_open())
	{
		std::cout << "file open failed" << std::endl;
		exit(0);
	}
    int trHight = 10;
    int branchLine = 1;
    int treeHeight = trHight;

    while (branchLine <= (trHight - 2))
    {
        drawALineOfFoliage(treeHeight, ofs);
        branchLine += 1;
    }
    drawTrunk(trHight, ofs);
    ofs.close();
}

void ShrubberyCreationForm::drawTrunk(int trHgt, std::ofstream &ofs) const
{
    int trunkLine = 1;
    int spaces;

    while (trunkLine <= 2) 
    {
        spaces = 1;

        while (spaces <= (trHgt - 2))  
        {
            ofs << BLANK;
            spaces += 1;
        }

        ofs << "|";     
        ofs << std::endl;          
        trunkLine += 1;
    }
}

void ShrubberyCreationForm::drawALineOfFoliage(int trHight, std::ofstream &ofs) const
{
    int treeHeight = trHight;
    int spaces = trHight - 2;

    for (int i = 0; i < (treeHeight - 2); i++) {
        for (int j = spaces; j > 0; j--)
        {
            ofs << " ";
        }
        for (int foliage = 0; foliage <= i * 2; foliage++)
        {
            ofs << "#";
        }
        spaces--;
        ofs << std::endl;
    }
}