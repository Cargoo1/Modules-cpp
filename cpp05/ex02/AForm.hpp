/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 12:43:02 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/24 15:30:11 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP

#define AFORM_HPP

# include <exception>

#include <ostream>
# include <string>

class Bureaucrat;

class	AForm
{
public:
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *	what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *	what() const throw();
	};
	AForm();
	AForm(const std::string& name, const unsigned int grade2sign,
									const unsigned int grade2exec);
	AForm(const AForm& other);
	virtual ~AForm();

	AForm&	operator=(const AForm& other);

	void	beSigned(const Bureaucrat& bureaucrat);

	const std::string&	getName(void) const;
	unsigned int	getGrade2Sign(void) const;
	unsigned int	getGrade2Exec(void) const;
	bool			getIsSigned(void) const;

private:
	const std::string	_name;
	bool	_isSigned;
	const unsigned int	_minGrade2sign;
	const unsigned int	_minGrade2exec;
};

std::ostream&	operator<<(std::ostream& o, AForm& some_form);

#endif
