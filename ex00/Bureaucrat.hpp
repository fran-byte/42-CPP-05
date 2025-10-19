#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
private:
    const std::string _name;
    unsigned int _grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string name, const unsigned int grade);
    Bureaucrat(const Bureaucrat &copy);
    ~Bureaucrat();

    Bureaucrat &operator=(const Bureaucrat &copy);

    const std::string &getName() const;
    unsigned int getGrade() const;
    void setGrade(unsigned int grade);
    void incrementGrade();
    void decrementGrade();

    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &obj);

#endif
