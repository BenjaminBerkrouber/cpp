/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 05:13:36 by bberkrou          #+#    #+#             */
/*   Updated: 2024/04/18 18:44:48 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

void print_start()
{
	// system("clear");
    std::cout << PURPLE << "=============================================================================" << std::endl;
	std::cout << "	  _____  _                                 _ _______               " << std::endl;
	std::cout << " |  __ \\(_)                               | |__   __|              " << std::endl;
	std::cout << " | |  | |_  __ _ _ __ ___   ___  _ __   __| |  | |_ __ __ _ _ __   " << std::endl;
	std::cout << " | |  | | |/ _` | '_ ` _ \\ / _ \\| '_ \\ / _` |  | | '__/ _` | '_ \\  " << std::endl;
	std::cout << " | |__| | | (_| | | | | | | (_) | | | | (_| |  | | | | (_| | |_) | " << std::endl;
	std::cout << " |_____/|_|\\__,_|_| |_| |_|\\___/|_| |_|\\__,_|  |_|_|  \\__,_| .__/  " << std::endl;
	std::cout << "                                                           | |     " << std::endl;
	std::cout << "                                                           |_|     " << std::endl;
    std::cout << "=============================================================================" << RESET << std::endl << std::endl;
}

void	print_status_player(DiamondTrap& player)
{
	std::cout << std::endl << GREEN << "          " << player.getName() << RESET << std::endl;
	print_steve();
	std::cout << RED << "❤️ : "  << player.getHitPoints() << ORANGE << " | ⚡: " << player.getEnergyPoints() << PURPLE  << " | ⚔️ : " << player.getAttackDamage() << RESET << std::endl << std::endl;
}

void	set_status_player(DiamondTrap& player, int hitPoints, int energyPoints, int attackDamage)
{
	player.setHitPoints(hitPoints);
	usleep(800000);
	player.setEnergyPoints(energyPoints);
	usleep(800000);
	player.setAttackDamage(attackDamage);
	print_status_player(player);
}

void	pross_attaque(DiamondTrap& player1, DiamondTrap& player2)
{
	player1.attack("Bob");
	usleep(800000);
	player2.takeDamage(player1.getAttackDamage());
	usleep(800000);
	print_status_player(player1);
	print_status_player(player2);
	usleep(1000000);
}

void	pross_heal(DiamondTrap& player)
{
	player.beRepaired(player.getAttackDamage());
	usleep(800000);
	print_status_player(player);
	usleep(1000000);
}

void	print_game() {
	print_start();
	
	std::cout << std::endl << BLUE << "══════════════════════════╗    Spawning Challenger    ╔══════════════════════════" << RESET << std::endl << std::endl;	
	usleep(1000000);
	DiamondTrap steve("Steve");
	usleep(1000000);
	DiamondTrap bob("Bob");
	usleep(1000000);
    std::cout << std::endl << GREEN << "══════════════════════════╝    Challenger was Spawn   ╚══════════════════════════" << RESET << std::endl << std::endl;
	
	usleep(3000000);
	print_start();
	
	std::cout << std::endl << BLUE << "══════════════════════════╗    Challenger set status     ╔══════════════════════════" << RESET << std::endl << std::endl;
	set_status_player(steve, 100, 100, 30);
	set_status_player(bob, 100, 100, 30);
	std::cout << std::endl << GREEN << "══════════════════════════╝    Challenger take status   ╚══════════════════════════" << RESET << std::endl << std::endl;
	
	usleep(3000000);
	print_start();
	
	std::cout << std::endl << BLUE << "══════════════════════════╗    Challenger attack     ╔══════════════════════════" << RESET << std::endl << std::endl;
	pross_attaque(steve, bob);
	
	pross_heal(bob);
	
	pross_attaque(bob, steve);
	pross_attaque(steve, bob);
	bob.guardGate();
	steve.highFivesGuys();
	std::cout << std::endl << GREEN << "══════════════════════════╝    end attack   ╚══════════════════════════" << RESET << std::endl << std::endl;
}

void print_game_error() {
	print_start();
	
	std::cout << std::endl << BLUE << "══════════════════════════╗    Spawning Challenger    ╔══════════════════════════" << RESET << std::endl << std::endl;	
	usleep(1000000);
	DiamondTrap steve("Steve");
	usleep(1000000);
	DiamondTrap bob("Bob");
	usleep(1000000);
    std::cout << std::endl << GREEN << "══════════════════════════╝    Challenger was Spawn   ╚══════════════════════════" << RESET << std::endl << std::endl;
	
	usleep(3000000);
	print_start();
	
	std::cout << std::endl << BLUE << "══════════════════════════╗    Challenger set status     ╔══════════════════════════" << RESET << std::endl << std::endl;
	set_status_player(steve, 100, 100, 30);
	set_status_player(bob, 1, 1, 30);
	std::cout << std::endl << GREEN << "══════════════════════════╝    Challenger take status   ╚══════════════════════════" << RESET << std::endl << std::endl;
	
	usleep(3000000);
	print_start();
	
	std::cout << std::endl << BLUE << "══════════════════════════╗    Challenger attack     ╔══════════════════════════" << RESET << std::endl << std::endl;
	pross_attaque(steve, bob);
	
	pross_heal(bob);
	
	pross_attaque(bob, steve);
	pross_attaque(steve, bob);
	bob.guardGate();
	steve.highFivesGuys();
	std::cout << std::endl << GREEN << "══════════════════════════╝    end attack   ╚══════════════════════════" << RESET << std::endl << std::endl;
}

int main(int argc, char **argv)
{
	if (argc == 2 && std::string(argv[1]) == "game")
	{
		print_game();
	}
	else if (argc == 2 && std::string(argv[1]) == "error")
	{
		print_game_error();
	}
	else if (argc == 2 && std::string(argv[1]) == "default")
	{
		DiamondTrap steve("Steve");
		DiamondTrap copy_steve(steve);
		DiamondTrap bob("Bob");
		DiamondTrap bob_cpy = bob;

		steve.attack("Bob");
		bob.takeDamage(steve.getAttackDamage());
		bob.beRepaired(steve.getAttackDamage());
		bob.setAttackDamage(5);
		bob.setEnergyPoints(5);
		bob.setHitPoints(5);
		steve.setAttackDamage(5);
		steve.setEnergyPoints(5);
		steve.setHitPoints(5);
		steve.attack("Bob");
		bob.takeDamage(steve.getAttackDamage());
		steve.attack("Bob");
		bob.takeDamage(steve.getAttackDamage());
		bob.guardGate();
		steve.highFivesGuys();
		std::cout << std::endl;
		steve.whoAmI();
	}
	else
		std::cout << RED <<  "Usage: ./a.out <action> | action is [game-error-default]" << RESET << std::endl;
	return (0);
}
