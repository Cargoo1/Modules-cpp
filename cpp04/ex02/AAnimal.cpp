/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:39:19 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/20 18:52:07 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"

# include <iostream>

AAnimal::AAnimal(void) : _type("???")
{
	std::cout << "Animal constructor called\n";
	return ;
}

AAnimal::AAnimal(AAnimal const & other)
{
	std::cout << "Animal copy constructor called\n";
	*this = other;
}

AAnimal::~AAnimal(void)
{
	std::cout << "Animal destructor called\n";
	return ;
}

AAnimal&	AAnimal::operator=(AAnimal const & other)
{
	this->_type = other._type;
	return (*this);
}
