/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:13:44 by frromero          #+#    #+#             */
/*   Updated: 2025/11/13 12:28:07 by frromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <vector>
#include <iostream>
#include <limits>

void menu()
{
    std::cout << "\nMenu:" << std::endl;
    std::cout << "1 - Create Bureaucrat by copy (new a)" << std::endl;
    std::cout << "2 - Assign Bureaucrat (a = b)" << std::endl;
    std::cout << "3 - Increment Grade (++)" << std::endl;
    std::cout << "4 - Decrement Grade (--)" << std::endl;
    std::cout << "5 - Sign Form" << std::endl;
    std::cout << "6 - Show Forms" << std::endl;
    std::cout << "0 - Exit" << std::endl;
}

void showBureaucrats(const std::vector<Bureaucrat> &bureaucrats)
{
    std::cout << "\033[1;32m\nCurrent Bureaucrats: \033[0m" << std::endl;
    for (size_t i = 0; i < bureaucrats.size(); ++i)
        std::cout << "\033[32m[#" << i << "] " << bureaucrats[i] << "\033[0m" << std::endl;
}
void showForms(const std::vector<Form> &forms)
{
    std::cout << "\033[1;32m\nCurrent Forms: \033[0m" << std::endl;
    for (size_t i = 0; i < forms.size(); ++i)
        std::cout << "\033[32m[#" << i << "] " << forms[i] << "\033[0m" << std::endl;
}

int main(void)
{
    std::vector<Bureaucrat> bureaucrats;
    std::vector<Form> forms;

    int count;

    std::cout << "Number of Bureaucrats? ";
    while (!(std::cin >> count) || count <= 0)
    {
        std::cin.clear(); /*reset (error)status cin*/
        /*ignore all characters from the input buffer until a newline (\n)*/
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a valid positive number: ";
    }
    for (int i = 0; i < count; ++i)
    {
        std::string name;
        std::string option;
        int grade;
        std::cout << "Use default name? (y/n): ";
        std::cin >> option;
        if (option == "y" || option == "Y")
        {
            Bureaucrat b;
            bureaucrats.push_back(b);
            continue;
        }

        std::cout << "Name #" << i + 1 << ": ";
        std::cin >> name;
        std::cout << "Grade (1-150): ";
        while (!(std::cin >> grade))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number: ";
        }
        try
        {
            /*Create Obj*/
            Bureaucrat b(name, grade);
            bureaucrats.push_back(b);
        }
        catch (std::exception &e)
        {
            std::cerr << "\033[1;31mError: " << e.what() << "\033[0m" << std::endl;
            --i;
        }
    }

    std::cout << "Number of Forms to create? ";
    while (!(std::cin >> count) || count <= 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a valid positive number: ";
    }

    for (int i = 0; i < count; ++i)
    {
        std::string name;
        int gradeToSign, gradeToExec;

        std::cout << "Form name #" << i + 1 << ": ";
        std::cin >> name;
        std::cout << "Grade required to sign (1-150): ";
        std::cin >> gradeToSign;
        std::cout << "Grade required to execute (1-150): ";
        std::cin >> gradeToExec;

        try
        {
            Form f(name, gradeToSign, gradeToExec);
            forms.push_back(f);
        }
        catch (std::exception &e)
        {
            std::cerr << "\033[1;31mError: " << e.what() << "\033[0m" << std::endl;
            --i; // repetir este formulario
        }
    }
    int option;
    do
    {
        showBureaucrats(bureaucrats);
        showForms(forms);

        menu();
        std::cout << "Choose an option: ";
        while (!(std::cin >> option))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Choose a number: ";
        }
        switch (option)
        {
        case 1: /*Copy with new name*/
        {
            int index;
            std::cout << "Enter index of Bureaucrat to copy (0 to " << bureaucrats.size() - 1 << "): ";
            std::cin >> index;

            if (index >= 0 && index < (int)bureaucrats.size())
            {
                std::string newName;
                std::cout << "Enter new name for the copy: ";
                std::cin >> newName;

                try
                {
                    Bureaucrat copy(newName, bureaucrats[index].getGrade());
                    bureaucrats.push_back(copy);
                    std::cout << "Copied: " << copy << std::endl;
                }
                catch (std::exception &e)
                {
                    std::cerr << "\033[1;31mError: " << e.what() << "\033[0m" << std::endl;
                }
            }
            else
                std::cout << "Invalid index" << std::endl;
            break;
        }
        case 2: /*Assignment*/
        {
            if (bureaucrats.size() < 2)
            {
                std::cout << "Assignment requires at least 2 Bureaucrats." << std::endl;
                break;
            }

            int from, to;
            std::cout << "Assign FROM index: ";
            std::cin >> from;
            std::cout << "Assign TO index: ";
            std::cin >> to;

            if (from >= 0 && from < (int)bureaucrats.size() &&
                to >= 0 && to < (int)bureaucrats.size())
            {
                bureaucrats[to] = bureaucrats[from];
                std::cout << "Assigned " << bureaucrats[from].getName()
                          << " to " << bureaucrats[to].getName() << std::endl;
            }
            else
                std::cout << "Invalid indices." << std::endl;
            break;
        }
        case 3: /* ++ Grade */
        {
            int index;
            std::cout << "Enter index to increment grade: ";
            std::cin >> index;
            if (index >= 0 && index < (int)bureaucrats.size())
            {
                try
                {
                    bureaucrats[index].incrementGrade();
                    std::cout << "Incremented: " << bureaucrats[index] << std::endl;
                }
                catch (std::exception &e)
                {
                    std::cerr << "\033[1;31mError: " << e.what() << "\033[0m" << std::endl;
                }
            }
            else
                std::cout << "Invalid index." << std::endl;
            break;
        }
        case 4: /* -- Grade */
        {
            int index;
            std::cout << "Enter index to decrement grade: ";
            std::cin >> index;
            if (index >= 0 && index < (int)bureaucrats.size())
            {
                try
                {
                    bureaucrats[index].decrementGrade();
                    std::cout << "Decremented: " << bureaucrats[index] << std::endl;
                }
                catch (std::exception &e)
                {
                    std::cerr << "\033[1;31mError: " << e.what() << "\033[0m" << std::endl;
                }
            }
            else
                std::cout << "Invalid index." << std::endl;
            break;
        }
        case 5:
        {
            std::string name;
            int gradeToSign, gradeToExec;

            std::cout << "Form name: ";
            std::cin >> name;
            std::cout << "Grade required to sign (1-150): ";
            std::cin >> gradeToSign;
            std::cout << "Grade required to execute (1-150): ";
            std::cin >> gradeToExec;

            try
            {
                Form f(name, gradeToSign, gradeToExec);
                forms.push_back(f);
                std::cout << "Form created: " << f << std::endl;
            }
            catch (std::exception &e)
            {
                std::cerr << "\033[1;31mError: " << e.what() << "\033[0m" << std::endl;
            }
            break;
        }
        case 6:
        {
            std::cout << "\033[1;34m\nCurrent Forms: \033[0m" << std::endl;
            for (size_t i = 0; i < forms.size(); ++i)
                std::cout << "\033[34m[#" << i << "] " << forms[i] << "\033[0m" << std::endl;
            break;
        }

        case 0:
            std::cout << "Bye, Bye..." << std::endl;
            break;
        default:
            std::cout << "Invalid option." << std::endl;
        }
    } while (option != 0);
    return 0;
}
