/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:38:35 by bberkrou          #+#    #+#             */
/*   Updated: 2023/12/09 17:59:49 by bberkrou         ###   ########.fr       */
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

int main(int argc, char **argv)
{
	Harl harl;
	
	if (argc != 2)
	{
		std::cout << RED << "Error, the programme need only 1 args" << RESET << std::endl;
		return (1);
	}
	
	system("clear");
	print_start();

	std::cout << std::endl << BLUE << "═════════════════════════╗    Test Harl function    ╔═══════════════════════════" << RESET << std::endl << std::endl;

	harl.complain(argv[1]);

	std::cout << std::endl << GREEN << "═════════════════════════╝  end Harl function test  ╚═══════════════════════════" << RESET << std::endl;
	return (0);
}
