/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 07:51:55 by frromero          #+#    #+#             */
/*   Updated: 2025/11/14 10:34:33 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
private:
    const std::string _name;
    int _grade;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &name, int grade);
    ShrubberyCreationForm(const ShrubberyCreationForm &copy);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

    const std::string &getName() const;
    int getGrade() const;
    void setGrade(int grade);
    void incrementGrade();
    void decrementGrade();
    void signForm(Form &form);

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

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm const &obj);

#endif