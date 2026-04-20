/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 14:41:46 by acamargo          #+#    #+#             */
/*   Updated: 2026/04/20 15:17:29 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP

#define SERIALIZER_HPP

#include <stdint.h>

struct	Data
{
	int	x;
	char c;
};

class	Serializer
{
private:
	Serializer(void);
	Serializer(const Serializer& other);
	~Serializer(void);

	Serializer&	operator=(const Serializer& other);
public:
	static uintptr_t	serialize(Data* ptr);
	static Data*	deserialize(uintptr_t raw);
};

#endif
