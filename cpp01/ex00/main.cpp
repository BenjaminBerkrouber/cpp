/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:38:59 by bberkrou          #+#    #+#             */
/*   Updated: 2023/12/09 09:39:00 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.h"
# include "Zombie.hpp"

void print_start()
{
    std::cout << PURPLE << "=============================================================================" << std::endl;
    std::cout << "                    |___  /              | |   (_)     " << std::endl;
    std::cout << "                       / / ___  _ __ ___ | |__  _  ___ " << std::endl;
    std::cout << "                      / / / _ \\| '_ ` _ \\| '_ \\| |/ _ \\" << std::endl;
    std::cout << "                     / /_| (_) | | | | | | |_) | |  __/" << std::endl;
    std::cout << "                    /_____\\___/|_| |_| |_|_.__/|_|\\___|" << std::endl;
    std::cout << "=============================================================================" << RESET << std::endl << std::endl;
}


int main()
{
	Zombie *tom;
	Zombie *gabriel;
	Zombie *lucas;

	system("clear");
	print_start();

	std::cout << std::endl << BLUE << "═════════════════════════╗    Spawning Zombie    ╔═══════════════════════════" << RESET << std::endl << std::endl;

	tom = new_zombie("tom");
	usleep(350000);
	gabriel = new_zombie("gabriel");
	usleep(350000);
	lucas = new_zombie("lucas");
	usleep(350000);

    std::cout << std::endl << GREEN << "═════════════════════════╝    Zombie was Spawn   ╚═══════════════════════════" << RESET << std::endl;
	std::cout << std::endl;
	usleep(1000000);
	std::cout << std::endl << BLUE << "═════════════════════════╗    Zombie present     ╔═══════════════════════════" << RESET << std::endl << std::endl;
	
	tom->announce();
	usleep(350000);
	gabriel->announce();
	usleep(350000);
	lucas->announce();
	usleep(350000);

    std::cout << std::endl << GREEN << "═════════════════════════╝  You know all Zombie  ╚═══════════════════════════" << RESET << std::endl;
	std::cout << std::endl;
	usleep(1000000);
	std::cout << std::endl << BLUE << "═════════════════════════╗   Spawning was kill   ╔═══════════════════════════" << RESET << std::endl << std::endl;

	delete tom;
	usleep(350000);
	delete gabriel;
	usleep(350000);
	delete lucas;
	usleep(350000);

    std::cout << std::endl << GREEN << "═════════════════════════╝  All Zombie was kill  ╚══════════════════════════" << RESET << std::endl;
	std::cout << std::endl;
	usleep(1000000);
	std::cout << std::endl << BLUE << "═════════════════════╗   One Zombie create and dead  ╔═══════════════════════" << RESET << std::endl << std::endl;

	usleep(350000);

	randomChump("Anna");

    std::cout << std::endl << GREEN << "═════════════════════════╝       His dead        ╚═══════════════════════════" << RESET << std::endl;

	return (0);
}
