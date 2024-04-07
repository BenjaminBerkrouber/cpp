/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 03:02:06 by bberkrou          #+#    #+#             */
/*   Updated: 2023/12/13 05:54:47 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

class ClapTrap {

	private :
		std::string		_Name;
		unsigned int	_Hitpoints;
		unsigned int	_Energy_points;
		unsigned int	_Attack_damage;

	public :
		ClapTrap();
		ClapTrap(std::string Name);
		ClapTrap(const ClapTrap &src);
		~ClapTrap();

		ClapTrap	&operator= (const ClapTrap &obj);

		void	attack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		unsigned int	getAttackDamage(void);
		std::string		getName(void);
		unsigned int	getHitPoints(void);
		unsigned int	getEnergyPoints(void);
		void			setName(std::string Name);
		void			setHitPoints(unsigned int Hitpoints);
		void			setEnergyPoints(unsigned int Energy_points);
		void			setAttackDamage(unsigned int Attack_damage);

};