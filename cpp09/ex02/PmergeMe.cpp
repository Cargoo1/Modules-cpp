/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 18:10:01 by acamargo          #+#    #+#             */
/*   Updated: 2026/10/09 19:43:09 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) : _number_of_comparations(0)
{

}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	this->_list = other._list;
	this->_vector = other._vector;
}

PmergeMe::~PmergeMe(void)
{

}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other)
{
	if (this == &other)
		return *this;
	this->~PmergeMe();
	new (this) PmergeMe(other);
	return *this;
}

bool	pair::operator<(const pair& other) const
{
	return this->a < other.a;
}

bool	pair::operator>(const pair& other) const
{
	return this->a > other.a;
}

std::size_t		PmergeMe::getNofComparations(void)
{
	return this->_number_of_comparations;
}
