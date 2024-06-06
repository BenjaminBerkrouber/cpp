/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 03:02:06 by bberkrou          #+#    #+#             */
/*   Updated: 2024/06/05 18:41:24 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

# define PURPLE "\033[35m"
# define RED    "\033[31m"
# define GREEN  "\033[32m"
# define BLUE   "\033[34m"
# define BLACK  "\033[30m"
# define ORANGE "\033[33m"
# define RESET  "\033[0m"
# define GRAY "\033[37m"

# include <unistd.h>
# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <limits>
# include <sstream>
# include <cstdlib>
# include <cctype>
# include <string>

template <typename T>
T max(T x, T y) {
	return ((x > y) ? x : y);
}

template <typename T>
T min(T x, T y) {
	return ((x < y) ? x : y);
}

template <typename T>
void swap(T &x, T &y) {
	T tmp;

	tmp = x;
	x = y;
	y = tmp;
}

template <typename T>
void	apply_operator(T x, T y) {

	std::cout << "Testing for x: [" << x << "] y: [" << y << "]" << std::endl;
	std::cout << "	max is : [" << max(x, y) << "]"<< std::endl;
	std::cout << "	min is : [" << min(x, y) << "]"<< std::endl;
	swap(x, y);
	std::cout << "	swap is : x = [" << x << "] y = [" << y << "]" << std::endl << std::endl;
}

#endif