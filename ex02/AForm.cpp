/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:32:33 by frromero          #+#    #+#             */
/*   Updated: 2025/11/14 07:39:39 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("NoName"), _isSigned(false), _gradeToSign(150), _gradeToExec(150)
{
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExec) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
    if (_gradeToSign < 1 || _gradeToExec < 1)
        throw GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExec > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExec(copy._gradeToExec)
{
}

Form::~Form() {}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        _isSigned = other._isSigned;
    return (*this);
}

std::string Form::getName() const
{
    return _name;
}
bool Form::getIsSign() const
{
    return _isSigned;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

int Form::getGradeToExec() const
{
    return _gradeToExec;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

void Form::beSigned(Bureaucrat &b)
{
    if (b.getGrade() > _gradeToSign)
    {
        throw Form::GradeTooLowException();
    }
    _isSigned = true;
}

std::ostream &operator<<(std::ostream &out, Form const &obj)
{
    out << obj.getName() << " :" << std::endl
        << "- Grade to sign: " << obj.getGradeToSign() << std::endl
        << "- Grade to Execute: " << obj.getGradeToExec() << std::endl
        << "- Sign : " << obj.getIsSign() << std::endl;
    return out;
}
