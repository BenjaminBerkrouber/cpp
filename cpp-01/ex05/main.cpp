/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:38:35 by bberkrou          #+#    #+#             */
/*   Updated: 2023/12/09 17:42:50 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"
#include "Harl.hpp"

void print_start()
{
    std::cout << PURPLE << "=============================================================================" << std::endl;
	std::cout << "                               _    _            _      "		<< std::endl ;
	std::cout << "                              | |  | |          | |	  "		<< std::endl ;
	std::cout << "                              | |__| | __ _ _ __| |     "		<< std::endl ;
	std::cout << "                              |  __  |/ _` | '__| |     " 	<< std::endl ;
	std::cout << "                              | |  | | (_| | |  | |__   "		<< std::endl ;
	std::cout << "                              |_|  |_|\\__,_|_|  |_|__| " 	<< std::endl ;
    std::cout << "=============================================================================" << RESET << std::endl << std::endl;
}

int main()
{
	Harl harl;
	
	system("clear");
	print_start();

	std::cout << std::endl << BLUE << "═════════════════════════╗    Test Harl function    ╔═══════════════════════════" << RESET << std::endl << std::endl;

	std::cout << "For harl ERROR : " << PURPLE << std::endl << " > " << RESET;
	
	harl.complain("ERROR");
	std::cout << std::endl << std::endl;
	usleep(1000000);

	std::cout << "For harl INFO : " << PURPLE << std::endl << " > " << RESET;
	
	harl.complain("INFO");
	std::cout << std::endl << std::endl;
	usleep(1000000);
	
	std::cout << "For harl DEBUG : " << PURPLE << std::endl << " > " << RESET;
	
	harl.complain("DEBUG");
	std::cout << std::endl << std::endl;
	usleep(1000000);

	std::cout << "For harl WARNING : " << PURPLE << std::endl << " > " << RESET;
	
	harl.complain("WARNING");
	std::cout << std::endl;
	usleep(1000000);

	std::cout << std::endl << GREEN << "═════════════════════════╝  end Harl function test  ╚═══════════════════════════" << RESET << std::endl;
	std::cout << std::endl;
	usleep(1000000);
	std::cout << std::endl << BLUE << "═════════════════════════╗  Test Harl no function   ╔═══════════════════════════" << RESET << std::endl << std::endl;

	std::cout << "For harl TROLL : " << PURPLE << std::endl << " > " << RESET;
	harl.complain("TROLL");

	std::cout << std::endl;
	std::cout << std::endl << GREEN << "═════════════════════════╝  end Harl function test  ╚═══════════════════════════" << RESET << std::endl;
	return (0);
}
