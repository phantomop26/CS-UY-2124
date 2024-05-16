/*
  08.polyConst
  Sec Base
*/

#include <iostream>
using namespace std;

class Base {
public:
    //Base() { foo(); }
    Base() { this->foo(); }
    virtual void foo() const { cout << "Base\n"; }
    //void display() { this->foo(); }
    void display() { foo(); }

    virtual ~Base() {} // just a good idea...
};

class Derived : public Base {
public:
    //Derived(int n) : Base(), x(n) {}
    Derived(int n) : x(n) {}
    void foo() const { cout << "Derived: x == " << x << endl; }
private:
    int x;
};

int main() {
    Derived der(17);
    //der.foo();
    der.display();
}
