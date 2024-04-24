/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 03:06:09 by bberkrou          #+#    #+#             */
/*   Updated: 2024/03/01 21:34:28 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <string>

class Contact {
    private:
        std::string first_name;
        std::string last_name;
        std::string nick_name;
        long    phone_number;
        std::string dark_secret;
    
    public:
        // constructors
        Contact();

        // destructors
        ~Contact();

        // getters
        std::string     get_first_name();
        std::string     get_last_name();
        std::string     get_nick_name();
        long            get_phone_number();
        std::string     get_dark_secret();

        // setters
        void            set_first_name(std::string first_name);
        void            set_last_name(std::string last_name);
        void            set_nick_name(std::string nick_name);
        void            set_phone_number(int phone_number);
        void            set_dark_secret(std::string dark_secret);
        
        // methods
        void            create_contact();

};

#endif