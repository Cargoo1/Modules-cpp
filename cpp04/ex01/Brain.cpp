/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:05:34 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/12 21:04:19 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"
#include <iostream>

Brain::Brain(void)
{
	std::cout << "Brain default constructor called\n";
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "Some idea...";
	return ;
}

Brain::Brain(Brain const & other)
{
	std::cout << "Brain copy constructor called\n";
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = other._ideas[i];
	}
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called\n";
	return ;
}

Brain&	Brain::operator=(Brain const & other)
{
	if (this == &other)
		return (*this);
	this->~Brain();
	new (this) Brain(other);
	return (*this);
}

std::string	const *Brain::getIdeas(void) const
{
	return (this->_ideas);
}

bool	Brain::setIdeas(std::string const & idea, int idx)
{
	if (idx > 100 || idx < 0)
		return (false);
	this->_ideas[idx] = idea;
	return (true);
}
