/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:38:27 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/24 14:31:09 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
# include <iostream>

int	main(void)
{
	{
		Bureaucrat	test("pepe", 1);
		Form		some_form;
		try
		{
			some_form = Form("paper", 1, 2);
		}
		catch(std::exception& e)
		{
			std::cout << e.what();
			std::cout << some_form.getGrade2Sign() << '\n';
		}
		std::cout << some_form;
		test.signForm(some_form);
		std::cout << some_form;
	}
	return 0;

}
