/*
  02.override.cpp
  Inclass Base
 */

#include <iostream>
using namespace std;

class Base {
public:
    virtual void whereAmI() { cout << "Base\n"; }
};

class Derived : public Base {
public:
    //void whereamI() { cout << "Derived\n"; }
    //void whereamI() override { cout << "Derived\n"; }
    void whereAmI() override { cout << "Derived\n"; }
};

void foo(Base& thing) {
    thing.whereAmI();
}

int main() {
    Base base;
    foo(base);

    Derived der;
    foo(der);
}

