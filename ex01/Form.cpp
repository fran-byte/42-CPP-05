/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:32:33 by frromero          #+#    #+#             */
/*   Updated: 2025/11/13 10:57:05 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("NoName"), _isSigned(false), _gradeToSign(150), _gradeToExec(150)
{
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExec) : _isSigned(false), _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
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

void Form::beSigned(Bureaucrat &b)
{
    if (b.getGrade() >= _gradeToSign)
    {
        _isSigned = true;
        std::cout << b << " signed the form!!" << std::endl;
    }
    else
        std::cout << b << "is not allowed to sign this form!!" << std::endl;
}

std::ostream &operator<<(std::ostream &out, Form const &obj)
{
    out << obj.getName() << " :" << std::endl
        << "- Grade to sign: " << obj.getGradeToSign() << std::endl
        << "- Grade to Execute: " << obj.getGradeToSign() << std::endl
        << "- Sign : " << obj.getIsSign() << std::endl;
    return out;
}
