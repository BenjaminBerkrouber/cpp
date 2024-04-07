/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 06:47:04 by bberkrou          #+#    #+#             */
/*   Updated: 2024/02/28 07:00:14 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
    public:
        // ------------- Constructors & Destructor ------------- //
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &source);
        ~Fixed();

        // ------------- Assignment Operator ------------- //
        Fixed &operator=(const Fixed &rhs);

        // ------------- Comparison Operators ------------- //
        bool operator>(const Fixed &rhs) const;
        bool operator<(const Fixed &rhs) const;
        bool operator>=(const Fixed &rhs) const;
        bool operator<=(const Fixed &rhs) const;
        bool operator==(const Fixed &rhs) const;
        bool operator!=(const Fixed &rhs) const;

        // ------------- Arithmetic Operators ------------- //
        Fixed operator+(const Fixed &rhs) const;
        Fixed operator-(const Fixed &rhs) const;
        Fixed operator*(const Fixed &rhs) const;
        Fixed operator/(const Fixed &rhs) const;

        // ------------- Increment/Decrement Operators ------------- //
        Fixed &operator++();    // Pre-increment
        Fixed operator++(int);  // Post-increment
        Fixed &operator--();    // Pre-decrement
        Fixed operator--(int);  // Post-decrement

        // ------------- Min/Max Static Functions ------------- //
        static Fixed &min(Fixed &lhs, Fixed &rhs);
        static const Fixed &min(const Fixed &lhs, const Fixed &rhs);
        static Fixed &max(Fixed &lhs, Fixed &rhs);
        static const Fixed &max(const Fixed &lhs, const Fixed &rhs);

        // ------------- Conversion Functions ------------- //
        int toInt(void) const;
        float toFloat(void) const;

    private:
        int fixed_point_value;
        static const int fractional_bits = 8;
};

// ------------- Stream Insertion Operator ------------- //
std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif // FIXED_HPP

