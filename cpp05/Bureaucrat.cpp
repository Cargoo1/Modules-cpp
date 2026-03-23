/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:54:22 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/23 19:48:43 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <ostream>

Bureaucrat::Bureaucrat(void) : _name("default?"), _grade(150)
{
	return;
}

Bureaucrat::~Bureaucrat(void)
{
	return ;
}

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other.getName()), _grade(other.getGrade())
{
	return ;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this == &other)
		return (*this);
	this->~Bureaucrat();
	new (this) Bureaucrat(other);
	return (*this);
}

const std::string & Bureaucrat::getName(void) const
{
	return this->_name;
}

unsigned int	Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

const char *	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "GradeTooHigh exception happened.\n";
}

const char *	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "GradeTooLow exception happened.\n";
}

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& instance)
{
	o << instance.getName() + ", bureaucrat grade " << instance.getGrade() << "\n";
	return o;
}
