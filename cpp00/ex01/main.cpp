/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 03:07:01 by bberkrou          #+#    #+#             */
/*   Updated: 2024/03/01 21:22:02 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.h"

int main()
{
    PhoneBook   phonebook;
    Contact     new_contact;
    std::string command;

    system("clear");
    print_start();
    print_rules();
    while (1)
    {
        std::cout << PURPLE << "  > " << RESET;
        std::cin.clear();
        std::getline(std::cin, command);
        if (std::cin.eof())
        {
            std::cin.clear();
            print_end();
            break ;
        }
        if (command == "EXIT")
        {
            system("clear");
            print_end();
            break ;
        }
        else if (command == "ADD")
        {
            new_contact.create_contact();
            phonebook.set_contact(new_contact);
        }
        else if (command == "SEARCH")
        {
            phonebook.search_contact();
        }
        else if (std::cin.eof())
            return (1);
        else
            std::cout << "Invalid command" << std::endl;
    }

    return 0;
}