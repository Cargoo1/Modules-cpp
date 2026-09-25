/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 20:41:28 by acamargo          #+#    #+#             */
/*   Updated: 2026/09/23 17:44:24 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "iter.hpp"

#include <cstddef>
#include <iostream>

void	display(const int &a)
{
	std::cout << a << '\n';
}

void	increment(int& n)
{
	n++;
}

void	display(const char &a)
{
	std::cout << a << '\n';
}

void	increment(char& n)
{
	n++;
}

int	main(void)
{
	int	array[2] = {1, 2};
	char	array2[2] = {'a', 'b'};
	const int	lenght = 2;
	::iter<int, void (*)(int&)>(array, lenght, increment);
	::iter<int, void (*)(int&)>(array, 2, NULL);
	::iter<int, void (*)(const int&)>(array, 2, display);
	::iter<char, void(*)(char&)>(array2, lenght, increment);
	::iter<char, void(*)(const char&)>(array2, 2, display);
	
	return 0;
}
