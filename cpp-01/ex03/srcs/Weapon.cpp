/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:51:39 by bberkrou          #+#    #+#             */
/*   Updated: 2024/03/01 21:48:38 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// ------------- Constructors -------------

Weapon::Weapon() {
	this->_type = "";
}

Weapon::Weapon(std::string type) {
	setType(type);
}

// ------------- Destructors -------------

Weapon::~Weapon() {
	
}

// ------------- Methods -------------


// ------------- Getters -------------

const std::string&	Weapon::getType() {
	std::string& type_ref = this->_type;
	return (type_ref);
}

// ------------- Setters -------------

void	Weapon::setType(std::string type) {
	this->_type = type;
}