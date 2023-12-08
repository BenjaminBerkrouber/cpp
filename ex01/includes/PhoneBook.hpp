#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>

class PhoneBook
{
    private:
        Contact contact[8];
        int     index;

    public:
        PhoneBook();
        void    add_contact(Contact contact);
        void    print_contact(Contact contact);
        Contact search_contact();
        void    clean_PhoneBook();
};

#endif