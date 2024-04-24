/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 03:06:21 by bberkrou          #+#    #+#             */
/*   Updated: 2023/12/09 03:06:23 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        void    print_line_info(std::string key, std::string value);
        void    search_contact();
        void    print_contact_list();
        void    chose_contact();
        void    print_contact_info(int index);
};

#endif