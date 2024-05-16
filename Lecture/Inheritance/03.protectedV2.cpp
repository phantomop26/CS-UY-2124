/*
  03.protectedV2.cpp
  Inclass Base
*/

#include <iostream>
#include <string>
using namespace std;

class Pet {
public:
    Pet(const string& name) : name(name) {}
    
protected:
const string& getName() const { return name; }
    
private:
    string name;
    
};

class Dog : public  Pet {
public:
    Dog(const string& name) : Pet(name) {}
};

class Cat : public Pet {
public:
    Cat(const string& name) : Pet(name) {}
    void display() const {
	cout << getName() << endl;
    }
    void displayDog(const Dog& aDog) const {
	cout << aDog.getName() << endl;
    }
};

int main() {
    Cat felix("Felix");
    // cout << felix.getName()<<endl;
    felix.display();
    Dog fido("Fido");
    felix.displayDog(fido);
}
