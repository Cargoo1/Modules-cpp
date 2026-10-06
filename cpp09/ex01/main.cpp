/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 17:39:52 by acamargo          #+#    #+#             */
/*   Updated: 2026/10/06 17:42:48 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <exception>
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./RPN \"[EXPR]\"\n";
		return 1;
	}
	std::string	expr(argv[1]);
	try
	{
		int result = RPN::calculate_expression(expr);
		std::cout << result << '\n';
	}catch (std::exception& e)
	{
		std::cout << e.what() << '\n';
		return 1;
	}
	return 0;
}
