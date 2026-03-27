/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 14:58:19 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/27 15:01:53 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

# include "Bureaucrat.hpp"

#include "AForm.hpp"

# include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void) : AForm()
{
	this->_target = "default?";
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), _target(other._target)
{
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return ;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this == &other)
		return *this;
	this->~PresidentialPardonForm();
	new (this) PresidentialPardonForm(other);
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getGrade2Exec())
		throw AForm::GradeTooLowException();
	std::cout << this->_target + " has been pardoned by Zaphod Beeblebrox.\n";
	return ;
}
