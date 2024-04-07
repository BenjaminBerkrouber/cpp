/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:38:09 by bberkrou          #+#    #+#             */
/*   Updated: 2023/12/09 09:38:43 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.h"
# include "Zombie.hpp"

// ------------- Constructors -------------

Zombie::Zombie()
{
	std::cout << "A zombie was spawn !" << std::endl;
	this->_name = "";
}

// ------------- Destructors -------------

Zombie::~Zombie() {
	std::cout << get_name() << " was killed by Steve" << std::endl;
}

// ------------- Methods -------------

void	Zombie::announce() {
	std::cout << get_name() << " BraiiiiiiinnnzzzZ..." << std::endl;
}

// ------------- Getters -------------

std::string	Zombie::get_name() {
	return this->_name;
}

// ------------- Setters -------------

void	Zombie::set_zombie(std::string name) {
	this->_name = name;
}

