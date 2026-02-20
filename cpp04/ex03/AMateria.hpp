/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 20:02:57 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/20 21:25:04 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP

#define AMATERIA_HPP

# include <string>

class	ICharacter;

class	AMateria
{
public:
	AMateria(void);
	AMateria(std::string const & type);
	AMateria(AMateria const & other);
	virtual ~AMateria(void);

	AMateria&	operator=(AMateria const & other);

	std::string	const & getType(void) const;
	virtual AMateria* clone(void) = 0;
	virtual void	use(ICharacter& target);
protected:
	std::string	_type;
};


#endif
