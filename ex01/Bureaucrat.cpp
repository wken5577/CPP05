#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

Bureaucrat::Bureaucrat()
:name("bName"), grade(150)
{}

Bureaucrat::Bureaucrat(std::string name)
:name(name), grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
    this->name = name;
    if (grade < 1) 
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &data)
{
    *this = data;
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat& Bureaucrat::operator= (const Bureaucrat &data)
{
    this->grade = data.grade;
    this->name = data.name;
    return *this;
}

std::string Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::incGrade()
{
    if (grade == 1)
        throw GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decGrade()
{
    if (grade == 150)
        throw GradeTooLowException();
    this->grade++;
}

void Bureaucrat::signForm(Form f)
{
    try
    {
        f.beSigned(*this);
        std::cout << this->getName() << " signed " << f.getName() << std::endl;
    }
    catch(Form::GradeTooLowException &e)
    {
         std::cout << this->getName() << " couldn't sign " << f.getName() << \
         " because your grade is low" << std::endl; 
    }
}

const char * Bureaucrat::GradeTooHighException::what() const
{
    return "Grade is too high!!!";
}

const char * Bureaucrat::GradeTooLowException::what() const
{
    return "Grade is too low!!!";
}

std::ostream & operator << (std::ostream &os, const Bureaucrat &data)
{
    os << data.getName() << ", bureaucrat grade " << data.getGrade();
    return os;
}