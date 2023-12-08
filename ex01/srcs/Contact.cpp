#include "Contact.hpp"
#include <iostream>

Contact::Contact(){
    this->first_name = "";
    this->last_name = "";
    this->nick_name = "";
    this->phone_number = 0;
    this->dark_secret = "";
}

Contact Contact::create_contact() {
    Contact contact;
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    int phone_number;
    std::string dark_secret;

    std::cout << "Enter first name: ";
    std::getline(std::cin, first_name);
    contact.set_first_name(first_name);

    std::cout << "Enter last name: ";
    std::getline(std::cin, last_name);
    contact.set_last_name(last_name);

    std::cout << "Enter nick name: ";
    std::getline(std::cin, nick_name);
    contact.set_nick_name(nick_name);

    std::cout << "Enter phone number: ";
    std::cin >> phone_number;
    contact.set_phone_number(phone_number);

    std::cout << "Enter dark secret: ";
    std::cin.ignore();
    std::getline(std::cin, dark_secret);
    contact.set_dark_secret(dark_secret);

    return contact;
}


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