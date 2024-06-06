/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 05:13:36 by bberkrou          #+#    #+#             */
/*   Updated: 2024/06/05 18:48:11 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	int tab_int[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	char tab_char[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

	std::cout << BLUE << "═════════════════════════╗    Testing [INT]    ╔═══════════════════════════" << RESET << std::endl << std::endl;
	apply_operator(tab_int, 8);

	std::cout << BLUE << "═════════════════════════╗    Testing [char]    ╔═══════════════════════════" << RESET << std::endl << std::endl;
	apply_operator(tab_char, 8);

	return (0);
}