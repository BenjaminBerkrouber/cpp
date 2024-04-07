/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:20:44 by bberkrou          #+#    #+#             */
/*   Updated: 2023/12/09 18:06:59 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"
#include "Harl.hpp"

// ------------- Constructors -------------

Harl::Harl() {
	this->harl_action[0]._level = "WARNING";
	this->harl_action[1]._level = "ERROR";
	this->harl_action[2]._level = "INFO";
	this->harl_action[3]._level = "DEBUG";
	
	this->harl_action[0].function = &Harl::warning;
	this->harl_action[1].function = &Harl::error;
	this->harl_action[2].function = &Harl::debug;
	this->harl_action[3].function = &Harl::info;
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
		this->warning();
	case 1:
		this->error();
	case 2:
		this->info();
	case 3:
		this->debug();
		break;
	default:
		std::cout << "Harl don't know this command" << std::endl;
		break;
	}
}

// ------------- Getters -------------


// ------------- Setters -------------