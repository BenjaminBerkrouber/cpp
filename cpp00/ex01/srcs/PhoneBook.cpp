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

std::string get_next_chars(const std::string& input_string, size_t start_index) {
    if (start_index >= input_string.length()) {
        return "";
    } else {
        return input_string.substr(start_index, 30);
    }
}

void	PhoneBook::print_line_info(std::string alias, std::string value)
{
	unsigned long	length;

	length = 0;
    std::cout << "│ " << std::setw(15) << std::left << alias << " | " << std::setw(40) << std::left << get_next_chars(value, length) << "│" << std::endl;
	length += 30;
	while (length < value.length())
	{
		std::cout << "│                 | " << std::setw(40) << std::left << get_next_chars(value, length) << "│" << std::endl;
		length += 30;
	}
}

void PhoneBook::print_contact_info(int index)
{
    std::cout << "╒═════════════════╤═════════════════════════════════════════╕" << std::endl;
    print_line_info("First name", this->contact[index].get_first_name());
    std::cout << "├––––—————————————┼—————————————————————————————————————————┤"<< std::endl;
	print_line_info("Last name", this->contact[index].get_last_name());
    std::cout << "├––––—————————————┼—————————————————————————————————————————┤"<< std::endl  ;
	print_line_info("Nick name", this->contact[index].get_nick_name());
    std::cout << "├––––—————————————┼—————————————————————————————————————————┤"<< std::endl  ;
	std::cout << "│ Phone number    │ " << std::setw(40) << std::left << this->contact[index].get_phone_number() << "│" << std::endl;
    std::cout << "├––––—————————————┼—————————————————————————————————————————┤"<< std::endl  ;
	print_line_info("Dark secret", this->contact[index].get_dark_secret());
    std::cout << "╘═══════════════════════════════════════════════════════════╛" << std::endl;
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
	std::string command;

    while (1)
    {
        std::cout << GREEN << "Chose your index contact index: " << RESET << std::endl;
        std::cout << GREEN << "Or -1 for quit: " << RESET << std::endl;
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
			while (1)
			{
				std::getline(std::cin, command);
				if (!command.empty())
					break;
			}
            break;
        }
		else if (index == -1)
			return ;
        else
            std::cout << RED << "Invalid input" << RESET << std::endl;
    }
}


void PhoneBook::search_contact()
{
	std::string command;
    print_top_contact();
    print_contact_list();

    if (this->contact_count == -1)
    {
        std::cout << RED << "No contact found" << RESET << std::endl;
		while (1)
		{
			std::getline(std::cin, command);
			if (!command.empty())
			{
				std::cin.clear();
				break;
			}
		}
        system("clear");
        print_start();
        print_rules();
        return ;
    }
    chose_contact();
    std::cin.clear();
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