/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:46:00 by bberkrou          #+#    #+#             */
/*   Updated: 2023/12/13 14:28:34 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

// -------- Constructors ---------

DiamondTrap::DiamondTrap(void) : ScavTrap(), FragTrap(), _Name("Default"){
	std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), _Name(name) {
	std::cout << "DiamondTrap Parametric constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) : ScavTrap(src), FragTrap(src){
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

// -------- Destructor ---------

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

// -------- Operators ---------

DiamondTrap &	DiamondTrap::operator=(DiamondTrap const &rhs) : ScavTrap(rhs), FragTrap(rhs) {
	std::cout << "DiamondTrap Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_Name = rhs._Name;
		this->_Hitpoints = rhs._Hitpoints;
		this->_Energy_points = rhs._Energy_points;
		this->_Attack_damage = rhs._Attack_damage;
	}
	return (*this);
}

// -------- Member functions ---------

void	DiamondTrap::attack(std::string const & target) : FragTrap::attack(target){
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "DiamondTrap name: " << this->_Name << std::endl;
	std::cout << "ScavTrap name: " << DiamondTrap.getName() << std::endl;
}