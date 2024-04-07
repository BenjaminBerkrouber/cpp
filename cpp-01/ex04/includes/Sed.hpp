/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:46:20 by bberkrou          #+#    #+#             */
/*   Updated: 2023/12/09 21:03:55 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_H
# define SED_H

#include "utils.h"

class Sed
{
	private:
		std::string _filename;
		std::string _s1;
		std::string _s2;
		std::string _line;

	public:
		Sed(std::string filename, std::string s1, std::string s2);
		~Sed();
		void replace();
		std::string getLine();
		void	readFile();
};

#endif