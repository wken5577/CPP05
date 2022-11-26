#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    Bureaucrat b1("jack");

    try
    {
        std::cout << b1 << std::endl;
        b1.incGrade();
        std::cout << b1 << std::endl;
        // b1.decGrade();
        // b1.decGrade();
        std::cout << std::endl;
        for(int i = 0; i < 150; i++)
        {
            b1.incGrade();
            std::cout << b1 << std::endl;
        }
    }
    catch (Bureaucrat::GradeTooLowException & e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
          std::cout << e.what() << std::endl;
    }
}