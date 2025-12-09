/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:20:42 by frromero          #+#    #+#             */
/*   Updated: 2025/12/09 11:35:51 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
#include <iostream>

class Intern
{

public:
    Intern();
    Intern(Intern const &copy);
    ~Intern();
    Intern &operator=(Intern const &other);
    AForm *makeForm(std::string const &name, std::string const &target);
};

#endif