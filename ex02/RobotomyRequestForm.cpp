/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 07:52:46 by frromero          #+#    #+#             */
/*   Updated: 2025/11/14 19:56:36 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <exception>
#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("NoName")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm("RobotomyRequestForm", 72, 45), _target(copy._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

void RobotomyRequestForm::executeAction() const
{
    std::srand(std::time(0));
    int randomNum = std::rand() % 10;

    std::cout << "* BRRRRZZZT! *" << std::endl; // 🔧 Sonidos de taladro

    if (randomNum % 2 == 0)
    {
        std::cout << _target << " has been successfully robotomized! 🤖" << std::endl;
    }
    else
    {
        std::cout << _target << "'s robotomy failed... better luck next time! 😅" << std::endl;
    }
}