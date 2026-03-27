/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:24:19 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/25 16:36:38 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUREAUCRAT_HPP

# define BUREAUCRAT_HPP

#include "AForm.hpp"
# include <exception>

#include <ostream>
# include <string>

class	Bureaucrat
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

	Bureaucrat(void);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat(const std::string & name, unsigned int grade);
	~Bureaucrat(void);

	Bureaucrat&	operator=(Bureaucrat const& other);

	const std::string& getName(void) const;
	void	executeForm(AForm const & form) const;
	void	incrementGrade();
	void	decrementGrade();
	unsigned int getGrade(void) const;
	void	signForm(AForm & some_form);

private:
	const std::string _name;
	unsigned int	_grade;
};

std::ostream& operator<<(std::ostream &o, const Bureaucrat& instance);

#endif
