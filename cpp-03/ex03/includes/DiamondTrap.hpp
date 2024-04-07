/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:46:17 by bberkrou          #+#    #+#             */
/*   Updated: 2023/12/13 14:25:26 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.h"

class DiamondTrap : virtual public ScavTrap, virtual public FragTrap
{
	private:
		std::string	_Name;
		int			_Hitpoints;
		int			_Energy_points;
		int			_Attack_damage;

	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const &src);
		~DiamondTrap(void);

		DiamondTrap &	operator=(DiamondTrap const &rhs);

		void		attack(std::string const & target);
		void		whoAmI(void);
};

#endif