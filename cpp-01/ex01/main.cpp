/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:40:04 by bberkrou          #+#    #+#             */
/*   Updated: 2023/12/09 10:18:06 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.h"
# include "Zombie.hpp"

void print_start()
{
    std::cout << PURPLE << "=============================================================================" << std::endl;
	std::cout << "    ______               _     _         _    _               _       " 		<< std::endl ;
	std::cout << "    |___  /              | |   (_)       | |  | |             | |      " 		<< std::endl ;
	std::cout << "       / / ___  _ __ ___ | |__  _  ___   | |__| | ___  _ __ __| |      " 		<< std::endl ;
	std::cout << "      / / / _ \\| '_ ` _ \\| '_ \\| |/ _ \\  |  __  |/ _ \\| '__/ _` | / _ \\" 		<< std::endl ;
	std::cout << "     / /_| (_) | | | | | | |_) | |  __/  | |  | | (_) | | | (_| ||  __/" 		<< std::endl ;
	std::cout << "    /_____\\___/|_| |_| |_|_.__/|_|\\___|  |_|  |_|\\___/|_|  \\__,_| \\___| " 		<< std::endl ;
    std::cout << "=============================================================================" << RESET << std::endl << std::endl;
}

int main()
{
	Zombie *zombie_hord;
	int		number_zombie;

	number_zombie = 10;

	system("clear");
	print_start();
	std::cout << std::endl << BLUE << "══════════════════════════╗    Spawning Zombie    ╔══════════════════════════" << RESET << std::endl << std::endl;

	zombie_hord = zombieHorde(number_zombie, "bberkrou");

    std::cout << std::endl << GREEN << "══════════════════════════╝    Zombie was Spawn   ╚══════════════════════════" << RESET << std::endl;
	std::cout << std::endl;
	usleep(1000000);
	std::cout << std::endl << BLUE << "══════════════════════════╗    Zombie present     ╔══════════════════════════" << RESET << std::endl << std::endl;
	
	for (int i = 0; i < number_zombie ; i++)
		zombie_hord[i].announce();

    std::cout << std::endl << GREEN << "══════════════════════════╝  You know all Zombie  ╚══════════════════════════" << RESET << std::endl;
	std::cout << std::endl;
	usleep(1000000);
	std::cout << std::endl << BLUE << "══════════════════════════╗   Spawning was kill   ╔══════════════════════════" << RESET << std::endl << std::endl;

	delete[] zombie_hord;
	
    std::cout << std::endl << GREEN << "══════════════════════════╝  All Zombie was kill  ╚═════════════════════════" << RESET << std::endl;
	std::cout << std::endl;


	return (0);
}
	