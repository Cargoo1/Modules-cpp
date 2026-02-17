/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:49:07 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/17 14:18:27 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

#include <climits>
# include <iostream>
#include <limits>

ClapTrap::ClapTrap(void) : _name("Jhon doe"),
						_hitPoints(10),
						_energyPoints(10),
						_attackDamage(0)
{
	std::cout << "Default constructor called\n";
	return ;
}

ClapTrap::ClapTrap(std::string const & name) : _name(name),
											_hitPoints(10),
											_energyPoints(10),
											_attackDamage(0)
{
	std::cout << "Constructor with parameters called\n";
	return ;
}

ClapTrap::ClapTrap(ClapTrap const & other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called\n";
	return ;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & other)
{
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return (*this);
}

std::string const & ClapTrap::getName(void) const
{
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

bool	ClapTrap::setName(std::string const & name)
{
	if (name.empty())
		return (false);
	this->_name = name;
	return (true);
}

bool	ClapTrap::setHitPoints(unsigned int amount)
{
	this->_hitPoints = amount;
	return (true);
}

bool	ClapTrap::setEnergyPoints(unsigned int amount)
{
	this->_energyPoints = amount;
	return (true);
}

bool	ClapTrap::setAttackDamage(unsigned int amount)
{
	this->_attackDamage = amount;
	return (false);
}

bool	ClapTrap::is_able_to_interact(void)
{
	if (this->getHitPoints() == 0)
	{
		std::cout << this->getName() + " is dead\n";
		return (false);
	}
	if (this->getEnergyPoints() == 0)
	{
		std::cout << this->getName() + " has not enough energy points\n";
		return (false);
	}
	return (true);
}

void	ClapTrap::attack(std::string const & target)
{
	unsigned int	energyPoints = 0;

	if (!is_able_to_interact())
		return;
	energyPoints = this->getEnergyPoints() - 1;
	this->setEnergyPoints(energyPoints);
	std::cout << "ClapTrap " << this->getName() << " attacks " + target;
	std::cout << ", causing " << this->getAttackDamage() << " points of damage!\n";
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int	hit_points;
	if (this->getHitPoints() == 0)
		return ;
	hit_points = this->getHitPoints() - amount;
	this->setHitPoints(hit_points);
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!is_able_to_interact())
		return ;
	if (this->getHitPoints() == std::numeric_limits<unsigned int>::max())
		return ;
	this->setHitPoints(amount + this->getHitPoints());
	return ;
}
