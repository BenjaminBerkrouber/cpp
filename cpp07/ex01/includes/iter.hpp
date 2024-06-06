/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 03:02:06 by bberkrou          #+#    #+#             */
/*   Updated: 2024/06/05 18:48:08 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

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
void	iter(T *addrs, unsigned int size, void (*f)(T&)) {
	for (unsigned int i = 0; i < size; i++) {
		f(*addrs);
		addrs++;
	}
}

template <typename T>
void	inc(T &element) {
	element++;
}

template <typename T>
void	dec(T &element) {
	element--;
}

template <typename T>
void	print(T &element) {
	std::cout << element << " ";
}

template <typename T>
void	print_operator(T *addrs, unsigned int size, void (*f)(T&)) {
	std::cout << "  stats = [";
	iter(addrs, size, f);
	std::cout << "]" << std::endl;
}

template <typename T>
void	apply_operator(T *addrs, unsigned int size) {
	std::cout << "Elements is " << std::endl;
	print_operator(addrs, size, print);
	
	std::cout << std::endl << "Testing incrementation" << std::endl;
	iter(addrs, size, inc);
	print_operator(addrs, size, print);

	std::cout << std::endl << "Testing decrementation" << std::endl;
	iter(addrs, size, dec);
	print_operator(addrs, size, print);
	std::cout << std::endl;
}

#endif