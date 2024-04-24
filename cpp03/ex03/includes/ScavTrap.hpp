/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 03:02:06 by bberkrou          #+#    #+#             */
/*   Updated: 2023/12/13 14:06:49 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H
#include "ClapTrap.h"

class ScavTrap : virtual public ClapTrap {

	public :
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & src);
		~ScavTrap();
		ScavTrap & operator=(ScavTrap const & rhs);
		
		void attack(std::string const & target);
		void guardGate( void );
	private :
	
};

#endif