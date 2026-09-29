/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 20:48:19 by acamargo          #+#    #+#             */
/*   Updated: 2026/09/29 19:15:48 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <exception>
#include <limits>
#include <new>
#include <vector>

Span::Span(unsigned int N)
{
	if (N == 0)
		return;
	this->_container.reserve(N);
}

Span::Span(Span const& other)
{
	this->_container.reserve(other._container.capacity());
	this->_container = other._container;
}

Span::~Span(void)
{

}

Span&	Span::operator=(Span const& other)
{
	if (this == &other)
		return (*this);
	this->~Span();
	new (this) Span(other);
	return *this;
}

void	Span::addNumber(int n)
{
	if (this->_container.size() == this->_container.capacity())
		throw std::exception();
	this->_container.push_back(n);
}

std::vector<int>&	Span::getContainer(void)
{
	return this->_container;
}

int	Span::shortestSpan()
{
	if (this->_container.size() <= 1)
		throw std::exception();
	int	diff = INT_MAX;
	int	temp_diff;
	std::sort(this->_container.begin(), this->_container.end());

	for (size_t i = 0; i < this->_container.size() - 1; ++i)
	{
		temp_diff = this->_container.at(i + 1) -  this->_container.at(i);
		if (temp_diff < diff)
			diff = temp_diff;
	}
	return diff;
}

int	Span::longestSpan()
{
	if (this->_container.size() <= 1)
		throw std::exception();
	int	min = *std::min_element(this->_container.begin(), this->_container.end());
	int	max = *std::max_element(this->_container.begin(), this->_container.end());
	return max - min;
}
