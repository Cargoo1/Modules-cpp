/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:37:55 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/24 14:30:23 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

# include "Bureaucrat.hpp"
#include <ostream>

Form::Form() : _name("default?"), _isSigned(0), _minGrade2sign(150), _minGrade2exec(150)
{
	return ;
}

Form::Form(const std::string& name, unsigned int grade2sign, unsigned int grade2exec)
	: _name(name), _isSigned(0), _minGrade2sign(grade2sign), _minGrade2exec(grade2exec)
{
	if (grade2sign > 150)
		throw Form::GradeTooLowException();
	else if (grade2sign < 1)
		throw Form::GradeTooHighException();
	if (grade2exec > 150)
		throw Form::GradeTooLowException();
	else if (grade2exec < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const Form& other) : _name(other.getName()), _isSigned(other._isSigned),
								_minGrade2sign(other._minGrade2sign),
								_minGrade2exec(other._minGrade2exec)
{
	return ;
}

Form::~Form(void)
{
	return ;
}

Form&	Form::operator=(const Form& other)
{
	if (this == &other)
		return *this;
	this->~Form();
	new (this) Form(other);
	return *this;
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_minGrade2sign)
		throw Form::GradeTooLowException();
	this->_isSigned = 1;
	return ;
}

const std::string& Form::getName(void) const
{
	return this->_name;
}

unsigned int	Form::getGrade2Sign(void) const
{
	return this->_minGrade2sign;
}

unsigned int	Form::getGrade2Exec(void) const
{
	return this->_minGrade2exec;
}

bool	Form::getIsSigned(void) const
{
	return this->_isSigned;
}

const char *	Form::GradeTooHighException::what() const throw()
{
	return "GradeTooHigh exception happened.\n";
}

const char *	Form::GradeTooLowException::what() const throw()
{
	return "GradeTooLow exception happened.\n";
}

std::ostream&	operator<<(std::ostream& o, Form& some_form)
{
	o << some_form.getName() + ", ";
	o << "signed state: " << some_form.getIsSigned() << ", ";
	o << "grade to sign: " << some_form.getGrade2Sign() << ", ";
	o << "grade to execute: " << some_form.getGrade2Exec() << "\n";
	return o;
}
