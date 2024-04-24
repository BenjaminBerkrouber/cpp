/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:06:52 by bberkrou          #+#    #+#             */
/*   Updated: 2024/04/08 15:24:38 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		HumanB jim("Jim");
		HumanB tim("Tim");
		
		bob.attack();

		club.setType("some other type of club");
		bob.attack();

		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();

		tim.attack();
		
	return 0;
}