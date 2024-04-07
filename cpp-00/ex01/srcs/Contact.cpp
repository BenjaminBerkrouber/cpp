/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 03:06:42 by bberkrou          #+#    #+#             */
/*   Updated: 2024/03/01 21:34:39 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "utils.h"

// ------------- Constructors -------------

Contact::Contact(){
    this->first_name = "";
    this->last_name = "";
    this->nick_name = "";
    this->phone_number = 0;
    this->dark_secret = "";
}

// ------------- Destructors -------------

Contact::~Contact() {
    
}

// ------------- Methods -------------

std::string valide_name()
{
    std::string name;

    std::cin.clear();
    do {
        std::cout << PURPLE << "  > " << RESET;
        std::getline(std::cin, name);
        if (std::cin.eof())
        {
            std::cin.clear();
            print_end();
            exit(1) ;
        }
        if (name == "")
            std::cout << RED << "Invalid input" << RESET << std::endl;
    } while (name == "");
    std::cin.clear();
    return (name);
}

bool is_number(const std::string& str)
{
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
        if (!std::isdigit(*it))
            return false;
    return true;
}

long  valide_number() {
    std::string input;
    long number;

    do {
        std::cout << PURPLE << "  > " << RESET;
        std::getline(std::cin, input);

        if (std::cin.eof()) {
            std::cin.clear();
            print_end();
            exit(1);
        }

        if (!is_number(input) || input.length() != 10) {
            std::cout << RED << "Invalid input. Please enter a 10-digit number." << RESET << std::endl;
        } else {
            std::istringstream ss(input);
            ss >> number;
            if (ss.fail()) {
                std::cout << RED << "Invalid input." << RESET << std::endl;
                continue;
            }
            break;
        }
    } while (true);
    return (number);
}

void    Contact::create_contact()
{
    system("clear");
    print_creat_contact();
    std::cout << std::endl << BLUE << "═════════════════════════╗ Adding new contact ╔═════════════════════════" << RESET << std::endl << std::endl;
    
    std::cout << " Enter first name" << std::endl;
    this->first_name = valide_name();
    std::cout << " Enter last name" << std::endl;
    this->last_name = valide_name();
    std::cout << " Enter nick name" << std::endl;
    this->nick_name = valide_name();
    std::cout << " Enter dark secret" << std::endl;
    this->dark_secret = valide_name();
    std::cout << " Enter phone number" << std::endl;
    this->phone_number = valide_number();

    std::cout << std::endl << GREEN << "══════════════════════════╝   Contact added   ╚══════════════════════════" << RESET << std::endl;
    std::cout << std::endl;
    std::cin.clear();
    sleep(1);
    system("clear");
    print_start();
    print_rules();
}

// ------------- Getters -------------

std::string Contact::get_first_name() {
    return this->first_name;
}

std::string Contact::get_last_name() {
    return this->last_name;
}

std::string Contact::get_nick_name() {
    return this->nick_name;
}

long  Contact::get_phone_number() {
    return this->phone_number;
}

std::string Contact::get_dark_secret() {
    return this->dark_secret;
}

// ------------- Setters -------------

void   Contact::set_first_name(std::string first_name) {
    this->first_name = first_name;
}

void   Contact::set_last_name(std::string last_name) {
    this->last_name = last_name;
}

void   Contact::set_nick_name(std::string nick_name) {
    this->nick_name = nick_name;
}

void   Contact::set_phone_number(int phone_number) {
    this->phone_number = phone_number;
}

void   Contact::set_dark_secret(std::string dark_secret) {
    this->dark_secret = dark_secret;
}