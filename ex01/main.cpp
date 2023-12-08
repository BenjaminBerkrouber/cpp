#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

int main()
{
    PhoneBook phonebook;
    Contact contact;

    contact.create_contact();
    phonebook.add_contact(contact);
    phonebook.print_contact(contact);

    return 0;
}