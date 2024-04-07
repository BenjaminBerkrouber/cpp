/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:37:55 by bberkrou          #+#    #+#             */
/*   Updated: 2023/12/09 09:37:57 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.h"
# include "Zombie.hpp"

Zombie *new_zombie(std::string name)
{
	Zombie *zombie;
	
	zombie = new Zombie;
	zombie->set_zombie(name);
	return (zombie);
}