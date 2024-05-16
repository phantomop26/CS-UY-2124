/*
  6.OverrideVsOverload.cpp
  Demonstrates how the compiler makes the choice for overloading based
  when the parameters are related by inheritance
 */
#include <iostream>
using namespace std;
class Parent {};
class Child : public Parent {};
class Grandchild : public Child {};

void func(Parent& base) { cout << "func(Parent)\n"; }
void func(Child& derived) {cout << "func(Child)\n"; }
  
void otherFunc(Parent& base) {
    func(base);
}
int main() {
    Parent parent;
    func(parent);
    Child child;
    func(child);
    Grandchild gc;
    func(gc);
    otherFunc(child);}
