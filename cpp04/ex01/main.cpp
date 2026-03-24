/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:53:51 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/24 12:12:09 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

# include <iostream>
#include "Brain.hpp"
# include "Cat.hpp"
#include "Dog.hpp"


int	main(void)
{
	{
		Animal	**animals = new Animal*[10];
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
	{
		Dog	doggie;
		doggie.setBrain("New idea?", 0);
		Dog another_dog;
		another_dog = doggie;
		std::cout << doggie.getBrain()->getIdeas()[0] << '\n';
		std::cout << another_dog.getBrain()->getIdeas()[0] << '\n';
	}
	Animal	lol;
	Dog	a;
	lol = a;
	std::cout << lol.getType() + '\n';
}
