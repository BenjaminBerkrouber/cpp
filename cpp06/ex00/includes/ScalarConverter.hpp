/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:36:34 by ben               #+#    #+#             */
/*   Updated: 2024/06/06 13:36:35 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <limits>
# include <cmath>
# include <cstdlib>

# include "utils.h"

class ScalarConverter
{
    public:
        static void convert(const std::string &input);

    private:
        ScalarConverter(void);
        ScalarConverter(ScalarConverter const &src);
        ScalarConverter &operator=(ScalarConverter const &rhs);
        ~ScalarConverter(void);

        static void displayChar(char c);
        static void displayInt(int n);
        static void displayFloat(float f);
        static void displayDouble(double d);
};

#endif
