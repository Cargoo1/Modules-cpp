/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:53:51 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/20 18:53:32 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

# include <iostream>
#include "Brain.hpp"
# include "Cat.hpp"
#include "Dog.hpp"


int	main(void)
{
	AAnimal	**animals = new AAnimal*[10];
	for(int i = 0; i < 5; i++)
		animals[i] = new Dog();
	for (int j = 5; j < 10; j++)
		animals[j] = new Cat();

	for (int i = 0; i < 10; i++)
		animals[i]->makeSound();
	for (int i = 0; i < 10; i++)
		delete animals[i];
	delete [] animals;
}
