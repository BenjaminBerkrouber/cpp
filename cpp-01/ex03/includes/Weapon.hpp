/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:47:52 by bberkrou          #+#    #+#             */
/*   Updated: 2024/03/01 21:48:06 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEPON_HPP
# define WEPON_HPP

#include "Weapon.h"

class Weapon {

	public :
		Weapon();
		Weapon(std::string type);
		~Weapon();
		const std::string&	getType();
		void			setType(std::string type);

	private :
		std::string _type;
};

#endif
