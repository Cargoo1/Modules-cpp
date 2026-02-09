/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:14:37 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/09 12:39:42 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP

#define HARL_HPP

# include <string>

class	Harl
{
public:
	Harl(void);
	~Harl(void);
	void	complain(std::string level);
private:
	void	_debug(void);
	void	_info(void);
	void	_warning(void);
	void	_error(void);
	void	_unknownlevel(void);
};

#endif
