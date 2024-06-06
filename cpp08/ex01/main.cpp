/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 05:13:36 by bberkrou          #+#    #+#             */
/*   Updated: 2024/06/06 13:45:24 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

static void initContainer(Span &span, int nbr) {
    try {
        span.addNumber(nbr);
    } catch (std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
}

int main(void) {
    Span sp = Span(5);
    std::cout << BLUE << "═════════════════════════╗    Testing [vector]    ╔═══════════════════════════" << RESET << std::endl << std::endl;

    initContainer(sp, -8);
    initContainer(sp, 574);
    initContainer(sp, -68);
    initContainer(sp, -9);
    initContainer(sp, 0);
    initContainer(sp, 80);
    
    sp.printState();

    std::cout << BLUE << "═════════════════════════╗    Testing [empty vector]    ╔═══════════════════════════" << RESET << std::endl << std::endl;

    Span sp0 = Span(5);

    sp0.printState();

    std::cout << BLUE << "═════════════════════════╗    Testing [fill Span]    ╔═══════════════════════════" << RESET << std::endl << std::endl;

    Span sp1 = Span(10000);
    std::vector<int> vec(500, 42);
    std::vector<int> vec2(500, 21);
    std::vector<int> vec3(9000, 84);

    try {
        sp1.fillSpan(vec.begin(), vec.end());
        sp1.fillSpan(vec2.begin(), vec2.end());
        sp1.fillSpan(vec3.begin(), vec3.end());
        sp1.fillSpan(vec.begin(), vec.end());
    } catch (std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    // sp1.printState();

    std::cout << BLUE << "═════════════════════════╗    Testing [constructor]    ╔═══════════════════════════" << RESET << std::endl << std::endl;

    Span sp2 = Span(sp);
    sp2.printState();

    return 0;
}
