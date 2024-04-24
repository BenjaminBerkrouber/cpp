/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:33:24 by bberkrou          #+#    #+#             */
/*   Updated: 2023/12/09 13:26:01 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "Weapon.h"
#include "HumanB.hpp"

// ------------- Constructors -------------

HumanB::HumanB(std::string name) {
	this->_name = name;
	this->_weapon = NULL;
}

// ------------- Destructors -------------

HumanB::~HumanB() {
	
}

// ------------- Methods -------------

void HumanB::attack() {
    if (_weapon) {
        std::cout << this->_name << " attacks with their " << _weapon->getType() << std::endl;
    } else {
        std::cout << this->_name << " has no weapon" << std::endl;
    }
}

// ------------- Getters -------------

std::string	HumanB::getName() {
	return (this->_name);
}

Weapon* HumanB::getWeapon() {
    return this->_weapon;
}

// ------------- Setters -------------

void HumanB::setWeapon(Weapon& weapon) {
    this->_weapon = &weapon;
}


void	HumanB::setName(std::string name) {
	this->_name = name;
}