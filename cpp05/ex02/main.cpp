/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:38:27 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/25 16:40:55 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
# include <iostream>

int	main(void)
{
	{
		ShrubberyCreationForm	test("lol");
		RobotomyRequestForm		robotomy("pepe");
		Bureaucrat				b("pablo", 150);
		b.signForm(test);
		b.executeForm(test);
	}
	return 0;

}
