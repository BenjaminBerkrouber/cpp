/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 01:26:09 by bberkrou          #+#    #+#             */
/*   Updated: 2024/02/28 06:50:29 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// ------------- Constructors ------------- //

Fixed::Fixed() : fixed_point_value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : fixed_point_value(value << fractional_bits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : fixed_point_value(roundf(value * (1 << fractional_bits))) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &source) : fixed_point_value(source.fixed_point_value) {
    std::cout << "Copy constructor called" << std::endl;
}

// ------------- Destructor ------------- //

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// ------------- Operator Overloads ------------- //

Fixed &Fixed::operator=(const Fixed &rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->fixed_point_value = rhs.fixed_point_value;
    }
    return *this;
}

// ------------- Public Member Functions ------------- //

int Fixed::toInt(void) const {
    return fixed_point_value >> fractional_bits;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(fixed_point_value) / (1 << fractional_bits);
}

// ------------- Non-member Function Overloads ------------- //

std::ostream &operator<<(std::ostream &out, const Fixed &value) {
    out << value.toFloat();
    return out;
}

