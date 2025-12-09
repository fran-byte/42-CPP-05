/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:20:42 by frromero          #+#    #+#             */
/*   Updated: 2025/12/09 10:42:23 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include "Aform.hpp"
#include <iostream>

class Intern
{

public:
    Intern();
    Intern(Intern const &copy);
    ~Intern();
    Intern &operator=(Intern const &other);
    Aform *makeForm(std::string const &name, std::string const &target);
};

#endif