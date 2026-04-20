/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 14:40:57 by acamargo          #+#    #+#             */
/*   Updated: 2026/04/20 15:21:39 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <stdint.h>
#include <iostream>
int	main(void)
{
	Data	*ptr = new Data;
	ptr->c = 'x';
	uintptr_t	uptr;
	uptr = Serializer::serialize(ptr);
	Data	*temp = Serializer::deserialize(uptr);
	if (temp == ptr)
		std::cout << "Pointers are equal\n";
}
