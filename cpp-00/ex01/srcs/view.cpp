/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 03:06:55 by bberkrou          #+#    #+#             */
/*   Updated: 2023/12/09 04:48:14 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void    print_search_contact()
{
    std::cout << PURPLE << std::endl;
    std::cout << "  / ____|                   | |                     | |           | |  " << std::endl;
    std::cout << " | (___   ___  __ _ _ __ ___| |__     ___ ___  _ __ | |_ __ _  ___| |_ " << std::endl;
    std::cout << "  \\___ \\ / _ \\/ _` | '__/ __| '_ \\   / __/ _ \\| '_ \\| __/ _` |/ __| __|" << std::endl;
    std::cout << "  ____) |  __/ (_| | | | (__| | | | | (_| (_) | | | | || (_| | (__| |_ " << std::endl;
    std::cout << " |_____/ \\___|\\__,_|_|  \\___|_| |_|  \\___\\___/|_| |_|\\__\\__,_|\\___|\\__|" << std::endl;
    std::cout << "                                                                        " << std::endl;
    std::cout << RESET << std::endl;
}

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
    std::cout << RESET << std::endl;
}

void print_top_contact()
{
    system("clear");
    print_search_contact();
    std::cout << std::endl << BLUE << "════════════════════════╗ Chose your contact ╔═════════════════════════" << RESET << std::endl << std::endl;
    std::cout << std::endl;
    std::cout << "╒══════════╤══════════╤══════════╤══════════╕" << std::endl;
    std::cout << "│     index│first name│ last name│  nickname│" << std::endl;
    std::cout << "╞══════════╪══════════╪══════════╪══════════╡" << std::endl;
}