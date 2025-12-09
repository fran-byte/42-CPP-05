/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:57:45 by frromero          #+#    #+#             */
/*   Updated: 2025/12/09 11:14:20 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &copy)
{
    /*Copy anything*/
    void(copy);
}

Intern &Intern::operator=(Intern const &other)
{
    void(other);
    return *this;
}

Intern::~Intern() {}

Aform *Intern::makeForm(std::string const &name, std::string const &target)
{
}
