/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:39:34 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/12 20:40:17 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "WrongAnimal.hpp"

# include <iostream>

WrongAnimal::WrongAnimal(void) : _type("???")
{
	std::cout << "WrongAnimal constructor called\n";
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const & other)
{
	std::cout << "WrongAnimal copy constructor called\n";
	*this = other;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called\n";
	return ;
}

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const & other)
{
	this->_type = other._type;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "???\n";
	return ;
}

std::string const&	WrongAnimal::getType(void) const
{
	return (this->_type);
}
