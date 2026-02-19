/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:53:51 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/19 22:16:47 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
# include "Cat.hpp"
#include "Dog.hpp"

# include <iostream>

int	main(void)
{
	Animal	*cat = new Cat();
	Animal	test;
	Animal	*dog = new Dog();

	test.makeSound();
	cat->makeSound();
	dog->makeSound();
	std::cout << cat->getType() + '\n';
	std::cout << dog->getType() + '\n';
	std::cout << test.getType() + '\n';
	delete cat;
	delete dog;
	Cat	a;
}
