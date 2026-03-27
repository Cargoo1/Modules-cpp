/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 14:57:00 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/27 14:58:01 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP

#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	~PresidentialPardonForm(void);

	PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);

	void	execute(Bureaucrat const & executor) const;
private:
	std::string	_target;
};

#endif
