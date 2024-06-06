/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 01:37:53 by ben               #+#    #+#             */
/*   Updated: 2024/06/05 01:42:53 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// ========== Constructors ==========

Serializer::Serializer(void) {
    
}

Serializer::Serializer(Serializer const &src) {
    *this = src;
}

Serializer &Serializer::operator=(Serializer const &rhs) {
    if (this != &rhs) {
        // utils
    }
    return *this;
}

// ========== Destructor ==========

Serializer::~Serializer(void) {
    
}

// ========== Methods ==========

uintptr_t Serializer::serialize(Data *ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}
