/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandrocamargo <acamargo@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 14:42:31 by alejandrocama     #+#    #+#             */
/*   Updated: 2026/10/06 18:19:41 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <string>
class	RPN
{
public:
	static int	calculate_expression(const std::string& expr);
	static int		add(int a, int b);
	static int		substraction(int a, int b);
	static int		multiplication(int a, int b);
	static int		division(int a, int b);
private:
	RPN(void);
	RPN(const RPN& other);
	~RPN(void);

	RPN&	operator=(const RPN& other);

};
