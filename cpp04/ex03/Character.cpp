/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 21:09:44 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/21 00:35:48 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

#include <cstddef>
# include <iostream>

Character::Character(void) : _Name("???"), _trashcan(INVENTORY_SIZE)
{
	std::cout << "Character default constructor called\n";
	for (int i = 0; i < INVENTORY_SIZE; i++)
		this->_inventory[i] = NULL;
	return ;
}

Character::Character(std::string const &name) : _Name(name), _trashcan(INVENTORY_SIZE)
{
	std::cout << "Character parametrized constructor called\n";
	for (int i = 0; i < INVENTORY_SIZE; i++)
		this->_inventory[i] = NULL;
	return ;
}

Character::Character(Character const & other)
{
	std::cout << "Character copy constructor called\n";
	this->_Name = other._Name;
	for (int i = 0; i < INVENTORY_SIZE; i++)
		this->_inventory[i] = other._inventory[i]->clone();
	this->_trashcan = other._trashcan;
	return ;
}

Character::~Character(void)
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	return ;
}

Character&	Character::operator=(Character const & other)
{
	if (this == &other)
		return (*this);
	this->~Character();
	this->_Name = other._Name;
	for (int i = 0; i < INVENTORY_SIZE; i++)
		this->_inventory[i] = other._inventory[i]->clone();
	this->_trashcan = other._trashcan;
	return (*this);
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= INVENTORY_SIZE || idx < 0)
		return ;
	if (!this->_inventory[idx])
		return ;
	this->_inventory[idx]->use(target);
	return ;
}

void	Character::equip(AMateria *m)
{
	int	i = 0;
	while (this->_inventory[i] && i < INVENTORY_SIZE)
		i++;
	if (i >= INVENTORY_SIZE)
		return ;
	this->_inventory[i] = m;
	return ;
}

void	Character::unequip(int idx)
{
	if (idx >= INVENTORY_SIZE || idx < 0)
		return ;
	if (!this->_inventory[idx])
		return ;
	this->_trashcan.add(this->_inventory[idx]);
	this->_inventory[idx] = NULL;
	return ;
}
