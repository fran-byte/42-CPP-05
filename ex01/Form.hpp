/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:31:17 by frromero          #+#    #+#             */
/*   Updated: 2025/11/13 09:26:41 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <exception>

class Form
{
private:
    std::string const _name;
    bool _isSigned;
    int const _gradeToSign;
    int const _gradeToExec;

public:
    Form();
    Form(const std::string &name, int gradeToSign, int gradeToExec);
    Form(const Form &copy);
    ~Form();
    Form &operator=(const Form &other);
    std::string getName() const;
    bool getSign() const;
    int getGradeToSign() const;
    int getGradeToExec() const;
    void beSigned(Bureaucrat &b);
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

std::ostream &operator<<(std::ostream &out, Form const &obj);
#endif