/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Garbage.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 23:29:34 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/21 21:15:41 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Garbage.hpp"
#include "ICharacter.hpp"

Garbage::Garbage(void) : _size(0), _index(0), _trashcan(NULL)
{
	return ;
}

Garbage::Garbage(size_t size) : _size(size), _index(0), _trashcan(new AMateria*[size])
{
	for (size_t i = 0; i < this->_size; i++)
		this->_trashcan[i] = NULL;
	return ;
}

Garbage::Garbage(Garbage const & other) : _size(0), _index(0), _trashcan(NULL)
{
	this->_index = other._index;
	this->_size = other._size;
	this->_trashcan = new AMateria*[other._size];
	for (size_t i = 0; i < other._size; i++)
		this->_trashcan[i] = NULL;
	if (!other._index)
		return ;
	for (size_t i = 0; i <= other._index; i++)
	{
		if (other._trashcan[i])
			this->_trashcan[i] = other._trashcan[i]->clone();
	}
	return ;
}

Garbage::~Garbage(void)
{
	this->flush();
	return ;
}

void	Garbage::flush(void)
{
	for (size_t i = 0; i <= this->_index; i++)
	{
		if (this->_trashcan[i])
			delete this->_trashcan[i];
		this->_trashcan[i] = NULL;
	}
	if (this->_trashcan)
		delete [] this->_trashcan;
	this->_index = 0;
	this->_size = 0;
}

Garbage&	Garbage::operator=(Garbage const & other)
{
	if (this == &other)
		return (*this);
	this->~Garbage();
	new (this) Garbage(other);
	return (*this);
}

void	Garbage::add(AMateria *m)
{
	AMateria	**temp_trash;

	if (this->_index != this->_size)
	{
		this->_trashcan[this->_index++] = m;
		return ;
	}
	if (!this->_trashcan)
	{
		this->_size = INVENTORY_SIZE;
		this->_trashcan = new AMateria*[this->_size];
		this->_trashcan[this->_index++] = m;
		return ;
	}
	temp_trash = this->_trashcan;
	this->_size = this->_size + INVENTORY_SIZE;
	this->_trashcan = new AMateria*[this->_size];
	for (size_t i = 0; i < this->_index; i++)
		this->_trashcan[i] = temp_trash[i];
	delete [] temp_trash;
	this->_trashcan[this->_index++] = m;
	return ;
}
