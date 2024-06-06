/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 03:02:06 by bberkrou          #+#    #+#             */
/*   Updated: 2024/06/05 18:45:00 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

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
# include <list>
# include <queue>

template <typename T>
class Array {
	public :
		// Constructor
		Array();
		Array(size_t size);
		Array(const Array &src);

		// Destructor
		~Array();

		// Operator
		Array<T>& operator=(const Array<T> &obj);
		T& operator[](const size_t index);

		// Getter
		size_t size() const;
		void	print() const;
	private :
		T *_tab;
		size_t _size;
};

#include "Array.tpp"

#endif