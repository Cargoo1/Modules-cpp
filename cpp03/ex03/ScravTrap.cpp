/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScravTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:45:49 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/19 19:42:56 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScravTrap.hpp"
#include "ClapTrap.hpp"

# include <iostream>

ScravTrap::ScravTrap(void) : ClapTrap()
{
	std::cout << "ScravTrap default constructor called\n";
	return ;
}

ScravTrap::ScravTrap(std::string const & name)
{
	std::cout << "ScravTrap constructor w paramaters called\n";
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	return ;
}

ScravTrap::ScravTrap(ScravTrap const & other) : ClapTrap(other)
{
	*this = other;
	return ;
}

ScravTrap::~ScravTrap(void)
{
	std::cout << "ScravTrap destructor called\n";
	return ;
}

ScravTrap&	ScravTrap::operator=(ScravTrap const & other)
{
	this->_name = other._name;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	this->_hitPoints = other._hitPoints;
	return (*this);
}

void	ScravTrap::attack(std::string const & target)
{
	unsigned int	energyPoints = 0;

	if (!is_able_to_interact())
		return;
	energyPoints = this->getEnergyPoints() - 1;
	this->setEnergyPoints(energyPoints);
	std::cout << "ScravTrap " << this->getName() << " attacks " + target;
	std::cout << ", causing " << this->getAttackDamage() << " points of damage!\n";
	return ;
}

void	ScravTrap::guardGate(void)
{
	if (!is_able_to_interact())
		return ;
	std::cout << "ScravTrap " + this->_name + " is now in Gate keeper mode\n";
	return ;
}
