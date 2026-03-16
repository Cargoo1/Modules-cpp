/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:40:45 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/12 20:41:42 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongCat.hpp"

# include <iostream>

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat constructor called\n";
	this->_type = "WrongCat";
	return ;
}

WrongCat::WrongCat(WrongCat const & other)
{
	std::cout << "WrongCat copy constructor called\n";
	*this = other;
	return ;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called\n";
	return ;
}

WrongCat&	WrongCat::operator=(WrongCat const & other)
{
	this->_type = other._type;
	return (*this);
}

std::string const&	WrongCat::getType(void) const
{
	return (this->_type);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow\n";
}

