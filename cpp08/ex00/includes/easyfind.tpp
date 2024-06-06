/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:43:31 by ben               #+#    #+#             */
/*   Updated: 2024/06/06 13:43:41 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
#define EASYFIND_TPP

template <typename T>
typename T::iterator easyfind(T &container, int target) {
    typename T::iterator it = std::find(container.begin(), container.end(), target);
    if (it == container.end()) {
        throw std::runtime_error("Element not found");
    }
    return it;
}

template <typename T>
void    printContainer(T &container) {
    std::cout << "Container: [";
    for (typename T::iterator it = container.begin(); it != container.end(); it++)
        std::cout << *it << " ";
    std::cout << "]" << std::endl << std::endl;
}

template <typename T>
void    initContainer(T &container, int size) {
    for (int i = 0; i < size; i++)
        container.push_back(i);
}

template <typename T>
void    processSearch(T &container, int target) {
    try {
        std::cout << " [" << target << "] => ";
        typename T::iterator it = easyfind(container, target);
        std::cout << GREEN << "Element found:	" << *it << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
}

#endif



