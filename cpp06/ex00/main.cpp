/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 05:13:36 by bberkrou          #+#    #+#             */
/*   Updated: 2024/06/06 13:18:56 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void	processConvert(std::string input)
{
	std::cout << "Input: [" << input << "]" << std::endl;
	try {
		ScalarConverter::convert(input);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

int main(void)
{
	std::cout << std::endl << BLUE << "═════════════════════════╗    Testing CHAR    ╔═══════════════════════════" << RESET << std::endl << std::endl;

	processConvert("A");
	processConvert("1");
	processConvert("'");

	std::cout << BLUE << "═════════════════════════╗    Testing INT    ╔═══════════════════════════" << RESET << std::endl << std::endl;

	processConvert("42");
	processConvert("2147483647");
	processConvert("2147483648");
	processConvert("-2147483648");
	processConvert("-2147483649");

	std::cout << BLUE << "═════════════════════════╗    Testing FLOAT    ╔═══════════════════════════" << RESET << std::endl << std::endl;

	processConvert("42.0f");
	processConvert("nanf");
	processConvert("+inff");
	processConvert("-inff");

	std::cout << BLUE << "═════════════════════════╗    Testing DOUBLE    ╔═══════════════════════════" << RESET << std::endl << std::endl;

	processConvert("42.0");
	processConvert("nan");
	processConvert("+inf");
	processConvert("-inf");


	std::cout << BLUE << "═════════════════════════╗    Testing Error    ╔═══════════════════════════" << RESET << std::endl << std::endl;

	processConvert("42.0.0");
	processConvert("nanfz");
	processConvert("+inffz");
	processConvert("-inffz");
	processConvert("");


	return (0);
}