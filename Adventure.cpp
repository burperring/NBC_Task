#include <iostream>
#include <vector>

using namespace std;

class Adventure{
public:
    virtual void useSkill() {}
    virtual ~Adventure() {}
};

class Warrior : public Adventure{
    void useSkill(){
        cout << "Warror uses Slash!" << endl;
    }
};

class Mage : public Adventure{
    void useSkill(){
        cout << "Mage casts Fireball!" << endl;
    }
};

class Archer : public Adventure{
    void useSkill(){
        cout << "Archer shoots an Arrow!" << endl;
    }
};

int main(){
    vector<Adventure*> advChars;
    advChars.push_back(new Warrior());
    advChars.push_back(new Mage());
    advChars.push_back(new Archer());

    for(auto x : advChars){
        x->useSkill();
    }

    for(auto x : advChars){
        delete x;
    }
}