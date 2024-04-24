/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 08:21:33 by bberkrou          #+#    #+#             */
/*   Updated: 2023/12/09 08:36:25 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# define PURPLE "\033[35m"
# define RED    "\033[31m"
# define GREEN  "\033[32m"
# define BLUE   "\033[34m"
# define RESET  "\033[0m"

# include <unistd.h>
# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <limits>
# include <sstream>
# include <cstdlib>

# include "Zombie.hpp"

Zombie *new_zombie(std::string name);
void	randomChump(std::string name);

#endif