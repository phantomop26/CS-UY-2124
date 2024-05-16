#include <string>
#include <vector>
#include <iostream>
#include "Noble.h"
#include "Protector.h"
using namespace std;

namespace WarriorCraft {
    //Base constructor for a Protector
    Protector::Protector(const string& name, double strength): name(name), strength(strength), alive(true), lord(nullptr) {}

    //Get the name of the Protector
    const string& Protector::getName() const {
        return name;
    }

    //@brief Get the strength of the Protector
    double Protector::getStrength() const {
        return strength;
    }

    //Set the strength of the Protector
    void Protector::setStrength(double strength) {
        this->strength = strength;
    }

    //Return the Lord of the Protector
    Lord* const Protector::getLord() const {
        return lord;
    }

    //Set the Lord of the Protector
    void Protector::setLord(Lord* lord) {
        this->lord = lord;
    }

    //Have the Protector runaway from his Lord
    bool Protector::runaway() {
        if (lord != nullptr) {
            cout << name << " flees in terror, abandoning his lord, " << lord->getName() << endl;
            lord->fires(*this,true);
            lord = nullptr;
            return true;
        }
        return false;
    }

    //Output the Protector's name and strength
    ostream& operator<<(ostream& os, const Protector& protector) {
        os << protector.name << " has strength " << protector.strength;
        return os;
    }

    //Construct a new Wizard object
    Wizard::Wizard(const string& name, double strength): Protector(name, strength) {}

    //Output the Wizard's battle cry
    void Wizard::battleCry() const {
        cout << "POOF" << endl;
    }

    //Construct a new Warrior object
    Warrior::Warrior(const string& name, double strength): Protector(name, strength) {}

    //Construct a new Archer object
    Archer::Archer(const string& name, double strength): Warrior(name, strength) {}

    //Output the Archer's battle cry
    void Archer::battleCry() const {
        cout << "TWANG! " << getName() << " says: Take that in the name of my lord, " << getLord()->getName() << endl;
    }

    //Construct a new Swordsman object
    Swordsman::Swordsman(const string& name, double strength): Warrior(name, strength) {}

    //Output the Swordsman's battle cry
    void Swordsman::battleCry() const {
        cout << "CLANG! " << getName() << " says: Take that in the name of my lord, " << getLord()->getName() << endl;
    }
}

