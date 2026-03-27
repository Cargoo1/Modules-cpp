/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 15:19:40 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/27 16:02:33 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP

# define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include <string>
class	Intern
{
public:
	Intern(void);
	Intern(const Intern& other);
	~Intern(void);

	Intern&	operator=(const Intern& other);
	AForm*	makeForm(const std::string& form_name, const std::string& target) const;
private:
	AForm*	makePresiPardon(const std::string& target) const;
	AForm*	makeRobotomyRequest(const std::string& target) const;
	AForm*	makeShrubberyCreation(const std::string& target) const;

};


#endif
