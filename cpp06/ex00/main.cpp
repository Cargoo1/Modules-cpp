/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:43:33 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/30 19:06:38 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Invalid args number, should only take one\n";
		return 1;
	}
	std::string str = argv[1];
	ScalarConverter::convert(str);
	return 0;
}
