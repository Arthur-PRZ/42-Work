#include "../includes/Animal.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    Animal* animals[10];
    Dog a;
    Dog dog;
    dog = a;

    std::cout << "-----------------------" << std::endl;

    for (int i = 0; i < 5; i++)
        animals[i] = new Dog();
    for (int i = 5; i < 10; i++)
        animals[i] = new Cat();
    
    std::cout << "-----------------------" << std::endl;


    dog.makeSound();
    for (int i = 0; i < 10; i++)
        animals[i]->makeSound();

    std::cout << "-----------------------" << std::endl;

    for (int i = 0; i < 10; i++)
        delete animals[i];

    delete j;
    delete i;
    return 0;
}