/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:13:39 by bberkrou          #+#    #+#             */
/*   Updated: 2023/12/09 13:24:27 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.h"
# include "Weapon.hpp"

class HumanA {

	public :
        HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void		attack( void );
		void		setWeapon(Weapon arms);
		void		setName(std::string name);
		std::string	getName();
		Weapon		getWeapon();
		
	private :
		std::string _name;
		Weapon&		_weapon;
};


#endif