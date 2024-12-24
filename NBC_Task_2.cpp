#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

class Animal{
public:
    Animal() {}

    virtual void makeSound() {}
    virtual ~Animal() {}

protected:
    string m_word;
};

class Dog : public Animal{
public:
    Dog(string word) { this->m_word = word; }
    void makeSound() { cout << this->m_word << endl; }
};

class Cat : public Animal{
public:
    Cat(string word) { this->m_word = word; }
    void makeSound() { cout << this->m_word << endl; }
};

class Cow : public Animal{
public:
    Cow(string word) { this->m_word = word; }
    void makeSound() { cout << this->m_word << endl; }
};

Animal* createRandomAnimal(){
    Animal* ani = nullptr;

    int num = rand() % 3;

    if(num == 0)
        ani = new Dog("멍멍");
    else if(num == 1)
        ani = new Cat("냥냥");
    else
        ani = new Cow("음머");

    return ani;
}

class Zoo{
protected:
    Animal* animals[10] = { 0 };

public:
    Zoo() {}

    void addAnimal(Animal* animal);
    void performActions();

    ~Zoo(){
        delete[] animals;
    }
};

void Zoo::addAnimal(Animal* animal){
    for(int i = 0; i < 10; i++){
        if(animals[i] == nullptr){
            animals[i] = animal;
            break;
        }
    }
}

void Zoo::performActions(){
    for(int i = 0; i < 10; i++){
        animals[i]->makeSound();
    }
}

int main(){
    srand((unsigned int)time(NULL));

    Zoo* zoo = new Zoo();

    for(int i = 0; i < 10; i++){
        Animal* ani = createRandomAnimal();
        zoo->addAnimal(ani);
    }

    zoo->performActions();

    delete zoo;

    return 0;
}