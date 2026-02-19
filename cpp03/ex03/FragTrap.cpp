/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:16:49 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/19 18:07:51 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"
#include "ClapTrap.hpp"

# include <iostream>

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap default constructor called\n";
	return ;
}

FragTrap::FragTrap(std::string const & name)
{
	std::cout << "FragTrap constructor with parameters called\n";
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	return ;
}

FragTrap::FragTrap(FragTrap const & other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called\n";
	*this = other;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called\n";
	return ;
}

FragTrap&	FragTrap::operator=(FragTrap const & other)
{
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return (*this);
}

void	FragTrap::attack(std::string const & target)
{
	if (!is_able_to_interact())
		return ;
	std::cout << "FragTrap " + this->getName() + " attacks " + target + ", causing ";
	std::cout << this->getAttackDamage() << " points of damage!\n";
}

void	FragTrap::highFivesGuys(void)
{
	if (!is_able_to_interact())
		return ;
	std::cout << "FragTrap " + this->getName() + " is requesting a high five!\n";
	return ;
}
