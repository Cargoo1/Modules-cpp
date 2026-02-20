/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:45:28 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/20 18:17:04 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"
#include "Brain.hpp"

# include <iostream>

Dog::Dog(void)
{
	std::cout << "Dog constructor called\n";
	this->_myBrain = new Brain();
	this->_type = "Dog";
	return ;
}

Dog::Dog(Dog const & other)
{
	std::cout << "Dog copy constructor called\n";
	*this = other;
	return ;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called\n";
	delete this->_myBrain;
	return ;
}

Dog&	Dog::operator=(Dog const & other)
{
	this->_type = other._type;
	this->_myBrain = other._myBrain;
	return (*this);
}

std::string const&	Dog::getType(void) const
{
	return (this->_type);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof\n";
}

bool	Dog::setBrain(std::string const & idea, int idx)
{
	if (!this->_myBrain->setIdeas(idea, idx))
		return (false);
	return (true);
}

Brain*	Dog::getBrain(void) const
{
	return (this->_myBrain);
}
