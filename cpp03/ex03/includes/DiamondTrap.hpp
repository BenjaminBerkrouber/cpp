/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:46:17 by bberkrou          #+#    #+#             */
/*   Updated: 2024/04/18 18:17:01 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.h"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_Name;

	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const &src);
		~DiamondTrap(void);

		DiamondTrap &	operator=(DiamondTrap const &rhs);

		using		ScavTrap::attack;
		void		whoAmI(void);
};

#endif