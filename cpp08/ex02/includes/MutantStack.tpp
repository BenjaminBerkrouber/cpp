/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 00:54:40 by ben               #+#    #+#             */
/*   Updated: 2024/06/05 18:58:00 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

// ============== Constructors ==============

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {
    std::cout << "MutantStack constructor called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &other) : std::stack<T>(other) {
    std::cout << "MutantStack copy constructor called" << std::endl;
    *this = other;
}

// ============== Operator ==============

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &other) {
    std::cout << "MutantStack assignation operator called" << std::endl;
    if (this != &other)
        std::stack<T>::operator=(other);
    return *this;
}

// ============== Destructor ==============

template <typename T>
MutantStack<T>::~MutantStack() {
    std::cout << "MutantStack destructor called" << std::endl;
}

// ============== Member functions ==============

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (std::stack<T>::c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return (std::stack<T>::c.end());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return (std::stack<T>::c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return (std::stack<T>::c.rend());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
	return (std::stack<T>::c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
	return (std::stack<T>::c.rend());
}

template <typename T>
void MutantStack<T>::print_stack()
{
    std::cout << "Stack in order =>         [ ";
    for (iterator it = begin(); it != end(); it++)
        std::cout << *it << " ";
    std::cout << "]" << std::endl;

    std::cout << "Stack in reverse order => [ ";
    for (reverse_iterator it = rbegin(); it != rend(); it++)
        std::cout << *it << " ";
    std::cout << "]" << std::endl;

    std::cout << std::endl;
}

#endif