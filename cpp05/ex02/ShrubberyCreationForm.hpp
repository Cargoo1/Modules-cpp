/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:15:25 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/24 15:48:18 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP

# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <exception>
#include <string>

class	ShrubberyCreationForm: public AForm
{
public:
	class	FileErrorException : public std::exception
	{
		public:
			virtual const char *	what() const throw();
	};
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);

	void	execute(Bureaucrat const & executor) const;
private:
	std::string	_target;
};

#endif
