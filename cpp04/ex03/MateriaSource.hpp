/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 18:12:49 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/21 21:41:49 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MATERIASOURCE_HPP

# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

# define MAX_TEMPLATES 4

class	MateriaSource : public IMateriaSource
{
public:
	MateriaSource(void);
	MateriaSource(MateriaSource const & other);
	~MateriaSource(void);

	MateriaSource&	operator=(MateriaSource const & other);

	void	learnMateria(AMateria *m);
	AMateria	*createMateria(std::string const & type);
private:
	AMateria	*_templates[MAX_TEMPLATES];
};

#endif
