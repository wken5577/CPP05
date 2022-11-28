#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
private:
    const std::string   name;
    bool                isSign;
    const int           needGradeToSign;
    const int           needGradeToExec;

public:
    Form();
    Form(std::string name, int needSign, int needExec);
    Form(const Form &data);
    ~Form();

    Form & operator= (const Form &data);

    std::string getName() const;
    bool        getIsSign() const;
    int   getNeedGradeToSign() const;
    int   getNeedGradeToExec() const;

    void    beSigned(Bureaucrat b);

    class GradeTooHighException
    {
     public:
       const char * what() const;
    };
    class GradeTooLowException
    { 
    public:
        const char * what() const;
    };
};

std::ostream & operator << (std::ostream &os, const Form &data);

#endif