/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 08:38:01 by bberkrou          #+#    #+#             */
/*   Updated: 2024/02/28 08:46:46 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    _type = "Cat";
    std::cout << "Cat: Default constructor called" << std::endl;
}

Cat::Cat(Cat & ref)
{
	this->type = ref.getType();
	std::cout << "A cat was constructed from copy\n";
}

Cat::~Cat() {
    std::cout << "Cat: Destructor called" << std::endl;
}


Cat &Cat::operator=(const Cat &rhs) {
    Animal::operator=(rhs);
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}
