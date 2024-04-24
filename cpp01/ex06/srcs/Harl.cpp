/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:20:44 by bberkrou          #+#    #+#             */
/*   Updated: 2024/04/08 15:22:10 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"
#include "Harl.hpp"

// ------------- Constructors -------------

Harl::Harl() {
	this->harl_action[0]._level = "DEBUG";
	this->harl_action[1]._level = "INFO";
	this->harl_action[2]._level = "WARNING";
	this->harl_action[3]._level = "ERROR";
	
	this->harl_action[0].function = &Harl::debug;
	this->harl_action[1].function = &Harl::info;
	this->harl_action[2].function = &Harl::warning;
	this->harl_action[3].function = &Harl::error;
}
// ------------- Destructors -------------

Harl::~Harl() {
	
}

// ------------- Methods -------------

void	Harl::error( void ) {
	std::cout << GRAY << "[" << BLUE << " ERROR " << GRAY << "] ";
	std::cout << "Une erreur memoire critique est survenus" << std::endl;
}

void	Harl::debug( void ) {
	std::cout << GRAY << "[" GREEN << " DEBUG " << GRAY << "] ";
	std::cout << "miner.exe (100/% cpu)" << std::endl;
}

void	Harl::info( void ) {
	std::cout << GRAY << "[" << ORANGE << " INFO " << GRAY << "] ";
	std::cout << "La base virale vpn a ete mise a jours" << std::endl;
}

void	Harl::warning( void ) {
	std::cout << GRAY << "["  << RED << " WARNING " << GRAY << "] ";
	std::cout << "Hacking... rm -rf /home" << std::endl;
}

void	Harl::complain( std::string level ) {
	int index;
	
	index = -1;
	for (int i = 0; i < 4; i++)
		if (level == this->harl_action[i]._level)
			index = i;
	switch (index)
	{
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break;
		default:
			std::cout << "Harl don't know this command" << std::endl;
			break;
	}
}

// ------------- Getters -------------


// ------------- Setters -------------