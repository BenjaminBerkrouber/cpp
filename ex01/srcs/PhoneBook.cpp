#include "PhoneBook.hpp"

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
}

void    PhoneBook::print_contact(Contact contact)
{
    std::cout << "First name: " << contact.get_first_name() << std::endl;
    std::cout << "Last name: " << contact.get_last_name() << std::endl;
    std::cout << "Nick name: " << contact.get_nick_name() << std::endl;
    std::cout << "Phone number: " << contact.get_phone_number() << std::endl;
    std::cout << "Dark secret: " << contact.get_dark_secret() << std::endl;
}

void    PhoneBook::add_contact(Contact contact)
{
    if (this->index > 7)
        this->index = 0;
    this->contact[this->index] = contact;
    this->index++;
}