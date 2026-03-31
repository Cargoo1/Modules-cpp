/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:43:33 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/31 18:15:00 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Invalid args number, should only take one\n";
		return 1;
	}
	std::string str = argv[1];
	float a = std::numeric_limits<float>::min();
	std::cout << strtof("-11111111111111111111111111111111111111111111111111", NULL) << "\n";
	//ScalarConverter::convert(str);
	return 0;
}
