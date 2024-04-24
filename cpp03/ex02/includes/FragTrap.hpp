/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:05:43 by bberkrou          #+#    #+#             */
/*   Updated: 2023/12/13 11:49:18 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.h"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		~FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const &src);

		FragTrap &	operator=(FragTrap const &rhs);

		void		highFivesGuys(void);
};


#endif