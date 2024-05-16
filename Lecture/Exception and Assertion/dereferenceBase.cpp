/*
  dereferenceBasePtr.cpp

  demonstrates that dereferencing a base pointer returns whatever the
  pointer was pointing to. Here a Derived.
  But the COMPILE TIME type is still Base.
 */

#include <iostream>
using namespace std;

class Base {
public:
    virtual void foo() { cout << "Base::foo\n"; }
private:
};

class Derived : public Base {
public:
    virtual void foo() { cout << "Derived::foo\n"; }
private:
};

void func2(Base& baseRef) {
    cout << "In func2(Base& baseRef)\n";
    baseRef.foo();
}

void func2(Derived& derivedRef) {
    cout << "In func2(Derived& derivedRef)\n";
    derivedRef.foo();
}

void func(Base* bp) {
    func2(*bp);
}

int main() {
    Base* B =new Derived();
    func(B);
}