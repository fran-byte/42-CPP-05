/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:01:01 by frromero          #+#    #+#             */
/*   Updated: 2025/11/14 17:15:50 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class AForm;

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &copy);
    ~Bureaucrat();

    Bureaucrat &operator=(const Bureaucrat &other);

    const std::string &getName() const;
    int getGrade() const;
    void setGrade(int grade);
    void incrementGrade();
    void decrementGrade();

    /*forms*/
    void signForm(AForm &form);
    void executeForm(AForm const &form);

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
