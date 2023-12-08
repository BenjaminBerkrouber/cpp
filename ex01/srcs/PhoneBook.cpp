#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include "utils.h"

// ------------- Constructors -------------

PhoneBook::PhoneBook()
{
    Contact contact;

    contact = Contact();
    this->contact[0] = contact;
    this->contact[1] = contact;
    this->contact[2] = contact;
    this->contact[3] = contact;
    this->contact[4] = contact;
    this->contact[5] = contact;
    this->contact[6] = contact;
    this->contact[7] = contact;
    this->index = 0;
    this->contact_count = -1;
}

// ------------- Destructors -------------

PhoneBook::~PhoneBook()
{
    
}

// ------------- Methods -------------

std::string truncate(const std::string& str) {
    return str.length() > 10 ? str.substr(0, 9) + "." : str;
}

void    PhoneBook::print_contact(Contact contact, int index)
{
    std::cout << "│" ;
    std::cout << std::setw(10) << std::right << truncate(std::to_string(index)) << "│";
    std::cout << std::setw(10) << std::right << truncate(contact.get_first_name())  << "│";
    std::cout << std::setw(10) << std::right << truncate(contact.get_last_name())   << "│";
    std::cout << std::setw(10) << std::right << truncate(contact.get_nick_name())   << "│";
    std::cout << std::endl;
}

void    print_search_contact()
{
    std::cout << PURPLE << std::endl;
    std::cout << "  / ____|                   | |                     | |           | |  " << std::endl;
    std::cout << " | (___   ___  __ _ _ __ ___| |__     ___ ___  _ __ | |_ __ _  ___| |_ " << std::endl;
    std::cout << "  \\___ \\ / _ \\/ _` | '__/ __| '_ \\   / __/ _ \\| '_ \\| __/ _` |/ __| __|" << std::endl;
    std::cout << "  ____) |  __/ (_| | | | (__| | | | | (_| (_) | | | | || (_| | (__| |_ " << std::endl;
    std::cout << " |_____/ \\___|\\__,_|_|  \\___|_| |_|  \\___\\___/|_| |_|\\__\\__,_|\\___|\\__|" << std::endl;
    std::cout << "                                                                        " << std::endl;
    std::cout << RESET << std::endl;
}

void PhoneBook::search_contact()
{
    int index;

    system("clear");
    print_search_contact();
    std::cout << std::endl << BLUE << "════════════════════════╗ Chose your contact ╔═════════════════════════" << RESET << std::endl << std::endl;
    std::cout << std::endl;
    std::cout << "╒══════════╤══════════╤══════════╤══════════╕" << std::endl;
    std::cout << "│     index│first name│ last name│  nickname│" << std::endl;
    std::cout << "╞══════════╪══════════╪══════════╪══════════╡" << std::endl;
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

    if (this->contact_count == -1)
    {
        std::cout << RED << "No contact found" << RESET << std::endl;
        sleep(5);
        system("clear");
        print_start();
        print_rules();
        return ;
    }
    while (1)
    {
        std::cout << GREEN << "Chose your index contact : " << RESET << std::endl;
        std::cout << PURPLE << "  > " << RESET;
        std::cin.clear();
        std::cin >> index;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (index >= 0 && index <= 7 && index <= contact_count)
        {
            std::cout << "╒═══════════════╤═══════════════════════════════╕" << std::endl;
            std::cout << "│ First name    │ " << std::setw(30) << std::left << this->contact[index].get_first_name() << "│" << std::endl;
            std::cout << "├––––———————————┼———————————————————————————————┤"<< std::endl  ;
            std::cout << "│ Last name     │ " << std::setw(30) << std::left << this->contact[index].get_last_name() << "│" << std::endl;
            std::cout << "├––––———————————┼———————————————————————————————┤"<< std::endl  ;
            std::cout << "│ Nick name     │ " << std::setw(30) << std::left << this->contact[index].get_nick_name() << "│" << std::endl;
            std::cout << "├––––———————————┼———————————————————————————————┤"<< std::endl  ;
            std::cout << "│ Phone number  │ " << std::setw(30) << std::left << this->contact[index].get_phone_number() << "│" << std::endl;
            std::cout << "├––––———————————┼———————————————————————————————┤"<< std::endl  ;
            std::cout << "│ Dark secret   │ " << std::setw(30) << std::left << this->contact[index].get_dark_secret() << "│" << std::endl;
            std::cout << "╘═══════════════════════════════════════════════╛" << std::endl;
            break;
        }
        else
            std::cout << RED << "Invalid input" << RESET << std::endl;
    }
    std::cin.clear();
    sleep(5);
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
    this->contact_count++;
}