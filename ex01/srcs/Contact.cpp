#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
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

void    print_creat_contact()
{
    std::cout << PURPLE << std::endl;
    std::cout << "  / ____|              | |        / ____|          | |          | |      " << std::endl;
    std::cout << " | |     _ __ ___  __ _| |_ ___  | |     ___  _ __ | |_ ___ __ _| |_ ___ " << std::endl;
    std::cout << " | |    | '__/ _ \\/ _` | __/ _ \\ | |    / _ \\| '_ \\| __/ __/ _` | __/ _ \\" << std::endl;
    std::cout << " | |____| | |  __/ (_| | ||  __/ | |___| (_) | | | | || (_| (_| | ||  __/" << std::endl;
    std::cout << "  \\_____|_|  \\___|\\__,_|\\__\\___|  \\_____\\___/|_| |_|\\__\\___\\__,_|\\__\\___|" << std::endl;
    std::cout << RESET << std::endl;
}

std::string valide_name()
{
    std::string name;

    std::cin.clear();
    do {
        std::cout << PURPLE << "  > " << RESET;
        std::getline(std::cin, name);
        if (name == "")
            std::cout << RED << "Invalid input" << RESET << std::endl;
    } while (name == "");
    std::cin.clear();
    return (name);
}

int valide_number()
{
    int index;

    std::cin.clear();
    do {
        std::cout << PURPLE << "  > " << RESET;
        std::cin >> index;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << RED << "Invalid input" << RESET << std::endl;
        }
    } while (index == 0);
    std::cin.clear();
    return (index);
}


void    Contact::create_contact()
{
    system("clear");
    print_creat_contact();
    std::cout << std::endl << BLUE << "═════════════════════════╗ Adding new contact ╔═════════════════════════" << RESET << std::endl << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    sleep(2);
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

int Contact::get_phone_number() {
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