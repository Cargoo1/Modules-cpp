/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:25:36 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/24 15:52:47 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

#include "AForm.hpp"

#include <fstream>

# include "Bureaucrat.hpp"

# include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm()
{
	this->_target = "default?";
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target)
{
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return ;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this == &other)
		return *this;
	this->~ShrubberyCreationForm();
	new (this) ShrubberyCreationForm(other);
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getGrade2Exec())
		throw AForm::GradeTooLowException();
	std::fstream	file;

	file.open((this->_target + "_shrubbery").c_str(), std::fstream::in);
	if (!file.is_open())
		throw ShrubberyCreationForm::FileErrorException();
	file << 'a';
}

const char *	ShrubberyCreationForm::FileErrorException::what(void) const throw()
{
	return "FileErrorException happened.\n";
}
