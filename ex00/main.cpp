/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:13:44 by frromero          #+#    #+#             */
/*   Updated: 2025/11/21 18:56:57 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

void test1()
{
    std::cout << "\033[1;33m*** TEST 1: Invalid Bureaucrats\033[0m" << std::endl;

    try
    {
        Bureaucrat tooHigh("God", 0); /* fail */
    }
    catch (const std::exception &e)
    {
        std::cout << "\033[1;31mException: " << e.what() << "\033[0m" << std::endl;
    }

    try
    {
        Bureaucrat tooLow("Slave", 151); /* fail */
    }
    catch (const std::exception &e)
    {
        std::cout << "\033[1;31mException: " << e.what() << "\033[0m" << std::endl;
    }
    std::cout << std::endl;
}

void test2()
{
    std::cout << "\033[1;33m*** TEST 2: Valid Bureaucrats and printing\033[0m" << std::endl;

    try
    {
        Bureaucrat boss("BOSS", 1);
        Bureaucrat john("John", 50);
        Bureaucrat slave("Slave", 150);

        std::cout << boss << std::endl;
        std::cout << john << std::endl;
        std::cout << slave << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "\033[1;31mException: " << e.what() << "\033[0m" << std::endl;
    }
    std::cout << std::endl;
}

void test3()
{
    std::cout << "\033[1;33m*** TEST 3: Increment/Decrement grade\033[0m" << std::endl;

    try
    {
        Bureaucrat luis("Luis", 75);
        std::cout << "Original: " << luis << std::endl;

        luis.incrementGrade();
        std::cout << "Increment: " << luis << std::endl;

        luis.decrementGrade();
        std::cout << "Decrement: " << luis << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "\033[1;31mException: " << e.what() << "\033[0m" << std::endl;
    }
    std::cout << std::endl;
}

void test4()
{
    std::cout << "\033[1;33m*** TEST 4: Increment/Decrement and fail\033[0m" << std::endl;

    try
    {
        Bureaucrat pepe("Pepe", 1);
        std::cout << "Original: " << pepe << std::endl;
        pepe.incrementGrade(); /* fail */
    }
    catch (const std::exception &e)
    {
        std::cout << "\033[1;31mException: " << e.what() << "\033[0m" << std::endl;
    }

    try
    {
        Bureaucrat alf("Alf", 150);
        std::cout << "Original: " << alf << std::endl;
        alf.decrementGrade(); /* fail */
    }
    catch (const std::exception &e)
    {
        std::cout << "\033[1;31mException: " << e.what() << "\033[0m" << std::endl;
    }
    std::cout << std::endl;
}

void test5()
{
    std::cout << "\033[1;33m*** TEST 5: Copy and assignment\033[0m" << std::endl;

    try
    {
        Bureaucrat leo("Leo", 42);
        Bureaucrat leocopy1(leo);

        Bureaucrat pedro("Pedro", 52);
        Bureaucrat jose("Jose", 12);

        std::cout << "Original: " << leo << std::endl;
        std::cout << "Copy (constructor): " << leocopy1 << std::endl
                  << std::endl;

        std::cout << "Original: " << pedro << std::endl;
        std::cout << "Original: " << jose << std::endl;
        jose = pedro;
        std::cout << "Copy (assignment): " << jose << std::endl;
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
    test4();
    test5();

    return 0;
}