/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:39:41 by acamargo          #+#    #+#             */
/*   Updated: 2026/04/23 20:22:10 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "whatever.hpp"
#include <iostream>

template<> std::string& min<std::string &>(std::string & a, std::string & b)
{
	int	a_count = 0;
	int	b_count = 0;
	size_t	i = 0;
	while (i < a.length())
		a_count += a.at(i++);
	i = 0;
	while (i < b.length())
		b_count += b.at(i++);
	if (a_count < b_count)
		return a;
	return b;
}

template <typename T> T	min(T a, T b)
{
	if (a < b)
		return a;
	return b;
}

template<> std::string& max<std::string &>(std::string & a, std::string & b)
{
	int	a_count = 0;
	int	b_count = 0;
	size_t	i = 0;
	while (i < a.length())
		a_count += a.at(i++);
	i = 0;
	while (i < b.length())
		b_count += b.at(i++);
	if (a_count > b_count)
		return a;
	return b;
}

template <typename T> T	max(T a, T b)
{
	if (a > b)
		return a;
	return b;
}

int	main(void)
{
	int	a = 1, b = 2;
	std::string s1 = "name1", s2 = "name2";
	::swap(a, b);
	std::cout << a << '\n' << b << '\n';
	std::cout << ::min(s1, s2) << '\n';
	std::cout << ::min(a, b) << '\n';
	std::cout << ::min(s2, s2) << '\n';
	std::cout << ::min(b, a) << '\n';
}
