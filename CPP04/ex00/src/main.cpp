#include "../includes/Animal.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* a = new WrongAnimal();
    const WrongAnimal* b = new WrongCat();

    std::cout << "--------------------" << std::endl;

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    std::cout << "--------------------" << std::endl;

    std::cout << a->getType() << " " << std::endl;
    std::cout << b->getType() << " " << std::endl;
    a->makeSound();
    b->makeSound();

    std::cout << "--------------------" << std::endl;

    delete meta;
    delete j;
    delete i;
    delete a;
    delete b;
    return 0;
}