/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:58:00 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/25 16:24:39 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"
# include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>
# include <iostream>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm()
{
	this->_target = "default?";
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target)
{
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return ;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this == &other)
		return *this;
	this->~RobotomyRequestForm();
	new (this) RobotomyRequestForm(other);
	return *this;
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (!this->getIsSigned())
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getGrade2Exec())
		throw AForm::GradeTooLowException();
	std::cout << "* making some drilling noises *\n";
	srand(time(NULL));
	int	coin_toss = rand() % 2;
	if (!coin_toss)
	{
		std::cout << "The robotomy has failed...\n";
		return ;
	}
	std::cout << this->_target + " has been successfully robotomized!\n";
	return ;
}
