/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 08:37:15 by bberkrou          #+#    #+#             */
/*   Updated: 2024/02/28 08:43:38 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal
{
	private:
		std::string	type;

	public:
		Cat();
		~Cat();
		Cat(Cat & ref);
		Cat & operator=(Cat const & rhs);
		void makeSound() const;
		std::string getType( void ) const;
};

#endif
