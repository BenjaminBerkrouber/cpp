/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 05:13:36 by bberkrou          #+#    #+#             */
/*   Updated: 2024/06/03 21:40:52 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"


int main(void) {
    std::cout << BLUE << "═════════════════════════╗    Testing [vector]    ╔═══════════════════════════" << RESET << std::endl << std::endl;

    std::vector<int> vec;
    initContainer(vec, 10);
    printContainer(vec);

    processSearch(vec, 5);
    processSearch(vec, 15);
	processSearch(vec, 0);
	processSearch(vec, -9);
	std::cout << std::endl;

    std::cout << BLUE << "═════════════════════════╗    Testing [list]    ╔═══════════════════════════" << RESET << std::endl << std::endl;

    std::list<int> lst;
    initContainer(lst, 10);
    printContainer(lst);

    processSearch(lst, 5);
    processSearch(lst, 15);
	processSearch(vec, 0);
	processSearch(vec, -9);
	std::cout << std::endl;

    std::cout << BLUE << "═════════════════════════╗    Testing [deque]    ╔═══════════════════════════" << RESET << std::endl << std::endl;

    std::deque<int> deq;
    initContainer(deq, 10);
    printContainer(deq);

    processSearch(deq, 5);
    processSearch(deq, 15);
	processSearch(vec, 0);
	processSearch(vec, -9);
	std::cout << std::endl;
	
    return 0;
}
