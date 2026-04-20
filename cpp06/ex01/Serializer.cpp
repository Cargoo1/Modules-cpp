/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:03:08 by acamargo          #+#    #+#             */
/*   Updated: 2026/04/20 15:21:06 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
Serializer::Serializer(void)
{
	return;
}

Serializer::Serializer(const Serializer& other)
{
	(void)other;
	return;
}

Serializer::~Serializer(void)
{
	return;
}

Serializer&	Serializer::operator=(const Serializer& other)
{
	if (this == &other)
		return *this;
	return *this;
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	uintptr_t	uptr;
	void	*vptr;

	vptr = static_cast<void*>(ptr);
	uptr = reinterpret_cast<uintptr_t>(vptr);
	return uptr;
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	Data*	dptr = reinterpret_cast<Data*>(raw);
	return dptr;
}
