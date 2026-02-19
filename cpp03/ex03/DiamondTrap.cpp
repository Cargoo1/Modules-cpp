/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:07:10 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/19 18:24:58 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScravTrap.hpp"

# include <iostream>

DiamondTrap::DiamondTrap(void) : FragTrap(), ScravTrap()
{
	std::cout << "DiamondTrap defautl constructor called\n";
	return ;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called\n";
	return ;
}

DiamondTrap::DiamondTrap(std::string const & name) : FragTrap(name), ScravTrap(name)
{
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScravTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

void	DiamondTrap::attack(std::string const & target)
{
	ScravTrap::attack(target);
	return ;
}

void	DiamondTrap::whoAmi(void)
{
	std::cout << "I am " + this->_name + " and my claptrap name is: ";
	std::cout << this->ClapTrap::_name + "\n";
	return ;
}
