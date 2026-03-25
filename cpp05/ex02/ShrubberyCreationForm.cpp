/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:25:36 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/25 15:56:54 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

#include "AForm.hpp"

#include <fstream>

# include "Bureaucrat.hpp"

# include <iostream>

# define TREE_HEIGHT 8

# define LOG_HEIGHT 2

# define TREE_WIDTH 15

# define TREE_MID (TREE_WIDTH / 2)

# define TREE_NBR 6

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
	if (!this->getIsSigned())
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getGrade2Exec())
		throw AForm::GradeTooLowException();
	std::fstream	file;

	file.open((this->_target + "_shrubbery").c_str(), std::fstream::out);
	if (!file.is_open())
		throw ShrubberyCreationForm::FileErrorException();
	this->write_tree(file);
}

void	ShrubberyCreationForm::write_tree(std::fstream& file) const
{
	this->write_leafs(file);
	this->write_logs(file);
}

void	ShrubberyCreationForm::write_leafs(std::fstream& file) const
{
	int cols;

	for (int j = 0; j < TREE_HEIGHT; j++)
	{
		for (int k = 0; k < TREE_NBR; k++)
		{
			cols = 0;
			while (cols < TREE_MID - j)
			{
				file << ' ';
				cols++;
			}
			while (cols <= TREE_MID + j)
			{
				file << '*';
				cols++;
			}
			while (cols < TREE_WIDTH)
			{
				file << ' ';
				cols++;
			}
			file << "     ";
		}
		file << '\n';
	}
}

void	ShrubberyCreationForm::write_logs(std::fstream& file) const
{
	int	cols;

	for (int j = 0; j < LOG_HEIGHT; j++)
	{
		for (int k = 0; k < TREE_NBR; k++)
		{
			cols = 0;
			while (cols < TREE_MID - 1)
			{
				file << ' ';
				cols++;
			}
			file << "| |";
			cols += 3;
			while (cols < TREE_WIDTH)
			{
				file << ' ';
				cols++;
			}
			file << "     ";
		}
		file << '\n';
	}
}

const char *	ShrubberyCreationForm::FileErrorException::what(void) const throw()
{
	return "FileErrorException happened.\n";
}
