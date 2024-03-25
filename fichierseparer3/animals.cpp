#include <iostream>
#include "animals.hpp"

void Animal::eat() {
    std::cout << "Animal is eating" << std::endl;
}

void Animal::play() {
    std::cout << "Animal is playing" << std::endl;
}

void Cat::meow() {
    std::cout << "Cat says: Meow" << std::endl;
}

void Dog::bark() {
    std::cout << "Dog says: Bark" << std::endl;
}

