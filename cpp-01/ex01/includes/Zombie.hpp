/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 08:22:03 by bberkrou          #+#    #+#             */
/*   Updated: 2023/12/09 08:22:41 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include "Zombie.h"

class Zombie {

	private:
		std::string _name;

	public:
		Zombie();
		~Zombie();
		void		announce( void );
		void		set_zombie(std::string name);
		std::string	get_name( void );
};

#endif