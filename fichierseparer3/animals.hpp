# ifndef ANIMALS_HPP__ 
# define ANIMALS_HPP__

class Animal {
public:
    void eat();
    void play();
};

class Cat : public Animal {
public:
    void meow();
};

class Dog : public Animal {
public:
    void bark();
};

#endif
