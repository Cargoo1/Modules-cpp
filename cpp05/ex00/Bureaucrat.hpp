/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:24:19 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/24 12:17:22 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUREAUCRAT_HPP

# define BUREAUCRAT_HPP

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

	Bureaucrat&	operator=(const Bureaucrat& other);

	const std::string& getName(void) const;
	void	incrementGrade();
	void	decrementGrade();
	unsigned int getGrade(void) const;

private:
	const std::string _name;
	unsigned int	_grade;
};

std::ostream& operator<<(std::ostream &o, const Bureaucrat& instance);

#endif
