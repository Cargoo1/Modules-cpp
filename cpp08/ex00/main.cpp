/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 18:20:50 by acamargo          #+#    #+#             */
/*   Updated: 2026/09/29 19:02:50 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <vector>

int	main()
{
	{
		std::cout << "Vector example\n";
		std::vector<int> v;
		v.push_back(2);
		v.push_back(1);
		std::vector<int>::const_iterator it = easyfind(v, 1);
		std::cout << "Iterator value: " << *it << "\n";
		try
		{
			std::cout << *easyfind(v, 20) << '\n';
		}
		catch(...)
		{
			std::cout << "Int not found!\n";
		}
	}
	{
		std::cout << "List example\n";
		std::list<int> list;
		list.push_back(0);
		list.push_back(10);
		list.push_back(1);
		std::list<int>::const_iterator it = easyfind(list, 1);
		std::cout << "Iterator value: " << *it << "\n";
		try
		{
			std::cout << *easyfind(list, 1) << '\n';
		}
		catch(...)
		{
			std::cout << "Int not found!\n";
		}
	}
	{
		std::cout << "Deque example\n";
		std::deque<int> deque;
		deque.push_back(10);
		deque.push_back(1);
		deque.push_back(20);
		std::deque<int>::const_iterator it = easyfind(deque, 1);
		std::cout << "Iterator value: " << *it << "\n";
		try
		{
			std::cout << *easyfind(deque, 30) << '\n';
		}
		catch(...)
		{
			std::cout << "Int not found!\n";
		}
	}
}
