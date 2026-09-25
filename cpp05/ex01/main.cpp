/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:38:27 by acamargo          #+#    #+#             */
/*   Updated: 2026/09/15 19:21:08 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
# include <iostream>

int	main(void)
{
	{
		Bureaucrat	test("pepe", 2);
		Form		form_1("paper", 1, 2);
		try
		{
			Form some_form("test", 1, 123123);
		}
		catch(std::exception& e)
		{
			std::cout << e.what();
			std::cout << form_1.getGrade2Sign() << '\n';
		}
		std::cout << form_1;
		test.signForm(form_1);
		std::cout << form_1;
		test.incrementGrade();
		test.signForm(form_1);
	}
	return 0;

}
