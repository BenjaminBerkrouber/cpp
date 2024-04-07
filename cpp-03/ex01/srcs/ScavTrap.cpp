/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:11:37 by bberkrou          #+#    #+#             */
/*   Updated: 2023/12/13 10:45:50 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

// ------- Constructor --------

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << GREEN << "ScavTrap Default Constructor called" << RESET << std::endl;
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << GREEN << "ScavTrap Parameter Constructor called" << RESET << std::endl;
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
    std::cout << "Now you are a ScavTrap, a new challenger" << std::endl;
    std::cout << GREEN << "          " << getName() << RESET << std::endl;
    print_steve();
    std::cout << RED << "❤️ : " << getHitPoints() << ORANGE << " | ⚡: " << getEnergyPoints() << PURPLE << " | ⚔️ : " << getAttackDamage() << RESET << std::endl << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src) {
    std::cout << GREEN << "ScavTrap Copy Constructor called" << RESET << std::endl;
}

// ------- Destructor ---------

ScavTrap::~ScavTrap() {
    std::cout << RED << "ScavTrap Destructor called" << RESET << std::endl;
}

// ------- Operator Overload ---------

ScavTrap &ScavTrap::operator=(const ScavTrap &obj) {
    std::cout << GREEN << "ScavTrap Assignation operator called" << RESET << std::endl;
    if (this != &obj) {
        ClapTrap::operator=(obj);	
    }
    return *this;
}

// ------- Member Function ---------

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << getName() << " have entered in Gate keeper mode" << std::endl;
}

