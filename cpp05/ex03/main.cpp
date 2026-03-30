/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:38:27 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/28 17:15:59 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
# include <iostream>

int	main(void)
{
	{
		std::cout << "--- Test 1 ---\n";
		Intern	someone;
		AForm	*form;
		Bureaucrat	b("pepe", 3);

		form = someone.makeForm("shrubbery creation", "pablo");
		if (form)
		{
			b.signForm(*form);
			b.executeForm(*form);
		}
		std::cout << "--- end test 1 ---\n";
		if (form)
			delete form;
	}
	{
		std::cout << "--- Test 2 ---\n";
		RobotomyRequestForm	test("PABLO");
		Bureaucrat			b("pablo", 100);
		b.signForm(test);
		b.executeForm(test);
		b = Bureaucrat("pepe", 30);
		b.signForm(test);
		b.executeForm(test);
		std::cout << "--- end test 2 ---\n";
	}
	{
		std::cout << "--- Test 3 ---\n";
		PresidentialPardonForm	test("PABLO");
		Bureaucrat			b("pablo", 100);
		b.signForm(test);
		b.executeForm(test);
		b = Bureaucrat("pepe", 24);
		b.signForm(test);
		b.executeForm(test);
		std::cout << "--- end test 3 ---\n";
	}
	return 0;

}
