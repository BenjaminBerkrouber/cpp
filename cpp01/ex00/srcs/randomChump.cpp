/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:38:02 by bberkrou          #+#    #+#             */
/*   Updated: 2023/12/09 09:38:04 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.h"
# include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie zombie;

	zombie.set_zombie(name);
	zombie.announce();
}