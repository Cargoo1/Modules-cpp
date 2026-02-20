/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:05:34 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/20 18:25:53 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"
#include <iostream>

Brain::Brain(void)
{
	std::cout << "Brain default constructor called\n";
	this->_ideas = new std::string[100];
	return ;
}

Brain::Brain(Brain const & other)
{
	std::cout << "Brain copy constructor called\n";
	this->_ideas = new std::string[100];
	*this = other;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called\n";
	delete [] this->_ideas;
	return ;
}

Brain&	Brain::operator=(Brain const & other)
{
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = other._ideas[i];
	}
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
