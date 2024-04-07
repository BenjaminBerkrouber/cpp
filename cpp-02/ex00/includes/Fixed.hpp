/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 01:21:49 by bberkrou          #+#    #+#             */
/*   Updated: 2023/12/13 02:34:31 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include "Fixed.h"

class Fixed
{
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed &fixed);
		Fixed(const int);
		Fixed(const float);

		Fixed &operator=(const Fixed &fixed);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat();
		int toInt();

	private:
		int _fixed_point_value;
		static const int _fractional_bits = 8;
};

#endif // FIXED_HPP
