/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:13:44 by frromero          #+#    #+#             */
/*   Updated: 2025/12/09 20:40:19 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

/*
Exercise 01: Form signing mechanism.
Builds on ex00 by adding Form class with two-tier authorization.
Tests form signing workflow with grade validation.
Now includes Bureaucrat-Form interaction through signForm().
*/

void test1()
{
    std::cout << "\033[1;33m*** TEST 1: Invalid Bureaucrats and Forms ***\033[0m" << std::endl;

    try
    {
        Bureaucrat tooHigh("God", 0);
    }
    catch (const std::exception &e)
    {
        std::cout << "\033[1;31mException: " << e.what() << "\033[0m" << std::endl;
    }

    try
    {
        Bureaucrat tooLow("Slave", 151);
    }
    catch (const std::exception &e)
    {
        std::cout << "\033[1;31mException: " << e.what() << "\033[0m" << std::endl;
    }

    try
    {
        Form tooHighForm("Impossible Form", 0, 30);
    }
    catch (const std::exception &e)
    {
        std::cout << "\033[1;31mException: " << e.what() << "\033[0m" << std::endl;
    }

    try
    {
        Form tooLowForm("Invalid Form", 50, 151);
    }
    catch (const std::exception &e)
    {
        std::cout << "\033[1;31mException: " << e.what() << "\033[0m" << std::endl;
    }
    std::cout << std::endl;
}

void test2()
{
    std::cout << "\033[1;33m*** TEST 2: Form cannot be signed by low-grade bureaucrat ***\033[0m" << std::endl;

    try
    {
        Bureaucrat paco("Paco", 100);
        Form form42("Form42", 50, 25);

        std::cout << paco << std::endl;
        std::cout << form42 << std::endl;

        paco.signForm(form42);
        std::cout << form42 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "\033[1;31mException: " << e.what() << "\033[0m" << std::endl;
    }
    std::cout << std::endl;
}

void test3()
{
    std::cout << "\033[1;33m*** TEST 3: Form can be signed by high-grade bureaucrat ***\033[0m" << std::endl;

    try
    {
        Bureaucrat boss("BOSS", 1);
        Form importantForm("Important Document", 50, 25);

        std::cout << boss << std::endl;
        std::cout << importantForm << std::endl;

        boss.signForm(importantForm);
        std::cout << importantForm << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "\033[1;31mException: " << e.what() << "\033[0m" << std::endl;
    }
    std::cout << std::endl;
}

int main(void)
{
    test1();
    test2();
    test3();
    return 0;
}