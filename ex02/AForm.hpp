#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
private:
    std::string const _name;
    bool _isSigned;
    int const _gradeToSign;
    int const _gradeToExec;

public:
    AForm();
    AForm(const std::string &name, int gradeToSign, int gradeToExec);
    AForm(const AForm &copy);
    virtual ~AForm();
    AForm &operator=(const AForm &other);

    std::string getName() const;
    bool isSigned() const;
    bool getIsSign() const;
    int getGradeToSign() const;
    int getGradeToExec() const;

    void beSigned(Bureaucrat const &b);
    void execute(Bureaucrat const &executor) const;

protected:
    virtual void executeAction() const = 0;

public:
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

    class FormNotSignedException : public std::exception
    {
    public:
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, AForm const &obj);

#endif
