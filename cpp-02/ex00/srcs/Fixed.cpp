/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 01:26:09 by bberkrou          #+#    #+#             */
/*   Updated: 2023/12/13 02:10:12 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

// ------------- Constructors ------------- //

Fixed::Fixed(void) : _fixed_point_value() {
	std::cout << "Default constructor called" << std::endl;
	this->_fixed_point_value = 0;
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(fixed.getRawBits());
}

// ------------- Operator ------------- //

Fixed &Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        this->_fixed_point_value = fixed.getRawBits();
    return *this;
}

// ------------- Descturctor ------------- //

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

// ------------- Getter ------------- //

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed_point_value);
}

// ------------- Setter ------------- //

void	Fixed::setRawBits(int const raw) {
	this->_fixed_point_value = raw;
}

