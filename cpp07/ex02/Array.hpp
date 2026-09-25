/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 16:01:12 by acamargo          #+#    #+#             */
/*   Updated: 2026/09/23 17:26:13 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T> class Array
{
public:
	Array(void);
	Array(unsigned int n);
	Array(Array const& other);
	~Array();

	Array&	operator=(Array const& other);
	T&		operator[](unsigned int n);

	unsigned int	size(void);
private:
	T*				_elements;
	unsigned int	_size;
};

#include <cstddef>
#include <exception>

template<class T> Array<T>::Array()
{
	this->_elements = NULL;
	this->_size = 0;
}

template<class T> Array<T>::Array(unsigned int n) : _size(n)
{
	this->_elements = new T[n];
}

template<class T> Array<T>::~Array()
{
	if (this->_elements)
		delete [] this->_elements;
}

template<class T> Array<T>::Array(Array const& other)
{
	this->_size = other._size;
	if (!other._elements)
	{
		this->_elements = NULL;
		return;
	}
	this->_elements = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; ++i)
		this->_elements[i] = other._elements[i];
}

template<class T> Array<T>& Array<T>::operator=(Array const& other)
{
	if (this == &other)
		return *this;
	this->~Array();
	new (this) Array(other);
	return *this;
}

template<class T> T& Array<T>::operator[](unsigned int n)
{
	if (n >= this->_size)
		throw std::exception();
	return this->_elements[n];
}

template<class T> unsigned int	Array<T>::size(void)
{
	return this->_size;
}
