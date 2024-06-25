/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 01:43:40 by ben               #+#    #+#             */
/*   Updated: 2024/06/25 20:47:21 by bberkrou         ###   ########.fr       */
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
#include <utility>

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
		void	sort(const std::string &str);

    private :
        std::string _str;
		int		_nb;
        std::vector<std::pair<int, int> > _pairs;
		std::vector<int> _sorted_number;
		int		_size_min_vector;

        bool	parsInput(const std::string &str);
		bool	containsOnlyDigits(const std::string &str);
        
        void	makePair();
		void	printPairs();
		
		void	findMaxOfPairs();
		void	printNumbers();
		
		void	sortMaxOfPairs();
		void	recursiveSort(std::vector<int> &arr, int left, int right);
		int		partition(std::vector<int> &arr, int left, int right);
		
		void	findMinOfPairs();

		void	insertMin();
		void	generateJacobsthalSeq(std::vector<size_t> &seq, size_t size);
		void	insertInSortedOrder(int value);
};

#endif