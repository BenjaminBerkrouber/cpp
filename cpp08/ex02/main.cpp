/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 05:13:36 by bberkrou          #+#    #+#             */
/*   Updated: 2024/06/06 13:48:04 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    MutantStack<int> stack_int;
    MutantStack<char> stack_char;
    MutantStack<float> stack_float;
    MutantStack<std::string> stack_string;

    std::cout << std::endl << BLUE << "═════════════════════════╗    Testing [INT]    ╔═══════════════════════════" << RESET << std::endl << std::endl;

    stack_int.push(42);
    stack_int.push(21);
    stack_int.push(84);
    stack_int.push(42);
    stack_int.push(21);
    stack_int.push(84);
    stack_int.print_stack();

    std::cout << BLUE << "═════════════════════════╗    Testing [CHAR]    ╔═══════════════════════════" << RESET << std::endl << std::endl;

    stack_char.push('a');
    stack_char.push('b');
    stack_char.push('c');
    stack_char.push('d');
    stack_char.push('e');
    stack_char.push('f');
    stack_char.print_stack();

    std::cout << BLUE << "═════════════════════════╗    Testing [FLOAT]    ╔═══════════════════════════" << RESET << std::endl << std::endl;

    stack_float.push(42.42);
    stack_float.push(21.21);
    stack_float.push(84.84);
    stack_float.push(42.42);
    stack_float.push(21.21);
    stack_float.push(84.84);
    stack_float.print_stack();

    std::cout << BLUE << "═════════════════════════╗    Testing [STRING]    ╔═══════════════════════════" << RESET << std::endl << std::endl;

    stack_string.push("Hello");
    stack_string.push("World");
    stack_string.push("42");
    stack_string.push("21");

    stack_string.print_stack();

    return 0;  
}
