/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 21:35:10 by acamargo          #+#    #+#             */
/*   Updated: 2026/09/29 19:23:02 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <vector>

#define N 1000000

int	main()
{
	{
		Span	test(2);
		int	arr[2] = {1};
		try
		{
			test.shortestSpan();
		}catch (...)
		{
			std::cout << "couldnt find shortestSpan\n";
		}
		test.addNumber(arr, arr + 1);
		try
		{
			std::cout << test.shortestSpan() << '\n';
		}catch (...)
		{
			std::cout << "couldnt find shortestSpan\n";
		}
		test.addNumber(-1);
		std::cout << test.shortestSpan() << std::endl;
		std::cout << test.longestSpan() << std::endl;
	}
	{
		Span	test(N);
		std::srand(std::time(NULL));
		int	arr[N];
		std::generate(arr, arr + N, std::rand);
		test.addNumber(arr, arr + N);
		/*
		for (size_t i = 0; i < test.getContainer().size(); ++i)
			std::cout << "span[i] = " << test.getContainer().at(i) << '\n';
			*/
		std::cout << test.shortestSpan() << std::endl;
		std::cout << test.longestSpan() << std::endl;
	}
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
}
