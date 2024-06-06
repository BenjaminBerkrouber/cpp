/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:11:44 by ben               #+#    #+#             */
/*   Updated: 2024/06/03 22:45:12 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// ============== Constructors ==============

Span::Span(unsigned int n) : _n(n) {
    std::cout << "Span constructor called" << std::endl;
}

Span::Span(Span const &other) {
    std::cout << "Span copy constructor called" << std::endl;
    *this = other;
}

Span &Span::operator=(Span const &other) {
    std::cout << "Span assignation operator called" << std::endl;
    if (this != &other) {
        _n = other._n;
        _vec = other._vec;
    }
    return *this;
}

// ============== Destructor ==============

Span::~Span() {
    std::cout << "Span destructor called" << std::endl;
}

// ============== Member functions ==============

void Span::addNumber(int n) {
    if (_vec.size() >= _n)
        throw std::runtime_error("Span is full");
    _vec.push_back(n);
}

int Span::shortestSpan() const {
    std::vector<int> tmp = _vec;
    int shortest;

    if (_vec.size() <= 1)
        throw std::runtime_error("Span is empty or contains only one element");
    std::sort(tmp.begin(), tmp.end());
    shortest = tmp[1] - tmp[0];
    for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end() - 1; it++) {
        if (*(it + 1) - *it < shortest)
            shortest = *(it + 1) - *it;
    }
    return shortest;
}

int Span::longestSpan() const {
    if (_vec.size() <= 1)
        throw std::runtime_error("Span is empty or contains only one element");
    std::vector<int> tmp = _vec;
    std::sort(tmp.begin(), tmp.end());
    return tmp[tmp.size() - 1] - tmp[0];
}

void Span::printVec() const {
    std::cout << "  Vector content => [";
    for (std::vector<int>::const_iterator it = _vec.begin(); it != _vec.end(); it++)
        std::cout << *it << " ";
    std::cout << "]" << std::endl;
}

void Span::printState() const {
    std::cout << "----------- Span state -----------" << std::endl;

    printVec();
    std::cout << "  Size =>           [" << _n << "]" << std::endl;
    try {
        std::cout << "  Shortest span =>  [" << shortestSpan() << "]" << std::endl;
        std::cout << "  Longest span =>   [" << longestSpan() << "]" << std::endl;
    } catch (std::exception &e) {
        std::cerr << RED << e.what() << RESET << "]" << std::endl;
    }
    std::cout << "----------------------------------" << std::endl;
    std::cout << std::endl;
}

void Span::fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (_vec.size() + std::distance(begin, end) > _n)
        throw std::runtime_error("Span is full");
    std::cout << "Filling span with range [" << *begin << " - " << *(end - 1) << "]" << std::endl;
    _vec.insert(_vec.end(), begin, end);
}

// ============== Getters ==============

std::vector<int> Span::getVec() const {
    return _vec;
}