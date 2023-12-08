#ifndef CONTACT_H
# define CONTACT_H

# include <string>

class Contact {
    private:
        std::string first_name;
        std::string last_name;
        std::string nick_name;
        int         phone_number;
        std::string dark_secret;
    
    public:
        Contact();
        Contact     create_contact();
        std::string get_first_name();
        std::string get_last_name();
        std::string get_nick_name();
        int         get_phone_number();
        std::string get_dark_secret();
        void        set_first_name(std::string first_name);
        void        set_last_name(std::string last_name);
        void        set_nick_name(std::string nick_name);
        void        set_phone_number(int phone_number);
        void        set_dark_secret(std::string dark_secret);
};

#endif