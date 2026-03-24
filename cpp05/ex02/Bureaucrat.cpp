/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:54:22 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/24 15:14:19 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>
#include <iostream>

Bureaucrat::Bureaucrat(void) : _name("default?"), _grade(150)
{
	std::cout << "Bureaucrat constructor called\n";
	return;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called\n";
	return ;
}

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade) : _name(name)
{
	std::cout << "Bureaucrat constructor w parameters called\n";
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

void	Bureaucrat::signForm(AForm& some_form)
{
	try
	{
		some_form.beSigned(*this);
		std::cout << this->getName() + " signed " + some_form.getName() + '\n';
	}
	catch(std::exception& e)
	{
		std::cout << this->getName() + " couldn't sign " + some_form.getName() + "because ";
		std::cout << this->getName() + " grade is too low :(\n";
	}
}

const std::string & Bureaucrat::getName(void) const
{
	return this->_name;
}

unsigned int	Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void	Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
	std::cout << *this;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
	std::cout << *this;
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
