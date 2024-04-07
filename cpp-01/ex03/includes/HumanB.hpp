/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:30:47 by bberkrou          #+#    #+#             */
/*   Updated: 2023/12/09 13:25:41 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.h"
# include "Weapon.hpp"

class HumanB {

	public :
		HumanB(std::string name);
		~HumanB();
		void		attack( void );
		void 		setWeapon(Weapon& weapon);
		void		setName(std::string name);
		std::string	getName();
		Weapon*		getWeapon();
		
	private :
		std::string _name;
		Weapon*		_weapon;
};

#endif