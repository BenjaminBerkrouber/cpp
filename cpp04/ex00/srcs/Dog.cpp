/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 08:35:53 by bberkrou          #+#    #+#             */
/*   Updated: 2024/02/28 08:36:08 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    _type = "Dog";
    std::cout << "Dog: Default constructor called" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src) {
    std::cout << "Dog: Copy constructor called" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog: Destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs) {
    Animal::operator=(rhs);
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}
