
/*
  publicInterface.cpp
  Section B - 24S
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Pet {
    public:
    virtual void purr(){cout<<"Pet purr"<<endl;}
 };

class Cat : public Pet {
public:
    void purr() { cout << "purrr"; }
};

void someFunc(Pet& aPet) {
    cout << "someFunc: ";
    aPet.purr();
}

int main() {
    Cat felix;
    someFunc(felix);
}
