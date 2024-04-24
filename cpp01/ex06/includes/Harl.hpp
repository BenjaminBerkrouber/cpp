/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:08:38 by bberkrou          #+#    #+#             */
/*   Updated: 2023/12/09 17:47:04 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include "Harl.h"

class Harl {
	
	typedef struct s_level {
		std::string	_level;
		void	(Harl::*function)(void);
	}	t_level;

	public :
		Harl();
		~Harl();
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		void complain( std::string level );	
		
	private :
		t_level harl_action[4];
};

#endif