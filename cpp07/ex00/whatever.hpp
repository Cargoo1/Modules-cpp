/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:39:56 by acamargo          #+#    #+#             */
/*   Updated: 2026/09/23 17:46:19 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP

#define WHATEVER_HPP

# include <string>

template<typename T> void	swap(T& a, T& b)
{
	T	temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename T> T	min(T a, T b)
{
	if (a < b)
		return a;
	return b;
}

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

template <typename T> T	max(T a, T b)
{
	if (a > b)
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

#endif
