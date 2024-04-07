/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:39:53 by bberkrou          #+#    #+#             */
/*   Updated: 2023/12/09 10:12:47 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.h"
# include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *hord = new Zombie[N];

	for (int i = 0; i < N ; i++)
		hord[i].set_zombie(name);
	return (hord);
}