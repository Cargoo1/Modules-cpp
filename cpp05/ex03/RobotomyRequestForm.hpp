/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:44:55 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/25 15:51:27 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP

#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class	RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	~RobotomyRequestForm(void);

	RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);

	void	execute(Bureaucrat const & executor) const;
private:
	std::string	_target;
};

#endif
