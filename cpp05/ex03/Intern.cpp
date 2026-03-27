/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 15:25:07 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/27 16:02:40 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
# include <iostream>
#include <exception>

Intern::Intern(void)
{
	return ;
}

Intern::Intern(Intern const & other)
{
	(void)other;
	return ;
}

Intern::~Intern(void)
{
	return ;
}

Intern&	Intern::operator=(const Intern& other)
{
	if (this == &other)
		return *this;
	return *this;
}

AForm*	Intern::makeForm(const std::string& form_name, const std::string& target) const
{
	AForm*	(Intern::*forms_makers[3])(const std::string&) const = {&Intern::makePresiPardon,
																	&Intern::makeRobotomyRequest,
																	&Intern::makeShrubberyCreation};
	std::string		names[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	for (int i = 0; i < 3; i++)
	{
		if (names[i].compare(form_name) == 0)
			return (this->*forms_makers[i])(target);
	}
	std::cout << form_name + " does not exists\n";
	return NULL;
}

AForm*	Intern::makePresiPardon(const std::string& target) const
{
	PresidentialPardonForm	*new_form;
	try
	{
		new_form = new PresidentialPardonForm(target);
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
		return NULL;
	}
	std::cout << "Inter creates " + new_form->getName() + '\n';
	return new_form;
}

AForm*	Intern::makeRobotomyRequest(const std::string& target) const
{
	RobotomyRequestForm	*new_form;
	try
	{
		new_form = new RobotomyRequestForm(target);
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
		return NULL;
	}
	std::cout << "Inter creates " + new_form->getName() + '\n';
	return new_form;
}

AForm*	Intern::makeShrubberyCreation(const std::string& target) const
{
	ShrubberyCreationForm	*new_form;
	try
	{
		new_form = new ShrubberyCreationForm(target);
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
		return NULL;
	}
	std::cout << "Inter creates " + new_form->getName() + '\n';
	return new_form;
}
