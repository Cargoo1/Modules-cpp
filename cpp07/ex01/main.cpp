/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 20:41:28 by acamargo          #+#    #+#             */
/*   Updated: 2026/04/23 22:06:26 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "iter.hpp"

#include <cstddef>
#include <iostream>

template <typename T, typename RV> void	iter(T* a, const size_t lenght, RV (*fn)(T& param))
{
	size_t i = 0;
	while (i < lenght)
		fn(a[i++]);
}

void	increment(const char &a)
{
	(void)a;
}

int	main(void)
{
	int	array[2] = {1, 2};
	(void)array;
	char	array2[2] = {'a', 'b'};
	const	std::string c = "aaa";
	const int	lenght = 10;
	::iter<const char, void>(array2, lenght, increment);
	std::cout << array2[0] << '\n' << array2[1] << '\n';
	
	return 0;
}
