/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:17:45 by bberkrou          #+#    #+#             */
/*   Updated: 2023/12/09 13:25:13 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "Weapon.h"
#include "HumanA.hpp"

// ------------- Constructors -------------

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon) {
	this->_weapon = weapon;
	setName(name);
}

// ------------- Destructors -------------

HumanA::~HumanA() {
	
}

// ------------- Methods -------------

void	HumanA::attack() {
	std::cout << getName() << " attacks with their " << getWeapon().getType() << std::endl;
}

// ------------- Getters -------------

std::string	HumanA::getName() {
	return (this->_name);
}

Weapon	HumanA::getWeapon() {
	return (this->_weapon);
}

// ------------- Setters -------------

void	HumanA::setWeapon(Weapon weapon) {
	this->_weapon = weapon;
}

void	HumanA::setName(std::string name) {
	this->_name = name;
}