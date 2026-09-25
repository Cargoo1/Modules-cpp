/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 20:48:29 by acamargo          #+#    #+#             */
/*   Updated: 2026/09/25 22:14:46 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
class	Span
{
public:
	Span(unsigned int N);
	Span(Span const& other);
	~Span(void);

	Span&	operator=(Span const& other);

	void	addNumber(int n);
	template <class InputIterator>
	void	addNumber(InputIterator first, InputIterator last);
	std::vector<int>&	getContainer(void);
	int		shortestSpan();
	int		longestSpan();
private:
	std::vector<int>	_container;
	unsigned int		_size;
	unsigned int		_capacity;
};

template <class InputIterator> void	Span::addNumber(InputIterator first, InputIterator last)
{
	for (; first != last;)
	{
		this->addNumber(*first);
		++first;
	}

}
