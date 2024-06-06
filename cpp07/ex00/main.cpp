/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 05:13:36 by bberkrou          #+#    #+#             */
/*   Updated: 2024/06/03 18:37:59 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"


int main(void)
{
	std::cout << BLUE << "═════════════════════════╗    Testing INT    ╔═══════════════════════════" << RESET << std::endl << std::endl;
	apply_operator(1, -1);
	apply_operator(2147483647, (int)-2147483648);
	apply_operator(0, 0);

	std::cout << BLUE << "═════════════════════════╗    Testing Char   ╔═══════════════════════════" << RESET << std::endl << std::endl;
	apply_operator('a', 'b');
	apply_operator('b', 'a');
	apply_operator('a', 'a');

	std::cout << BLUE << "═════════════════════════╗    Testing string   ╔═══════════════════════════" << RESET << std::endl << std::endl;
	apply_operator("AAA", "aaa");
	apply_operator("Bonjour je suis bberkrou", "Bonjour je suis bberkroU");
	apply_operator("a", "");
	apply_operator("", "");
	apply_operator("Bonjour", "Bonjour");
	
	std::cout << BLUE << "═════════════════════════╗    Testing bool   ╔═══════════════════════════" << RESET << std::endl << std::endl;
	apply_operator(true, false);
	apply_operator(true, true);

	return (0);
}