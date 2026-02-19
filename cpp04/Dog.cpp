/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:45:28 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/19 22:04:08 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"

# include <iostream>

Dog::Dog(void)
{
	std::cout << "Dog constructor called\n";
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
	return ;
}

Dog&	Dog::operator=(Dog const & other)
{
	this->_type = other._type;
	return (*this);
}

std::string const&	Dog::getType(void) const
{
	return (this->_type);
}

void	Dog::makeSound(void)
{
	std::cout << "Woof\n";
}
