/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 05:13:36 by bberkrou          #+#    #+#             */
/*   Updated: 2024/06/03 20:50:48 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"


int main(void)
{
	std::cout << BLUE << "═════════════════════════╗    Testing [INT]    ╔═══════════════════════════" << RESET << std::endl << std::endl;
    Array<int> int_array(10);

	for (size_t i = 0; i < int_array.size(); i++)
		int_array[i] = i;
	int_array.print();

	std::cout << BLUE << "═════════════════════════╗    Testing [Char]    ╔═══════════════════════════" << RESET << std::endl << std::endl;
	Array<char> char_array(10);

	for (size_t i = 0; i < char_array.size(); i++)
		char_array[i] = i + 65;
	char_array.print();

	std::cout << BLUE << "═════════════════════════╗    Testing [String]    ╔═══════════════════════════" << RESET << std::endl << std::endl;

	Array<std::string> string_array(5);

	string_array[0] = "Hello";
	string_array[1] = "World";
	string_array[2] = "!";
	string_array[3] = "How";
	string_array[4] = "are you?";
	string_array.print();

	std::cout << BLUE << "═════════════════════════╗    Testing [Constructor]    ╔═══════════════════════════" << RESET << std::endl << std::endl;

	std::cout << std::endl << "-------- Testing copy constructor --------" << std::endl << std::endl;
	Array<int> int_array_copy(int_array);
	int_array_copy.print();
	int_array[0] = 42;
	int_array_copy.print();
	
	std::cout << std::endl << "-------- Testing assignation operator --------" << std::endl << std::endl;
	Array<int> int_array_assignation(5);
	int_array_assignation = int_array;
	int_array_assignation.print();

	std::cout << BLUE << "═════════════════════════╗    Testing [Out of range]    ╔═══════════════════════════" << RESET << std::endl << std::endl;

	try {
		std::cout << int_array[10] << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	try {
		std::cout << int_array[-1] << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::cout << std::endl << std::endl;

    return 0;
}
