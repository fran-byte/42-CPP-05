/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:57:45 by frromero          #+#    #+#             */
/*   Updated: 2025/12/09 18:17:34 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <vector>
#include <algorithm>
#include <string>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &copy)
{
    /*No attributes to initialize*/
    (void)copy;
}

Intern &Intern::operator=(Intern const &other)
{
    /*Nothing to assign*/
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(std::string const &name, std::string const &target)
{
    std::vector<std::string> validForm;
    validForm.push_back("shrubbery creation");
    validForm.push_back("robotomy request");
    validForm.push_back("presidential pardon");

    int index = -1;
    for (size_t i = 0; i < validForm.size(); i++)
    {
        if (name == validForm[i])
        {
            index = static_cast<int>(i);
            break;
        }
    }

    switch (index)
    {
    case 0:
        std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
        return new ShrubberyCreationForm(target);
    case 1:
        std::cout << "Intern creates RobotomyRequestForm" << std::endl;
        return new RobotomyRequestForm(target);
    case 2:
        std::cout << "Intern creates PresidentialPardonForm" << std::endl;
        return new PresidentialPardonForm(target);
    default:
        std::cerr << "Error: Form name '" << name << "' not found" << std::endl;
        return NULL;
    }
}
