/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:30:53 by frromero          #+#    #+#             */
/*   Updated: 2025/12/09 20:41:56 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

/*
Exercise 02: Polymorphic form execution.
Extends ex01: Form renamed to AForm (abstract base class).
Adds three concrete forms with unique executeAction() behaviors.
Tests two-phase workflow: signing then execution with grade checks.
*/

void test1()
{
    std::cout << "\033[1;33m*** TEST 1: ShrubberyCreationForm :OK ***\033[0m" << std::endl;

    try
    {
        Bureaucrat paco("Paco", 1);
        ShrubberyCreationForm garden("Home");
        std::cout << paco << std::endl;
        std::cout << garden;
        paco.signForm(garden);
        std::cout << garden;
        paco.executeForm(garden);
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void test2()
{
    std::cout << "\033[1;33m*** TEST 2: PresidentialPardonForm :OK ***\033[0m" << std::endl;

    try
    {
        Bureaucrat jose("Jose", 1);
        PresidentialPardonForm criminal("Criminal");
        std::cout << jose << std::endl;
        std::cout << criminal;
        jose.signForm(criminal);
        std::cout << criminal;
        jose.executeForm(criminal);
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void test3()
{
    std::cout << "\033[1;33m*** TEST 3: RobotomyRequestForm ***\033[0m" << std::endl;

    try
    {
        Bureaucrat luis("Luis", 1);
        RobotomyRequestForm bender("Bender");
        std::cout << luis << std::endl;
        std::cout << bender;
        luis.signForm(bender);
        std::cout << bender;
        luis.executeForm(bender);
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void test4()
{
    std::cout << "\033[1;33m*** TEST 4: Error - Grade too low to execute ***\033[0m" << std::endl;

    try
    {
        Bureaucrat pepi("Pepi", 150);
        RobotomyRequestForm r2d2("r2d2");
        std::cout << pepi << std::endl;
        std::cout << r2d2;

        Bureaucrat jesus("Jesus", 1); /* He can to sign*/
        std::cout << jesus << std::endl;
        jesus.signForm(r2d2);
        std::cout << r2d2;

        pepi.executeForm(r2d2); /* He can´t to execute*/
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void test5()
{
    std::cout << "\033[1;33m*** TEST 5: Error - Form not signed ***\033[0m" << std::endl;

    try
    {
        Bureaucrat maria("Maria", 1);
        RobotomyRequestForm roboto3("Roboto3");
        std::cout << maria << std::endl;
        std::cout << roboto3;
        maria.executeForm(roboto3);
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void test6()
{
    std::cout << "\033[1;33m*** TEST 6: Error - Grade too low to sign ***\033[0m" << std::endl;

    try
    {
        Bureaucrat perico("Perico", 150);
        RobotomyRequestForm roboto4("Roboto4");
        std::cout << perico << std::endl;
        std::cout << roboto4;
        perico.signForm(roboto4);
        std::cout << roboto4;
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

    return 0;
}