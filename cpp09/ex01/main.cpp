/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 05:13:36 by bberkrou          #+#    #+#             */
/*   Updated: 2024/06/04 22:47:12 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    std::string math_expression;

    if (argc < 2)
    {
        std::cout << RED << "Usage: ./RPN [math expression]" << std::endl;
        return 1;
    }

    for (int i = 1; i < argc; i++)
    {
        math_expression += argv[i];
        if (i + 1 < argc)
            math_expression += " ";
    }

    RPN rpn;
    try {
        rpn.calculateRPN(math_expression);
    } catch (std::exception &e) {
        std::cout << std::endl << std::endl << RED << "An error was found " << std::endl << " " << e.what() << std::endl;
    }
    return 0;
}
