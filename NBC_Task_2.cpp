#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Animal{ // Animal 객체 생성
public:
    Animal() {}

    virtual void makeSound() {}
    virtual ~Animal() {}

protected:
    string m_word;
};

class Dog : public Animal{ // 강아지
public:
    Dog(string word) { this->m_word = word; }
    void makeSound() { cout << "강아지 " << this->m_word << endl; }
};

class Cat : public Animal{ // 고양이
public:
    Cat(string word) { this->m_word = word; }
    void makeSound() { cout << "고양이 " << this->m_word << endl; }
};

class Cow : public Animal{ // 송아지지
public:
    Cow(string word) { this->m_word = word; }
    void makeSound() { cout << "송아지 " << this->m_word << endl; }
};

Animal* createRandomAnimal(){           // 랜덤 Animal 객체 생성성
    Animal* ani = nullptr;

    int num = rand() % 3;               // 난수 발생!!!

    if(num == 0)
        ani = new Dog("멍멍!");
    else if(num == 1)
        ani = new Cat("냥냥!");
    else
        ani = new Cow("음매!");

    return ani;
}

class Zoo{ // Zoo 객체 생성
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

void Zoo::addAnimal(Animal* animal){    // 비워져 있는 배열에 Animal 추가
    for(int i = 0; i < 10; i++){
        if(animals[i] == nullptr){
            animals[i] = animal;
            break;
        }
    }
}

void Zoo::performActions(){             // 비워져 있지 않는 동물 울음소리 발생
    for(int i = 0; i < 10; i++){
        if(animals[i] != nullptr)
            animals[i]->makeSound();
    }
}

int main(){
    srand((unsigned int)time(NULL));    // 실행 시 특정한 난수 Seed값 부여

    Zoo* zoo = new Zoo();               

    for(int i = 0; i < 10; i++){
        Animal* ani = createRandomAnimal();
        zoo->addAnimal(ani);
    }

    zoo->performActions();

    delete zoo;                         // 소멸자 실행
    zoo = nullptr;

    return 0;
}