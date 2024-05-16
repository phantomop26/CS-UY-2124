/*
  final.cpp
  -jbs
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Simple inheritance
class Base1 {};
class Derived1 : public Base1 {};


// Defining a final class
class Base2 final {};
// Attempting inheritance with a final class
//class Derived2 : public Base2 {};


//
// Four levels
//   Defining a final method
//
class Base3 {
public:
    virtual void foo() {
        cout<<"b3"<<endl;
    }
};

class Middle3a : public Base3 {
public:
    // Overriding
    void foo() override {
        cout<<"m3a"<<endl;
    }
};

class Middle3b : public Middle3a {
public:
    // Overriding. For the last time!
    void foo() final {
        cout<<"m3b"<<endl;
    }
};

class Derived3 : public Middle3b {
public:
    // Attempting to override a final method
    // void foo() {}
};

int main() {
    // The simple case
    Base1 b1;
    Derived1 d1;

    // Creating an instance of a final class
    Base2 b2;
    // But this class won't have compiled
    // Derived2 d2;
    
    // Creating an instance of a base class 
    Base3 b3;
    b3.foo();
    // Creating an instance of a class overriding base method
    Middle3a m3a;
    m3a.foo();
    // Creating an instance of a class declares a method final
    Middle3b m3b;
    m3b.foo();
    // But this class won't have compiled
    Derived3 d3;
    d3.foo();
}
