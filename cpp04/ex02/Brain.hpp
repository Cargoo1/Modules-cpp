/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:58:48 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/20 18:12:50 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP

#define BRAIN_HPP

# include <string>

class	Brain
{
public:
	Brain(void);
	Brain(Brain const & other);
	~Brain(void);

	Brain&	operator=(Brain const & other);
	std::string	const *getIdeas(void) const;
	bool	setIdeas(std::string const & idea, int idx);
private:
	std::string	*_ideas;
};

#endif
