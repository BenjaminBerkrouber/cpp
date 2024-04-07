/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 03:00:40 by bberkrou          #+#    #+#             */
/*   Updated: 2023/12/13 09:11:54 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# define PURPLE "\033[35m"
# define RED    "\033[31m"
# define GREEN  "\033[32m"
# define BLUE   "\033[34m"
# define BLACK  "\033[30m"
# define ORANGE "\033[33m"
# define RESET  "\033[0m"
# define GRAY "\033[37m"

# include <unistd.h>
# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <limits>
# include <sstream>
# include <cstdlib>
# include <cctype>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void	print_steve();

#endif