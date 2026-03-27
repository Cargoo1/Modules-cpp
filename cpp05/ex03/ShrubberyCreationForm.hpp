/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:15:25 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/25 15:35:02 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP

# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <exception>
#include <fstream>
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
	void	write_tree(std::fstream& file) const;
	void	write_leafs(std::fstream& file) const;
	void	write_logs(std::fstream& file) const;
	std::string	_target;
};

#endif
