/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 03:06:49 by bberkrou          #+#    #+#             */
/*   Updated: 2024/03/01 21:25:18 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.h"

// ------------- Constructors -------------

PhoneBook::PhoneBook()
{
    this->index = 0;
    this->contact_count = -1;
}

// ------------- Destructors -------------

PhoneBook::~PhoneBook()
{
    
}

// ------------- Methods -------------

// Printer

std::string truncate(const std::string& str) {
    return str.length() > 10 ? str.substr(0, 9) + "." : str;
}

void PhoneBook::print_contact(Contact contact, int index)
{
    std::ostringstream oss;
    oss << index;
    std::string indexStr = oss.str();

    std::cout << "│";
    std::cout << std::setw(10) << std::right << truncate(indexStr) << "│";
    std::cout << std::setw(10) << std::right << truncate(contact.get_first_name())  << "│";
    std::cout << std::setw(10) << std::right << truncate(contact.get_last_name())   << "│";
    std::cout << std::setw(10) << std::right << truncate(contact.get_nick_name())   << "│";
    std::cout << std::endl;
}

void PhoneBook::print_contact_info(int index)
{
    std::cout << "╒═══════════════╤═══════════════════════════════╕" << std::endl;
    std::cout << "│ First name    | " << std::setw(30) << std::left << this->contact[index].get_first_name() << "│" << std::endl;
    std::cout << "├––––———————————┼———————————————————————————————┤"<< std::endl  ;
    std::cout << "│ Last name     │ " << std::setw(30) << std::left << this->contact[index].get_last_name() << "│" << std::endl;
    std::cout << "├––––———————————┼———————————————————————————————┤"<< std::endl  ;
    std::cout << "│ Nick name     │ " << std::setw(30) << std::left << this->contact[index].get_nick_name() << "│" << std::endl;
    std::cout << "├––––———————————┼———————————————————————————————┤"<< std::endl  ;
    std::cout << "│ Phone number  │ " << std::setw(30) << std::left << this->contact[index].get_phone_number() << "│" << std::endl;
    std::cout << "├––––———————————┼———————————————————————————————┤"<< std::endl  ;
    std::cout << "│ Dark secret   │ " << std::setw(30) << std::left << this->contact[index].get_dark_secret() << "│" << std::endl;
    std::cout << "╘═══════════════════════════════════════════════╛" << std::endl;
}

void PhoneBook::print_contact_list()
{
    int index;

    index = 0;
    while (index < 8)
    {
        if (this->contact[index].get_first_name() != "")
            this->print_contact(this->contact[index], index);
        index++;
    }
    std::cout << "╘══════════╧══════════╧══════════╧══════════╛" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl << BLUE << "════════════════════════╝ Chose your contact ╚═════════════════════════" << RESET << std::endl << std::endl;
}

// Search

void PhoneBook::chose_contact()
{
    int index;

    while (1)
    {
        std::cout << GREEN << "Chose your index contact : " << RESET << std::endl;
        std::cout << PURPLE << "  > " << RESET;
        std::cin.clear();
        std::cin >> index;
        if (std::cin.eof())
        {
            std::cin.clear();
            print_end();
            exit(1) ;
        }
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (index >= 0 && index <= 7 && index <= contact_count)
        {
            this->print_contact_info(index);
            break;
        }
        else
            std::cout << RED << "Invalid input" << RESET << std::endl;
    }
}


void PhoneBook::search_contact()
{
    print_top_contact();
    print_contact_list();

    if (this->contact_count == -1)
    {
        std::cout << RED << "No contact found" << RESET << std::endl;
        sleep(3);
        system("clear");
        print_start();
        print_rules();
        return ;
    }

    chose_contact();
    std::cin.clear();
    sleep(3);
    system("clear");
    print_start();
    print_rules();
}

// ------------- Getters -------------

Contact PhoneBook::get_contact(int index)
{
    return this->contact[index];
}

// ------------- Setters -------------

void    PhoneBook::set_contact(Contact contact)
{
    if (this->index > 7)
        this->index = 0;
    this->contact[this->index] = contact;
    this->index++;
    if (this->contact_count < 7)
        this->contact_count++;
}