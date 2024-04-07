/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 08:15:30 by bberkrou          #+#    #+#             */
/*   Updated: 2024/02/28 08:37:55 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Animal.h"
#include "Cat.hpp"
#include "Dog.hpp"

class Animal {

    protected:
        std::string _type;

    public:
        Animal();
        virtual ~Animal();
        Animal(const Animal &src);
        Animal &operator=(const Animal &rhs);

        virtual void makeSound() const;
        std::string getType() const;
        void setType(const std::string &type);
};

#endif
