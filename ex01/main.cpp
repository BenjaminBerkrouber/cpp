#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include "utils.h"

void    print_start()
{
    std::cout << PURPLE << "=========================================================" << std::endl;
    std::cout << "  _____  _                        ____              _    "        << std::endl;
    std::cout << " |  __ \\| |                      |  _ \\            | |   "      << std::endl;
    std::cout << " | |__) | |__   ___  _ __   ___  | |_) | ___   ___ | | __"        << std::endl;
    std::cout << " |  ___/| '_ \\ / _ \\| '_ \\ / _ \\ |  _ < / _ \\ / _ \\| |/ /"  << std::endl;
    std::cout << " | |    | | | | (_) | | | |  __/ | |_) | (_) | (_) |   < "        << std::endl;
    std::cout << " |_|    |_| |_|\\___/|_| |_|\\___| |____/ \\___/ \\___/|_|\\_\\"  << std::endl;
    std::cout << std::endl << "=========================================================" << RESET << std::endl;
}

void    print_rules()
{
    std::cout << std::endl;
    std::cout << "Rules:" << std::endl;
    std::cout << "  - ADD: Add a new contact" << std::endl;
    std::cout << "  - SEARCH: Search a contact" << std::endl;
    std::cout << "  - EXIT: Exit the program" << std::endl;
    std::cout << std::endl << std::endl;
}

void    print_end()
{
    std::cout << PURPLE << std::endl;
    std::cout << "   _____                 _   _                  _ "       << std::endl;
    std::cout << "  / ____|               | | | |                | |"       << std::endl;
    std::cout << " | |  __  ___   ___   __| | | |__  _   _  ___  | |"       << std::endl;
    std::cout << " | | |_ |/ _ \\ / _ \\ / _` | | '_ \\| | | |/ _ \\ | |"   << std::endl;
    std::cout << " | |__| | (_) | (_) | (_| | | |_) | |_| |  __/ |_|"       << std::endl;
    std::cout << "  \\_____|\\___/ \\___/ \\__,_| |_.__/ \\__, |\\___| (_)"  << std::endl;
    std::cout << "                                    __/ |         "       << std::endl;
    std::cout << "                                   |___/          "       << std::endl;
    std::cout << std::endl;
}


int main()
{
    PhoneBook   phonebook;
    Contact     new_contact;
    std::string command;

    system("clear");
    print_start();
    print_rules();
    while (1)
    {
        std::cout << PURPLE << "  > " << RESET;
        std::cin.clear();
        std::cin >> command;
        if (command == "EXIT")
        {
            system("clear");
            print_end();
            break ;
        }
        else if (command == "ADD")
        {
            new_contact.create_contact();
            phonebook.set_contact(new_contact);
        }
        else if (command == "SEARCH")
        {
            phonebook.search_contact();
        }
        else
            std::cout << "Invalid command" << std::endl;
    }

    return 0;
}