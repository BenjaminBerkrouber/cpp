/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 06:47:04 by bberkrou          #+#    #+#             */
/*   Updated: 2024/02/28 06:55:24 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include "Fixed.h"

#include <iostream>
#include <cmath>

class Fixed {
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &source);
        ~Fixed(); 

        Fixed &operator=(const Fixed &rhs);

        int toInt(void) const;
        float toFloat(void) const;

        static const int fractional_bits = 8;

    private:
        int fixed_point_value;
};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif
