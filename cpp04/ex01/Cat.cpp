/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:45:28 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/24 12:11:57 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

#include <cstdlib>
# include <iostream>
#include <new>

Cat::Cat(void)
{
	std::cout << "Cat constructor called\n";
	this->_myBrain = new Brain();
	this->_type = "Cat";
	return ;
}

Cat::Cat(Cat const & other) : Animal(other)
{
	std::cout << "Cat copy constructor called\n";
	this->_type = other._type;
	this->_myBrain = new Brain(*other._myBrain);
	return ;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called\n";
	delete this->_myBrain;
	return ;
}

Cat&	Cat::operator=(Cat const & other)
{
	if (this == &other)
		return (*this);
	this->~Cat();
	new(this) Cat(other);
	return (*this);
}

std::string const&	Cat::getType(void) const
{
	return (this->_type);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow\n";
}

bool	Cat::setBrain(std::string const & idea, int idx)
{
	if (!this->_myBrain->setIdeas(idea, idx))
		return (false);
	return (true);
}

Brain*	Cat::getBrain(void) const
{
	return (this->_myBrain);
}
