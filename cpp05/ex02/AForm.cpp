/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:37:55 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/25 16:38:33 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

# include "Bureaucrat.hpp"
#include <ostream>

AForm::AForm() : _name("default?"), _isSigned(0), _minGrade2sign(150), _minGrade2exec(150)
{
	return ;
}

AForm::AForm(const std::string& name, unsigned int grade2sign, unsigned int grade2exec)
	: _name(name), _isSigned(0), _minGrade2sign(grade2sign), _minGrade2exec(grade2exec)
{
	if (grade2sign > 150)
		throw AForm::GradeTooLowException();
	else if (grade2sign < 1)
		throw AForm::GradeTooHighException();
	if (grade2exec > 150)
		throw AForm::GradeTooLowException();
	else if (grade2exec < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm& other) : _name(other.getName()), _isSigned(other._isSigned),
								_minGrade2sign(other._minGrade2sign),
								_minGrade2exec(other._minGrade2exec)
{
	return ;
}

AForm::~AForm(void)
{
	return ;
}

AForm&	AForm::operator=(const AForm& other)
{
	if (this == &other)
		return *this;
	this->_isSigned = other._isSigned;
	return *this;
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_minGrade2sign)
		throw AForm::GradeTooLowException();
	this->_isSigned = 1;
	return ;
}

const std::string& AForm::getName(void) const
{
	return this->_name;
}

unsigned int	AForm::getGrade2Sign(void) const
{
	return this->_minGrade2sign;
}

unsigned int	AForm::getGrade2Exec(void) const
{
	return this->_minGrade2exec;
}

bool	AForm::getIsSigned(void) const
{
	return this->_isSigned;
}

const char *	AForm::GradeTooHighException::what() const throw()
{
	return "GradeTooHigh exception happened.\n";
}

const char *	AForm::GradeTooLowException::what() const throw()
{
	return "GradeTooLow exception happened.\n";
}

const char *	AForm::NotSignedException::what() const throw()
{
	return "NotSigned exception happened.\n";
}

std::ostream&	operator<<(std::ostream& o, AForm& some_form)
{
	o << some_form.getName() + ", ";
	o << "signed state: " << some_form.getIsSigned() << ", ";
	o << "grade to sign: " << some_form.getGrade2Sign() << ", ";
	o << "grade to execute: " << some_form.getGrade2Exec() << "\n";
	return o;
}
