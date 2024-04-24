/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 01:26:09 by bberkrou          #+#    #+#             */
/*   Updated: 2024/02/28 07:03:29 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// ------------- Constructors ------------- //

Fixed::Fixed() : fixed_point_value(0) {
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : fixed_point_value(value << fractional_bits) {
    // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : fixed_point_value(roundf(value * (1 << fractional_bits))) {
    // std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &source) : fixed_point_value(source.fixed_point_value) {
    // std::cout << "Copy constructor called" << std::endl;
}

// ------------- Destructor ------------- //

Fixed::~Fixed() {
    // std::cout << "Destructor called" << std::endl;
}

// ------------- Operator Overloads ------------- //

Fixed &Fixed::operator=(const Fixed &rhs) {
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->fixed_point_value = rhs.fixed_point_value;
    }
    return *this;
}

// ------------- Comparison Operators ------------- //

bool Fixed::operator>(const Fixed &rhs) const {
    return this->fixed_point_value > rhs.fixed_point_value;
}

bool Fixed::operator<(const Fixed &rhs) const {
    return this->fixed_point_value < rhs.fixed_point_value;
}

bool Fixed::operator>=(const Fixed &rhs) const {
    return !(*this < rhs);
}

bool Fixed::operator<=(const Fixed &rhs) const {
    return !(*this > rhs);
}

bool Fixed::operator==(const Fixed &rhs) const {
    return this->fixed_point_value == rhs.fixed_point_value;
}

bool Fixed::operator!=(const Fixed &rhs) const {
    return !(*this == rhs);
}

// ------------- Arithmetic Operators ------------- //

Fixed Fixed::operator+(const Fixed &rhs) const {
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs) const {
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs) const {
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const {
    if (rhs.fixed_point_value != 0) {
        return Fixed(this->toFloat() / rhs.toFloat());
    } else {
        std::cerr << "Error: Division by zero." << std::endl;
        return Fixed();
    }
}

// ------------- Increment/Decrement Operators ------------- //

Fixed &Fixed::operator++() {
    this->fixed_point_value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++(*this);
    return temp;
}

Fixed &Fixed::operator--() {
    this->fixed_point_value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --(*this);
    return temp;
}

// ------------- Min/Max Functions ------------- //

Fixed &Fixed::min(Fixed &lhs, Fixed &rhs) {
    return (lhs < rhs) ? lhs : rhs;
}

const Fixed &Fixed::min(const Fixed &lhs, const Fixed &rhs) {
    return (lhs < rhs) ? lhs : rhs;
}

Fixed &Fixed::max(Fixed &lhs, Fixed &rhs) {
    return (lhs > rhs) ? lhs : rhs;
}

const Fixed &Fixed::max(const Fixed &lhs, const Fixed &rhs) {
    return (lhs > rhs) ? lhs : rhs;
}

// ------------- Conversion Functions ------------- //

int Fixed::toInt(void) const {
    return fixed_point_value >> fractional_bits;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(fixed_point_value) / (1 << fractional_bits);
}

// ------------- Stream Insertion Operator ------------- //

std::ostream &operator<<(std::ostream &out, const Fixed &value) {
    out << value.toFloat();
    return out;
}
