#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>

class PhoneBook
{
    private:
        Contact contact[8];
        int     index;
        int     contact_count;

    public:
        // constructors
        PhoneBook();

        // destructors
        ~PhoneBook();

        // getters
        Contact get_contact(int index);

        // setters
        void    set_contact(Contact contact);
        
        // methods
        void    print_contact(Contact contact, int index);
        void search_contact();
};

#endif