#include "Form.hpp"
Form::Form()
:name("form"), isSign(false), needGradeToSign(150), needGradeToExec(150)
{
}

Form::Form(std::string name, int needSign, int needExec)
:name(name), isSign(false), needGradeToSign(needSign), needGradeToExec(needExec)
{
    if (needSign < 1 || needExec < 1) 
        throw Form::GradeTooHighException();
    else if (needSign > 150 || needExec > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &data)
:name(data.name), isSign(data.isSign), needGradeToSign(data.needGradeToSign) \
    , needGradeToExec(data.needGradeToExec)
{
}

Form::~Form(){}

Form & Form::operator= (const Form &data)
{
    (void) data;
    return *this;
}

const char * Form::GradeTooHighException::what() const
{
    return "Grade is too high!!!";
}

const char * Form::GradeTooLowException::what() const
{
    return "Grade is too low!!!";
}

const char * Form::FormNotSignedException::what() const
{
    return "form not signed!!!!!";
}

std::string Form::getName() const
{
    return this->name;
}

bool Form::getIsSign() const
{
    return this->isSign;
}

int Form::getNeedGradeToExec() const
{
    return this->needGradeToExec;
}

int Form::getNeedGradeToSign() const
{
    return this->needGradeToSign;
}


void Form::beSigned(Bureaucrat b)
{
    if (b.getGrade() <= this->needGradeToSign)
        this->isSign = true;
    else
        throw Form::GradeTooLowException();
}

std::ostream & operator << (std::ostream &os, const Form &data)
{
    os << "form = "<< data.getName() << " isSign = " << data.getIsSign() << \
    " needGradeToSign = " << data.getNeedGradeToSign() << " needGradeToExec = " << data.getNeedGradeToExec();
    return os;
}