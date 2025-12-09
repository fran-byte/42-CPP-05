/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:57:45 by frromero          #+#    #+#             */
/*   Updated: 2025/12/09 12:02:44 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <vector>
#include <algorithm>
#include <string>

Intern::Intern() {}

Intern::Intern(Intern const &copy)
{
    /*Copy anything*/
    (void)copy;
}

Intern &Intern::operator=(Intern const &other)
{
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

    if (std::find(validForm.begin(), validForm.end(), name) != validForm.end())
    {
        ; // CREAR FORMULARIO
    }
    else
    {
        ; // Emitir ERROR
    }
    return // Devolver Formulario
}