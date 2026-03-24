/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:38:27 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/24 15:51:39 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
# include <iostream>

int	main(void)
{
	{
		ShrubberyCreationForm	test("lol");
		Bureaucrat				b("pablo", 1);
		try
		{
			test.execute(b);
		}
		catch(std::exception& e)
		{
			std::cout << e.what();
		}
	}
	return 0;

}
