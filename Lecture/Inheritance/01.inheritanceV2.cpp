
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

    Pet(const string& name) : name(name) {}

    //void eat() { cout << "eating" << endl; }
    // Enabling polymorphism
    virtual void eat() { cout << "eating" << endl; }
    const string& getName() const { return name; }
private:
    string name;
};

class Cat : public Pet {
public:
    //Cat() {}
    // Cat() : Pet() {}
    Cat(const string& name) : Pet(name) {}

    //void eat() { cout << "Cat eating" << endl; }
    void eat() {
        cout << "Cat ";
        Pet::eat();
    }

    void purr() {
        //cout << name << " purring\n"; // will not compile
        cout << getName() << " purring\n"; // will not compile
    }
};

class Slug : public Pet {
public:
    using Pet::Pet;
};

class Roach : public Pet { 
    public:
    using Pet::Pet;
};

//void someFunc(Pet aPet) {
void someFunc(Pet& aPet) {
    cout << "someFunc: ";
    aPet.eat();
}

int main() {
    // //Pet peeve;
    Pet peeve("Peeve");
    // peeve.eat();
    someFunc(peeve);

    // Cat felix;
    Cat felix("Felix");
    // felix.eat();    // 
    //someFunc(felix);  // Principle of Substitutability -- Barbara Liskov

    // Slug sluggo("chu");
    // Roach archie("lol");

    // vector<Pet> menagerie;
    // menagerie.push_back(peeve);
    // menagerie.push_back(felix);
    // menagerie.push_back(sluggo);
    // menagerie.push_back(archie);

    // //    for (Pet val : menagerie) {
    // for (Pet& val : menagerie) {
    //     val.eat();
    // }

    // vector<Pet*> menagerieV2;
    // menagerieV2.push_back(&peeve);
    // menagerieV2.push_back(&felix);
    // menagerieV2.push_back(&sluggo);
    // menagerieV2.push_back(&archie);

    // //    for (Pet val : menagerie) {
    // //for (const Pet* val : menagerieV2) {
    // for (Pet* val : menagerieV2) {
    //     val->eat();
    // }
}
