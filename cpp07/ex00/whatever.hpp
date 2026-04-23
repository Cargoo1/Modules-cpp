/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:39:56 by acamargo          #+#    #+#             */
/*   Updated: 2026/04/23 20:20:05 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP

#define WHATEVER_HPP

# include <string>

template<typename T> void	swap(T & a, T & b)
{
	T	temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename T> T	min(T a, T b);

template<> std::string& min<std::string &>(std::string & a, std::string & b);

template <typename T> T	max(T a, T b);

template<> std::string& max<std::string &>(std::string & a, std::string & b);
#endif
