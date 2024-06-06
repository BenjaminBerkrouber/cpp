/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 01:43:40 by ben               #+#    #+#             */
/*   Updated: 2024/06/04 23:03:55 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PREMGERME_HPP
#define PREMGERME_HPP

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
# include <cctype>
# include <string>
# include <list>
# include <queue>
# include <stack>
# include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include <climits>

class PmergeMe
{
    public:
        // Constructors
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);

        // Destructor
        ~PmergeMe();

        // Methods
        
    private :

};

#endif