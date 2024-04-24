/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:46:00 by bberkrou          #+#    #+#             */
/*   Updated: 2024/04/18 18:46:53 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

// -------- Constructors ---------

DiamondTrap::DiamondTrap(void) : ScavTrap(), FragTrap(), _Name("Default"){
	std::cout << std::endl << "DiamondTrap Default constructor called" << std::endl;
	print_steve();
	// std::cout << RED << "❤️ : "  << _Hitpoints << ORANGE << " | ⚡: " << _Energy_points << PURPLE  << " | ⚔️ : " << _Attack_damage << RESET << std::endl << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name) {
	std::cout << "DiamondTrap Parametric constructor called" << std::endl;
	this->_Name = name;
	this->ClapTrap::setName(name + "_clap_name");

	FragTrap::setHitPoints(100);
	ScavTrap::setEnergyPoints(50);
	FragTrap::setAttackDamage(30);
	std::cout << std::endl << GREEN << "          " << getName() << RESET << std::endl;
	print_steve();
	std::cout << RED << "❤️ : "  << getHitPoints() << ORANGE << " | ⚡: " << getEnergyPoints() << PURPLE  << " | ⚔️ : " << getAttackDamage() << RESET << std::endl << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(src), ScavTrap(src), FragTrap(src) {
    std::cout << std::endl << "DiamondTrap Copy constructor called" << std::endl;
    this->_Name = src._Name + "_copy";
    this->ClapTrap::setName(src._Name + "_clap_name");

    this->setHitPoints(src.getHitPoints());
    this->setEnergyPoints(src.getEnergyPoints());
    this->setAttackDamage(src.getAttackDamage());

    std::cout << std::endl << GREEN << "          " << getName() << RESET << std::endl;
    print_steve();
    std::cout << RED << "❤️ : "  << getHitPoints() << ORANGE << " | ⚡: " << getEnergyPoints() << PURPLE  << " | ⚔️ : " << getAttackDamage() << RESET << std::endl << std::endl;
}


// -------- Destructor ---------

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

// -------- Operators ---------

DiamondTrap &	DiamondTrap::operator=(DiamondTrap const &rhs) {
	std::cout << "DiamondTrap Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		// this->_Name = rhs._Name;
		// this->_Hitpoints = rhs._Hitpoints;
		// this->_Energy_points = rhs._Energy_points;
		// this->_Attack_damage = rhs._Attack_damage;
	}
	return (*this);
}

// -------- Member functions ---------

void DiamondTrap::whoAmI(void) {
    std::cout << "DiamondTrap name: " << this->_Name << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::getName() << std::endl;
}
