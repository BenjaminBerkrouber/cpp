/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:20:47 by bberkrou          #+#    #+#             */
/*   Updated: 2023/12/09 11:22:04 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define PURPLE "\033[35m"
# define RED    "\033[31m"
# define GREEN  "\033[32m"
# define BLUE   "\033[34m"
# define RESET  "\033[0m"

# include <unistd.h>
# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <limits>
# include <sstream>
# include <cstdlib>
# include <cctype>

void print_start()
{
    std::cout << PURPLE << "=============================================================================" << std::endl;
	std::cout << "           _____ _______ _____         _     _____  ______ ______        " 		<< std::endl ;
	std::cout << "           |  __ \\__   __|  __ \\       | |   |  __ \\|  ____|  ____|   " 		<< std::endl ;
	std::cout << "           | |__) | | |  | |__) |   ___| |_  | |__) | |__  | |__         " 		<< std::endl ;
	std::cout << "           |  ___/  | |  |  _  /   / _ \\ __| |  _  /|  __| |  __|       " 		<< std::endl ;
	std::cout << "           | |      | |  | | \\ \\  |  __/ |_  | | \\ \\| |____| |       " 		<< std::endl ;
	std::cout << "           |_|      |_|  |_|  \\_\\  \\___|\\__| |_|  \\_\\______|_|     " 		<< std::endl ;
    std::cout << "=============================================================================" << RESET << std::endl << std::endl;
}

void convertToUpperCase(std::string &str) {
    for (size_t i = 0; i < str.length(); ++i) {
        str[i] = std::toupper(static_cast<unsigned char>(str[i]));
    }
}

void convertToLowerCase(std::string &str) {
    for (size_t i = 0; i < str.length(); ++i) {
        str[i] = std::tolower(static_cast<unsigned char>(str[i]));
    }
}

int main()
{
	std::string str;
	std::string	*stringPTR;
	std::string& stringREF = str;

	str = "HI THIS IS BRAIN";
	stringPTR = &str;
	
	system("clear");
	print_start();

	std::cout << std::endl << BLUE << "══════════════════════════╗    Address part   ╔══════════════════════════" << RESET << std::endl << std::endl;
	
	std::cout << "str address : " << &str << std::endl;
	std::cout << "ptr address : " << stringPTR << std::endl;
	std::cout << "ref address : " << &stringREF << std::endl;
	
	std::cout << std::endl << GREEN << "══════════════════════════╝    end Address part   ╚══════════════════════════" << RESET << std::endl;
	std::cout << std::endl;
	usleep(1000000);
	std::cout << std::endl << BLUE << "══════════════════════════╗    Value part   ╔══════════════════════════" << RESET << std::endl << std::endl;
	
	std::cout << "str value : " << str << std::endl;
	std::cout << "ptr value : " << *stringPTR << std::endl;
	std::cout << "ref value : " << stringREF << std::endl;
	
	std::cout << std::endl << GREEN << "══════════════════════════╝    end Value part   ╚══════════════════════════" << RESET << std::endl;
	std::cout << std::endl;
	usleep(1000000);
	std::cout << std::endl << BLUE << "══════════════════════════╗   Analyse upadte     ╔══════════════════════════" << RESET << std::endl << std::endl;

	std::cout << "Basique value" << std::endl;
	std::cout << "str value : " << str << std::endl;
	std::cout << "ptr value : " << *stringPTR << std::endl;
	std::cout << "ref value : " << stringREF << std::endl;
	
	convertToLowerCase(str); 
	
	std::cout << std::endl << "Update value" << std::endl;
	std::cout << "str value : " << str << std::endl;
	std::cout << "ptr value : " << *stringPTR << std::endl;
	std::cout << "ref value : " << stringREF << std::endl;
	
	convertToUpperCase(str);
	
	std::cout << std::endl << GREEN << "══════════════════════════╝    end upadte part   ╚══════════════════════════" << RESET << std::endl;
	std::cout << std::endl;	
	usleep(1000000);
	std::cout << std::endl << BLUE << "══════════════════════════╗   Difference     ╔══════════════════════════" << RESET << std::endl << std::endl;

	std::cout << "A pointer is a variable that holds the memory address of an object" << std::endl
			<< "and can be reassigned or set to nullptr." << std::endl << std::endl;
	std::cout << "A reference is an alias for an existing object and must be initialized" << std::endl 
			<< "when declared, and cannot be null." << std::endl << std::endl;
	std::cout << "Their difference is that pointers offer flexibility and can point to" << std::endl
			<< "nothing, while references provide safety by always referencing an existing object." << std::endl;
	
	std::cout << std::endl << GREEN << "══════════════════════════╝    end differnent part   ╚══════════════════════════" << RESET << std::endl;
}