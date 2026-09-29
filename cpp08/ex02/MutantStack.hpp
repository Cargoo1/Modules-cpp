/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 15:06:59 by acamargo          #+#    #+#             */
/*   Updated: 2026/09/29 17:56:53 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <deque>
#include <iostream>
#include <iterator>
#include <stack>
#include <vector>

template<class Type, class Sequence = std::deque<Type> >
class	MutantStack : public std::stack<Type, Sequence>
{
public:
	MutantStack(void);
	MutantStack(const MutantStack& other);
	~MutantStack(void);

	MutantStack&	operator=(const MutantStack& other);
	
	typedef typename Sequence::iterator iterator;
	typedef typename Sequence::const_iterator const_iterator;
	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	iterator	begin(void);
	iterator	end(void);
	const_iterator	begin(void) const;
	const_iterator	end(void) const;
	reverse_iterator	rbegin(void);
	reverse_iterator	rend(void);
	const_reverse_iterator	rbegin(void) const;
	const_reverse_iterator	rend(void) const;
};

template<class Type, class Sequence> MutantStack<Type, Sequence>::MutantStack() : std::stack<Type, Sequence>()
{
	return;
}

template<class Type, class Sequence> MutantStack<Type, Sequence>::MutantStack(const MutantStack& other) : std::stack<Type, Sequence>(other)
{
	return ;
}

template<class Type, class Sequence> MutantStack<Type, Sequence>::~MutantStack(void)
{
	return;
}

template<class Type, class Sequence> MutantStack<Type, Sequence>&	MutantStack<Type, Sequence>::operator=(const MutantStack& other)
{
	if (this == &other)
		return *this;
	this->~MutantStack();
	new (this) MutantStack(other);
	return *this;
}

template<class Type, class Sequence> typename MutantStack<Type, Sequence>::iterator	MutantStack<Type, Sequence>::begin()
{
	return this->c.begin();
}


template<class Type, class Sequence> typename MutantStack<Type, Sequence>::iterator	MutantStack<Type, Sequence>::end()
{
	return this->c.end();
}

template<class Type, class Sequence> typename MutantStack<Type, Sequence>::const_iterator	MutantStack<Type, Sequence>::begin() const
{
	return this->c.begin();
}

template<class Type, class Sequence> typename MutantStack<Type, Sequence>::const_iterator	MutantStack<Type, Sequence>::end() const
{
	return this->c.end();
}

template<class Type, class Sequence> typename MutantStack<Type, Sequence>::reverse_iterator	MutantStack<Type, Sequence>::rbegin()
{
	return this->c.rbegin();
}


template<class Type, class Sequence> typename MutantStack<Type, Sequence>::reverse_iterator	MutantStack<Type, Sequence>::rend()
{
	return this->c.rend();
}

template<class Type, class Sequence> typename MutantStack<Type, Sequence>::const_reverse_iterator	MutantStack<Type, Sequence>::rbegin() const
{
	return this->c.rbegin();
}

template<class Type, class Sequence> typename MutantStack<Type, Sequence>::const_reverse_iterator	MutantStack<Type, Sequence>::rend() const
{
	return this->c.rend();
}
