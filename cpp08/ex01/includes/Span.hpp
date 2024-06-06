/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 03:02:06 by bberkrou          #+#    #+#             */
/*   Updated: 2024/06/05 18:57:15 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

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
# include <string>
# include <list>
# include <queue>
# include <stack>
# include <vector>
#include <algorithm>
#include <map>
class Span
{

public:
    // Constructors
    Span(unsigned int n);
    Span(Span const &other);

    // Operator
    Span &operator=(Span const &other);

    // Destructor
    ~Span();

    // Member functions
    void    addNumber(int n);
    int     shortestSpan() const;
    int     longestSpan() const;
    void    printVec() const;
    void    printState() const;
    void    fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    
    // Getters
    std::vector<int>    getVec() const;
    private:
        unsigned int _n;
        std::vector<int> _vec;
};


#endif