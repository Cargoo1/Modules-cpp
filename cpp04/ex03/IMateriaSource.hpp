/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 18:05:31 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/21 18:10:24 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef IMATERIASOURCE_HPP

# define IMATERIASOURCE_HPP

#include "AMateria.hpp"
class	IMateriaSource
{
public:
	IMateriaSource(void);
	IMateriaSource(IMateriaSource const & other);
	virtual	~IMateriaSource(void);

	IMateriaSource&	operator=(IMateriaSource const & other);

	virtual void	learnMateria(AMateria *m) = 0;
	virtual AMateria	*createMateria(std::string const & type) = 0;
};

#endif
