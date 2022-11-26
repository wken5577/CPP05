#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Bureaucrat
{
private:
    std::string name;
    int         grade;

public:
    Bureaucrat();
    Bureaucrat(std::string name);
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &data);
    ~Bureaucrat();

    Bureaucrat& operator= (const Bureaucrat &data);

    std::string getName() const;
    int         getGrade() const;
    void        incGrade();
    void        decGrade();

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

std::ostream & operator << (std::ostream &os, const Bureaucrat &data);


#endif