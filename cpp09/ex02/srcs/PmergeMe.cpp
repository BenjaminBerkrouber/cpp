/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 03:58:11 by ben               #+#    #+#             */
/*   Updated: 2024/06/04 23:04:35 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// ================== CONSTRUCTORS ================== //

PmergeMe::PmergeMe() {
    
}

PmergeMe::PmergeMe(const PmergeMe &other) {
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        // CODE HERE
    }
    return *this;
}


// ================== DESTRUCTOR ================== //

PmergeMe::~PmergeMe() {
}


// ================== METHODS ================== //
