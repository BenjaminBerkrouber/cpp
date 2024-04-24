/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 04:23:25 by bberkrou          #+#    #+#             */
/*   Updated: 2023/12/13 09:19:46 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

// ------ Constructors  ------ //

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string Name)
{
	std::cout << "ClapTrap Parameter constructor called" << std::endl;
	_Name = Name;
	_Hitpoints = 10;
	_Energy_points = 10;
	_Attack_damage = 0;
	std::cout << "Now you are a ClapTrap a new chalenger" << std::endl;
	std::cout << GREEN << "          " << _Name << RESET << std::endl;
	print_steve();
	std::cout << RED << "❤️ : "  << _Hitpoints << ORANGE << " | ⚡: " << _Energy_points << PURPLE  << " | ⚔️ : " << _Attack_damage << RESET << std::endl << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = src;
}

// ------ Destructor ------ //

ClapTrap::~ClapTrap()
{
	std::cout << RED << "ClapTrap Destructor called" << RESET << std::endl;
}

// ------ Operators ------ //

ClapTrap	&ClapTrap::operator= (const ClapTrap &obj)
{
	std::cout << "ClapTrap Assignation operator called" << std::endl;
	if (this != &obj)
	{
		_Name = obj._Name;
		_Hitpoints = obj._Hitpoints;
		_Energy_points = obj._Energy_points;
		_Attack_damage = obj._Attack_damage;
	}
	return (*this);
}

// ------ Member functions ------ //

void	ClapTrap::attack(std::string const &target)
{
	if (_Hitpoints == 0)
	{
		std::cout << RED << _Name << " didn't attack because he's dead\n" << RESET << std::endl;
		return ;
	}
	if (_Energy_points > 0)
	{
		if (_Energy_points > 0)
			_Energy_points--;
		else
			_Energy_points = 0;
		std::cout << "ClapTrap " << _Name << " attack " << target << ", causing " << _Attack_damage << " points of damage!" << std::endl;
	}
	else
		std::cout << RED << _Name << " can't be attack because he's doesn't have energy\n" << RESET << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_Hitpoints == 0)
	{
		std::cout << RED << _Name << " didn't take any damage because he's already dead\n" << RESET << std::endl;
		return ;
	}
	if (amount > this->_Hitpoints)
		this->_Hitpoints = 0;
	else
		this->_Hitpoints -= amount;
	std::cout << "ClapTrap " << _Name << " take " << amount << " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_Hitpoints == 0)
	{
		std::cout << RED << _Name << " can't be repaired because he's already dead\n" << RESET << std::endl;
		return ;
	}
	if (_Energy_points > 0)
	{
		_Hitpoints += amount;
		if (_Energy_points > 0)
			_Energy_points--;
		else
			_Energy_points = 0;
		std::cout << "ClapTrap " << _Name << " be repaired " << amount << " points of damage!" << std::endl;
	}
	else
		std::cout << RED << _Name << " can't be repaired because he's doesn't have energy\n" << RESET << std::endl;
}

// ------ Getters ------ //

std::string		ClapTrap::getName(void) {
	return (this->_Name);
}

unsigned int	ClapTrap::getHitPoints(void) {
	return (this->_Hitpoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) {
	return (this->_Energy_points);
}

unsigned int	ClapTrap::getAttackDamage(void) {
	return (this->_Attack_damage);
}

// ------ Setters ------ //

void	ClapTrap::setName(std::string Name) {
	std::cout << "ClapTrap " << _Name << " change name to " << Name << std::endl;
	_Name = Name;
}

void	ClapTrap::setHitPoints(unsigned int Hitpoints) {
	std::cout << "ClapTrap " << _Name << " change Hitpoints to " << Hitpoints << std::endl;
	_Hitpoints = Hitpoints;
}

void	ClapTrap::setEnergyPoints(unsigned int Energy_points) {
	std::cout << "ClapTrap " << _Name << " change Energy_points to " << Energy_points << std::endl;
	_Energy_points = Energy_points;
}

void	ClapTrap::setAttackDamage(unsigned int Attack_damage) {
	std::cout << "ClapTrap " << _Name << " change Attack_damage to " << Attack_damage << std::endl;
	_Attack_damage = Attack_damage;
}
