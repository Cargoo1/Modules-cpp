/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:45:28 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/19 22:03:55 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

# include <iostream>

Cat::Cat(void)
{
	std::cout << "Cat constructor called\n";
	this->_type = "Cat";
	return ;
}

Cat::Cat(Cat const & other)
{
	std::cout << "Cat copy constructor called\n";
	*this = other;
	return ;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called\n";
	return ;
}

Cat&	Cat::operator=(Cat const & other)
{
	this->_type = other._type;
	return (*this);
}

std::string const&	Cat::getType(void) const
{
	return (this->_type);
}

void	Cat::makeSound(void)
{
	std::cout << "Meow\n";
}
