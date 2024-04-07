/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 04:23:25 by bberkrou          #+#    #+#             */
/*   Updated: 2024/02/28 08:34:54 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// ------ Constructors  ------ //

Animal::Animal() : _type("Undefined") {
    std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::Animal(const Animal &src) : _type(src._type) {
    std::cout << "Animal: Copy constructor called" << std::endl;
}
// ------ Destructor ------ //

Animal::~Animal() {
    std::cout << "Animal: Destructor called" << std::endl;
}

// ------ Operators ------ //

Animal &Animal::operator=(const Animal &rhs) {
    if (this != &rhs) {
        _type = rhs._type;
    }
    return *this;
}

// ------ Member functions ------ //

void Animal::makeSound() const {
    std::cout << "Animal makes a sound." << std::endl;
}

// ------ Getters ------ //

std::string Animal::getType() const {
    return _type;
}

// ------ Setters ------ //

void Animal::setType(const std::string &type) {
    _type = type;
}

