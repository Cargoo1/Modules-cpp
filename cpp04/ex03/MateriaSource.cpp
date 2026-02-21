/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 18:21:25 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/21 21:41:10 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource(void)
{
	for (size_t i = 0; i < MAX_TEMPLATES; i++)
		this->_templates[i] = NULL;
	return ;
}

MateriaSource::MateriaSource(MateriaSource const & other)
{
	for (size_t i = 0; i < MAX_TEMPLATES; i++)
		this->_templates[i] = NULL;
	for (size_t i = 0; i < MAX_TEMPLATES; i++)
	{
		if (other._templates[i])
			this->_templates[i] = other._templates[i]->clone();
	}
	return ;
}

MateriaSource::~MateriaSource(void)
{
	for (size_t i = 0; i < MAX_TEMPLATES; i++)
	{
		if (this->_templates[i])
			delete this->_templates[i];
	}
	return ;
}

MateriaSource&	MateriaSource::operator=(MateriaSource const & other)
{
	if (this == &other)
		return (*this);
	this->~MateriaSource();
	new (this) MateriaSource(other);
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m)
{
	size_t	i;

	i = 0;
	while (i < MAX_TEMPLATES && this->_templates[i])
		i++;
	if (i >= MAX_TEMPLATES)
		return ;
	this->_templates[i] = m;
	return ;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	size_t	idx;

	idx = 0;
	while (idx < MAX_TEMPLATES)
	{
		if (this->_templates[idx] && this->_templates[idx]->getType().compare(type) == 0)
			break ;
		idx++;
	}
	if (idx >= MAX_TEMPLATES)
		return (NULL);
	return (this->_templates[idx]->clone());
}
