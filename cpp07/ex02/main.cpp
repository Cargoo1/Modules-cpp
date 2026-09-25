/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 16:10:59 by acamargo          #+#    #+#             */
/*   Updated: 2026/09/23 17:42:43 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <exception>
#include <iostream>

int	main()
{
	{
		std::cout << "Empty array example\n";
		Array<int>	array;
		try
		{
			std::cout << "size = " << array.size() << '\n';
			std::cout << "array[0] = " << array[0] << '\n';
		}
		catch(std::exception& e)
		{
			std::cout << "Out of bounds\n";
		}
		array = Array<int>(3);
		std::cout << "size = " << array.size() << '\n';
		array[0] = 100;
		std::cout << "array[0] = " << array[0] << '\n';
	}
	{
		std::cout << "Simple example\n";
		Array<std::string> array(100);
		array[0] = "hello";
		array[1] = "world";
		std::cout << "size = " << array.size() << '\n';
		std::cout << "array[0] = " << array[0] << '\n';
		std::cout << "array[1] = " << array[1] << '\n';
	}
	{
		std::cout << "Copy operator and accesing the size value\n";
		Array<std::string>	array(2);
		array[0] = "yes";
		array[1] = "no";
		Array<std::string>	array1(3);
		array1[0] = "lol";
		array1[1] = "??";
		try
		{
			array1[3] = "test";
		}
		catch(...)
		{
			std::cout << "Out of bounds\n";
		}
		array = array1;
		std::cout << "size = " << array.size() << '\n';
		std::cout << "array[0] = " << array[0] << '\n';
		std::cout << "array[1] = " << array[1] << '\n';
	}
	{
		std::cout << "Accesing a negative position\n";
		Array<std::string>	array(2);
		array[0] = "yes";
		array[1] = "no";
		try
		{
			array[-1] = "test";
		}
		catch(...)
		{
			std::cout << "Out of bounds\n";
		}
		Array<std::string>	array1(array);
		std::cout << "size = " << array.size() << '\n';
		std::cout << "array1[0] = " << array[0] << '\n';
		std::cout << "array1[1] = " << array[1] << '\n';
	}
	{
		std::cout << "Copy operator with a empty array\n";
		Array<std::string>	array(2);
		array[0] = "yes";
		array[1] = "no";
		array = Array<std::string>();
		std::cout << "size = " << array.size() << '\n';
		try
		{
			std::cout << "array[0] = " << array[0] << '\n';
		}
		catch(...)
		{
			std::cout << "Out of bounds\n";
		}
	}
	{
		std::cout << "Copy constructor with an empty array\n";
		Array<std::string>	array;
		std::cout << "size = " << array.size() << '\n';
		Array<std::string>	array1(array);
		try
		{
			std::cout << "size = " << array1.size() << '\n';
			std::cout << "array1[0] = " << array1[0] << '\n';
		}
		catch(...)
		{
			std::cout << "Out of bounds\n";
		}
	}

}
