/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:32:33 by frromero          #+#    #+#             */
/*   Updated: 2025/11/14 18:35:19 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("NoName"), _isSigned(false), _gradeToSign(150), _gradeToExec(150)
{
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExec) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
    if (_gradeToSign < 1 || _gradeToExec < 1)
        throw GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExec > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExec(copy._gradeToExec)
{
}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        _isSigned = other._isSigned;
    return (*this);
}

std::string AForm::getName() const
{
    return _name;
}
bool AForm::getIsSign() const
{
    return _isSigned;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExec() const
{
    return _gradeToExec;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

void AForm::beSigned(Bureaucrat const &b)
{
    if (b.getGrade() > _gradeToSign)
    {
        throw AForm::GradeTooLowException();
    }
    _isSigned = true;
}
void AForm::execute(Bureaucrat const &executor) const
{
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExec)
        throw GradeTooLowException();
    executeAction();
}
const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form not signed";
}

bool AForm::isSigned() const
{
    return _isSigned;
}

std::ostream &operator<<(std::ostream &out, AForm const &obj)
{
    out << obj.getName() << " :" << std::endl
        << "- Grade to sign: " << obj.getGradeToSign() << std::endl
        << "- Grade to Execute: " << obj.getGradeToExec() << std::endl
        << "- Sign : " << obj.getIsSign() << std::endl;
    return out;
}
