#include <iostream>

using namespace std;

class Battery{
public:
    Battery(int charge = 100){
        this->Charge = charge;

        if(Charge > 100)
            Charge = 100;
        else if(Charge < 0)
            Charge = 0;
    }

    void leftCharge();
    void useCharge();
    void chargeBettery();

    ~Battery() {}

private:
    int Charge;
};

void Battery::leftCharge(){
    cout << Charge << endl;
}

void Battery::useCharge(){
    if(Charge >= 5)
        Charge -= 5;
    else
        Charge = 0;

    cout << Charge << endl;
}

void Battery::chargeBettery(){
    if(Charge <= 93)
        Charge += 7;
    else
        Charge = 100;

    cout << Charge << endl;
}

int main(){
    Battery b;

    b.leftCharge();
    b.useCharge();
    b.useCharge();
    b.chargeBettery();
}