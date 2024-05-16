#include <vector>
#include <string>
#include <iostream>
#include "Noble.h"
#include "Warrior.h"
using namespace std;

namespace WarriorCraft {
    Warrior::Warrior(const string& name, double strength): 
    name(name), strength(strength), employer(nullptr) {}
    const string& Warrior::getName() const {
        return name;
    }
    const double Warrior::getStrength() const {
        return strength;
    }
    void Warrior::setStrength(double strength) {
        this->strength = strength;
    }
    const Noble* Warrior::getEmployer() const {
        return employer;
    }
    void Warrior::setEmployer(Noble* employer) {
        this->employer = employer;
    }
    bool Warrior::isHired() const {
        return employer != nullptr;
    }
    bool Warrior::runaway() {
        if (employer != nullptr) {
            cout << name << " flees in terror, abandoning his lord, "
                << employer->getName() << endl;
            employer->fire(*this);
            return true;
        }
        else {
            cout << name << " is already unemployed." << endl;
            return false;
        }
    }
    ostream& operator<<(ostream& os, const Warrior& warrior) {
        os << warrior.name << ": " << warrior.strength;
        return os;
    }
}