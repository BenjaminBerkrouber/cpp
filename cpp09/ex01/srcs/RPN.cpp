/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 03:58:11 by ben               #+#    #+#             */
/*   Updated: 2024/06/04 23:00:49 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// ================== CONSTRUCTORS ================== //

RPN::RPN() {
    
}

RPN::RPN(const RPN &other) {
    *this = other;
}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other) {
        this->_stack = other._stack;
    }
    return *this;
}


// ================== DESTRUCTOR ================== //

RPN::~RPN() {
}

// ================== CALCUL METHODS ================== //

double RPN::add(double nbr1, double nbr2) const {
    return (nbr1 + nbr2);
}

double RPN::subtract(double nbr1, double nbr2) const {
    return (nbr1 - nbr2);
}

double RPN::multiply(double nbr1, double nbr2) const {
    return (nbr1 * nbr2);
}

double RPN::divised(double nbr1, double nbr2) const {
    if (nbr2 == 0)
        throw std::invalid_argument("[Error] => Division by zero");
    return (nbr1 / nbr2);
}

// ================== UTILS METHODS ================== //

bool RPN::isOperator(char c) const {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

double RPN::applyOperator(char c, double nbr2, double nbr1) const {
    #ifdef DEBUG
        std::cout << std::endl << "Calculat [" << c << "] on [" << nbr1 << "] and [" << nbr2 << "]" << std::endl;
    #endif
    if (c == '+')
        return add(nbr1, nbr2);
    if (c == '-')
        return subtract(nbr1, nbr2);
    if (c == '*')
        return multiply(nbr1, nbr2);
    if (c == '/')
        return divised(nbr1, nbr2);
    throw std::invalid_argument("[Error] => Invalid operator.");
}

std::string RPN::printStack() const {
    std::stack<double>  tmp = _stack;
    std::ostringstream  oss;

    while (!tmp.empty()) {
        oss << tmp.top() << " ";
        tmp.pop();
    }
    return oss.str();
}

void RPN::applyOperatorToStack(char op) {
    double nbr1;
    double nbr2;

    if (_stack.size() < 2) {
        throw std::invalid_argument("[Error] => Too many numbers in the stack. Not enough operators.");
    }
    nbr1 = _stack.top();
    _stack.pop();
    nbr2 = _stack.top();
    _stack.pop();
    _stack.push(applyOperator(op, nbr1, nbr2));
}

void    RPN::pushToStack(char c) {
    double     nbr;
    
    nbr = c - '0';
    _stack.push(nbr);
    #ifdef DEBUG
        std::cout << std::endl << "Push(" << nbr << ") stack stats => [" << printStack() << "]" << std::endl;
    #endif
}

// ================== METHODS ================== //

void    RPN::calculateRPN(std::string input) {
    char    c;

    std::cout << "Results of [" << input << "]";
	
    for (size_t i = 0; i < input.size(); i++) {
        c = input[i];
        if (c == ' ') continue;
        if (isdigit(c)) {
            pushToStack(c);
            continue ;
        } else if (isOperator(c))
            applyOperatorToStack(c);
        else
            throw std::invalid_argument("[Error] => Found Invalid character.");
    }
    if (_stack.size() != 1)
        throw std::runtime_error("[Error] => Not enough numbers in the stack for the operators.");
    std::cout << " = [" << GREEN << _stack.top() << RESET << "]" <<  std::endl;
}

