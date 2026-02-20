/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:39:19 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/20 16:51:30 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"

# include <iostream>

Animal::Animal(void) : _type("???")
{
	std::cout << "Animal constructor called\n";
	return ;
}

Animal::Animal(Animal const & other)
{
	std::cout << "Animal copy constructor called\n";
	*this = other;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called\n";
	return ;
}

Animal&	Animal::operator=(Animal const & other)
{
	this->_type = other._type;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "???\n";
	return ;
}

std::string const&	Animal::getType(void) const
{
	return (this->_type);
}
