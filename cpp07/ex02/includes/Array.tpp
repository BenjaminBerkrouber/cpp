/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:41:37 by ben               #+#    #+#             */
/*   Updated: 2024/06/06 13:41:46 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

// ------------- Constructors ------------- //

template <typename T>
Array<T>::Array() {
    _tab = NULL;
    _size = 0;
    std::cout << "Default Constructors called" << std::endl;
}

template <typename T>
Array<T>::Array(size_t size) {
    _size = size;
    _tab = new T[size];
    std::cout << "Constructors Parameters called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array &src) {
    _tab = NULL;
	*this = src;
    std::cout << "Copy Constructor called" << std::endl;
}

// ------------- Destructor ------------- //

template <typename T>
Array<T>::~Array() {
    delete[] _tab;
    std::cout << "Destructor called" << std::endl;
}

// ------------- Operator ------------- //

template <typename T>
Array<T>& Array<T>::operator=(const Array<T> &obj) {
    std::cout << "Assignation Operator called" << std::endl;
    if (this == &obj)
        return (*this);
    delete[] _tab;
    _size = obj.size();
    _tab = new T[_size];
    for (size_t i = 0; i < _size; i++)
        _tab[i] = obj._tab[i];
    return (*this);
}

template <typename T>
T& Array<T>::operator[](const size_t index) {
    if (index >= _size)
        throw (std::out_of_range("Index out of range"));
    return (_tab[index]);
}

// ------------- Methods ------------- //

template <typename T>
void    Array<T>::print() const {
    std::cout << "	Size: [" << size() << "]" << std::endl;
    std::cout << "	Content: [";
    for (size_t i = 0; i < _size; i++)
        std::cout << _tab[i] << " ";
    std::cout << "]" << std::endl << std::endl;
}

// ------------- Getter ------------- //

template <typename T>
size_t  Array<T>::size() const {
    return (_size);
}

#endif
