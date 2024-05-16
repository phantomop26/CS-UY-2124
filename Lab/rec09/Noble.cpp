#include <vector>
#include <string>
#include <iostream>
#include "Noble.h"
#include "Warrior.h"
using namespace std;

namespace WarriorCraft {
    Noble::Noble(const string& name): 
    name(name), strength(0), alive(true) {}
    const string& Noble::getName() const {
        return name;
    }
    bool Noble::hire(Warrior& warrior) {
        if (!alive) {
            cout << name << " is dead -- they cannot hire anymore." << endl;
            return false;
        }
        else if (warrior.isHired()) {
            cout << name <<" failed to hire "<< warrior.getName()<< endl;
            return false;
        }
        else {
            warrior.setEmployer(this);
            army.push_back(&warrior);
            strength += warrior.getStrength();
            return true;}
    }
    bool Noble::fire(Warrior& warrior) {  
    size_t warriorPosition = army.size();
    for (size_t i = 0; i < army.size(); ++i) {
        if (alive && army[i] == &warrior) {
            cout << warrior.getName() << " you're fired! -- "
                << name << endl;
            warriorPosition = i;
            strength -= warrior.getStrength();
            warrior.setEmployer(nullptr);
        }
    }
    if (warriorPosition < army.size()) {
        for (size_t i = warriorPosition; i < army.size() - 1; ++i) {
            army[i] = army[i + 1];
        }
        army.pop_back();
        return true;
    }
    else {
        cout << "Couldn't find " << warrior.getName() << " in " << name
            << "'s army!" << endl;
        return false;
    }
}
    void Noble::uponDeath() {
        for (size_t i = 0; i < army.size(); ++i) {
            army[i]->setStrength(0);
        }
        strength = 0;
        alive = false;
    }
    void Noble::battle(Noble& otherNoble) {
        cout << name << " battles " << otherNoble.name << endl;
        if (!alive && !otherNoble.alive) {
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        }
        else if (!alive) {
            cout << "He's dead, " << otherNoble.name << endl;
        }
        else if (!otherNoble.alive) {
            cout << "He's dead, " << name << endl;
        }
        else if (strength == otherNoble.strength) {
            cout << "Mutual Annihilation: " << name << " and " << otherNoble.name
                << " die at each other's hands" << endl;
            uponDeath();
            otherNoble.uponDeath();
        }
        else if (strength > otherNoble.strength) {
            cout << name << " defeats " << otherNoble.name << endl;
            double ratio = (strength - otherNoble.strength) / strength;
            for (size_t i = 0; i < army.size(); ++i) {
                army[i]->setStrength(army[i]->getStrength() * ratio);
            }
            strength = strength * ratio;
            otherNoble.uponDeath();
        }
        else {
            cout << otherNoble.name << " defeats " << name << endl;
            double ratio = (otherNoble.strength - strength) / otherNoble.strength;
            for (size_t i = 0; i < otherNoble.army.size(); ++i) {
                otherNoble.army[i]->setStrength(otherNoble.army[i]->getStrength() * ratio);
            }
            otherNoble.strength = otherNoble.strength * ratio;
            uponDeath();
        }
    }
    ostream& operator<<(ostream& os, const Noble& noble) {
        os << noble.name << " has an army of " << noble.army.size() << endl;
        for (size_t i = 0; i < noble.army.size(); ++i) {
            os << "\t" << *noble.army[i] << endl;
        }
        return os;
    }
}