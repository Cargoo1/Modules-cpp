/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:38:27 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/24 12:25:43 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>
# include <iostream>

int	main(void)
{
	try
	{
		Bureaucrat test("pablo", 0);
		std::cout << test;
	}
	catch(std::exception& e)
	{
		std::cout << e.what();
	}
	Bureaucrat test("pepe", 2);
	try
	{
		test.incrementGrade();
		test.decrementGrade();
		test.incrementGrade();
		test.incrementGrade();
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what();
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what();
	}
	return 0;

}
