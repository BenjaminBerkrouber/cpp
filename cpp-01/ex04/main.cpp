/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:56:12 by bberkrou          #+#    #+#             */
/*   Updated: 2024/03/01 21:56:45 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "Sed.hpp"

int main(int argc, char **argv)
{
	if (argc != 4) {
		std::cout << "Program need 3 args" << std::endl;
		return (0);
	}
	
	Sed sed = Sed(argv[1], argv[2], argv[3]);
	
	sed.readFile();
	return (0);
}