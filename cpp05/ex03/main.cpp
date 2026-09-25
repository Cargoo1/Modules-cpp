/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:38:27 by acamargo          #+#    #+#             */
/*   Updated: 2026/09/15 21:29:27 by acamargo         ###   ########.fr       */
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
		Intern	someone;
		AForm	*form;
		Bureaucrat	b("pablo", 150);

		form = someone.makeForm("asdasd creation", "pablo");
		form = someone.makeForm("robotomy request", "pablo");
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
		Intern	someone;
		AForm	*form;
		Bureaucrat	b("pierre", 1);

		form = someone.makeForm("asdasd creation", "pierre");
		form = someone.makeForm("robotomy request", "pierre");
		if (form)
		{
			b.signForm(*form);
			b.executeForm(*form);
		}
		std::cout << "--- end test 1 ---\n";
		if (form)
			delete form;
	}
	return 0;

}
