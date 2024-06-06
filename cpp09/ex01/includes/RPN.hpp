/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 01:43:40 by ben               #+#    #+#             */
/*   Updated: 2024/06/04 23:03:42 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

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

class RPN
{
    public:
        // Constructors
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);

        // Destructor
        ~RPN();

        // Methods
        void    calculateRPN(std::string input);
    private :
        std::stack<double> _stack;
        double    applyOperator(char c, double nbr1, double nbr2) const;
        void      applyOperatorToStack(char c);
        void      pushToStack(char c);
        double    add(double nbr1, double nbr2) const;
        double    subtract(double nbr1, double nbr2) const;
        double    multiply(double nbr1, double nbr2) const;
        double    divised(double nbr1, double nbr2) const;
        bool      isOperator(char c) const;
        std::string      printStack() const;
};

#endif