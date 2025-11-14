/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 07:52:10 by frromero          #+#    #+#             */
/*   Updated: 2025/11/14 19:20:31 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <exception>
#include <fstream>
#include "ShrubberyCreationForm.hpp"

#define TREE "\n     *\n \
   { }   \n \
  {   }  \n \
 {     } \n \
{       }\n \
   | |   \n"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("NoName")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm("ShrubberyCreationForm", 145, 137), _target(copy._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

void ShrubberyCreationForm::executeAction() const
{
    std::string outFilename = _target + "_shrubbery";
    std::ofstream outFile(outFilename.c_str());

    if (outFile.is_open())
    {
        outFile << TREE << std::endl;
        outFile.close();
    }
    else
        throw std::runtime_error("Cannot create file");
}