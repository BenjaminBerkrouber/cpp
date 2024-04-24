/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:05:41 by bberkrou          #+#    #+#             */
/*   Updated: 2024/04/18 18:28:10 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.h"

// ------ Constructors  ------ //

FragTrap::FragTrap() : ClapTrap() {
    std::cout << GREEN << "FragTrap Default Constructor called" << RESET << std::endl;
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(20);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << GREEN << "FragTrap Parameter Constructor called" << RESET << std::endl;
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(20);
    std::cout << "Now you are a FragTrap, a new challenger" << std::endl;
    std::cout << std::endl << GREEN << "          " << getName() << RESET << std::endl;
    print_steve();
    std::cout << RED << "❤️ : " << getHitPoints() << ORANGE << " | ⚡: " << getEnergyPoints() << PURPLE << " | ⚔️ : " << getAttackDamage() << RESET << std::endl << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src) {
	std::cout << "FragTrap Copy constructor called" << std::endl;
}

// ------ Destructor ------ //

FragTrap::~FragTrap() {
    std::cout << RED << "FragTrap Destructor called" << RESET << std::endl;
}

// ------ Operators ------ //

FragTrap &FragTrap::operator=(const FragTrap &obj) {
    std::cout << GREEN << "FragTrap Assignation operator called" << RESET << std::endl;
    if (this != &obj) {
        ClapTrap::operator=(obj);	
    }
    return *this;
}

// ------ Member functions ------ //

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << getName() << " want to high five" << std::endl;
}
