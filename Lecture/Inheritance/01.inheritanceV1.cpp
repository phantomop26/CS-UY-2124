
/*
  1.inheritance.cpp
  Section B - 24S

  Code reuse, principle of substitutability, polymorphism
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Pet {
public:
    // void eat() { cout << "eating" << endl; }
    // Enabling polymorphism
    virtual void eat() { cout << "eating" << endl; }
};

class Cat : public Pet {
public:
    // void eat() { cout << "Cat eating" << endl; }
    void eat() {
        cout << "Cat ";
        Pet::eat();
    }
};

class Slug : public Pet { };

class Roach : public Pet {};

//void someFunc(Pet aPet) {
void someFunc(Pet& aPet) {
    cout << "someFunc: ";
    aPet.eat();
}
// void someFunc(Cat& aPet) {
//     cout << "newFunc: ";
//     aPet.eat();
// }

int main() {
    Pet peeve;
    peeve.eat();
    someFunc(peeve);

    Cat felix;
    felix.eat();    // 
    someFunc(felix);  // Principle of Substitutability -- Barbara Liskov

    Slug sluggo;
    sluggo.eat(); // code reuse

    Roach archie;

    // vector<Pet> menagerie;
    // menagerie.push_back(peeve);
    // menagerie.push_back(felix);
    // menagerie.push_back(sluggo);
    // menagerie.push_back(archie);

    // //for (Pet val : menagerie) {
    // for (Pet& val : menagerie) {
    //     val.eat();
    // }

    vector<Pet*> menagerieV2;
    menagerieV2.push_back(&peeve);
    menagerieV2.push_back(&felix);
    menagerieV2.push_back(&sluggo);
    menagerieV2.push_back(&archie);

    // //    for (Pet val : menagerie) {
    // //for (const Pet* val : menagerieV2) {
    for (Pet* val : menagerieV2) {
        val->eat();
    }
}
