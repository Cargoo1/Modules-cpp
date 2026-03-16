/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Garbage.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 23:29:34 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/16 13:39:12 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
# include "Garbage.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Garbage::Garbage(void) : _capacity(INVENTORY_SIZE), _lenght(0), _elements(new AMateria*[INVENTORY_SIZE])
{
	for (size_t i = 0; i < this->_capacity; i++)
		this->_elements[i] = NULL;
	return ;
}

Garbage::Garbage(size_t size) : _capacity(size), _lenght(0), _elements(new AMateria*[size])
{
	for (size_t i = 0; i < this->_capacity; i++)
		this->_elements[i] = NULL;
	return ;
}

Garbage::Garbage(Garbage const & other) : _capacity(other._capacity), _lenght(other._lenght), _elements(NULL)
{
	this->_elements = new AMateria*[this->_capacity];
	for (size_t i = 0; i < this->_capacity; i++)
		this->_elements[i] = NULL;
	for (size_t i = 0; i < this->_lenght; i++)
	{
		if (other._elements[i])
			this->_elements[i] = other._elements[i]->clone();
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
	for (size_t i = 0; i < this->_lenght; i++)
	{
		std::cout << "i: " << i << "\n";
		std::cout << "capacity: " << _capacity << "\n";
		std::cout << "_lenght: " << _lenght << "\n";
		if (this->_elements[i])
			delete this->_elements[i];
		this->_elements[i] = NULL;
	}
	if (this->_elements)
		delete [] this->_elements;
	this->_lenght = 0;
	this->_capacity = 0;
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

	if (this->_lenght != this->_capacity)
	{
		std::cout << "Adding elements to Garbage\n";
		this->_elements[this->_lenght] = m;
		this->_lenght++;
		return ;
	}
	std::cout << "Reallocating Garbage\n";
	temp_trash = this->_elements;
	this->_capacity = this->_capacity + INVENTORY_SIZE;
	this->_elements = new AMateria*[this->_capacity];
	for (size_t i = 0; i < this->_lenght; i++)
	{
		this->_elements[i] = NULL;
		if (temp_trash[i])
			this->_elements[i] = temp_trash[i];
	}
	delete []temp_trash;
	this->_elements[this->_lenght] = m;
	this->_lenght++;
	return ;
}
