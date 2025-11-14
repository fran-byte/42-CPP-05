/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:30:53 by frromero          #+#    #+#             */
/*   Updated: 2025/11/14 20:03:22 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

void test1()
{
    std::cout << "*** TEST 1: ShrubberyCreationForm :OK ***" << std::endl;
    Bureaucrat paco("Paco", 1);
    ShrubberyCreationForm garden("Home");
    paco.signForm(garden);
    paco.executeForm(garden);
    std::cout << std::endl;
}

void test2()
{
    std::cout << "*** TEST 2: PresidentialPardonForm :OK ***" << std::endl;
    Bureaucrat jose("Jose", 1);
    PresidentialPardonForm criminal("Criminal");
    jose.signForm(criminal);
    jose.executeForm(criminal);
    std::cout << std::endl;
}

void test3()
{
    std::cout << "*** TEST 3: RobotomyRequestForm ***" << std::endl;
    Bureaucrat luis("Luis", 1);
    RobotomyRequestForm bender("Bender");
    luis.signForm(bender);
    luis.executeForm(bender);
    std::cout << std::endl;
}

void test4()
{
    std::cout << "*** TEST 4: Error - Grade too low to execute ***" << std::endl;
    Bureaucrat pepi("Pepi", 150);
    RobotomyRequestForm r2d2("r2d2");

    Bureaucrat jesus("Jesus", 1);
    jesus.signForm(r2d2);
    pepi.executeForm(r2d2);
    std::cout << std::endl;
}

void test5()
{
    std::cout << "*** TEST 5: Error - Form not signed ***" << std::endl;
    Bureaucrat maria("Maria", 1);
    RobotomyRequestForm roboto3("Roboto3");
    maria.executeForm(roboto3);
    std::cout << std::endl;
}

void test6()
{
    std::cout << "*** TEST 6: Error - Grade too low to sign ***" << std::endl;
    Bureaucrat perico("perico", 150);
    RobotomyRequestForm roboto4("Roboto4");
    perico.signForm(roboto4);
    std::cout << std::endl;
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