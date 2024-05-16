#include <string>
#include <vector>
#include <iostream>
#include "Noble.h"
#include "Protector.h"

using namespace std;

namespace WarriorCraft {
    //Base constructor for a Noble
    Noble::Noble(const string& name, double strength): name(name), strength(strength), alive(true) {}

    //Get the name of the Noble
    const string& Noble::getName() const {
        return name;
    }

    //Get the strength of the Noble
    double Noble::getStrength() const {
        return strength;
    }

    //Set the strength of the Noble
    void Noble::setStrength(double strength) {
        this->strength = strength;
    }

    //Return true if the Noble is alive, false otherwise
    bool Noble::isAlive() const {
        return alive;
    }

    //Simulate a battle between two Nobles
    void Noble::battle(Noble& other) {
        cout << name << " battles " << other.name << endl;

        if (!alive && !other.alive) {
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        }

        else if (!alive) {
            other.battleCry();
            cout << "He's dead, " << other.name << endl;
        }
        else if (!other.alive) {
            battleCry();
            cout << "He's dead, " << name << endl;
        }
        
        else {
            battleCry();
            other.battleCry();
            double ratio = other.strength / strength;
            postBattle(ratio);
            other.postBattle(1 / ratio);
            if (strength > other.strength) {
                cout << name << " defeats " << other.name << endl;
            }
            else if (strength < other.strength) {
                cout << other.name << " defeats " << name << endl;
            }
            else {
                cout << "Mutual Annihilation: " << name << " and " << other.name << " die at each other's hands" << endl;
            }
        }

    }

    //Update the Noble's strength after a battle
    void Noble::postBattle(double ratio) {
        if (ratio >= 1) {
            strength = 0;
            alive = false;
        }
        else
            strength = strength * (1 - ratio);
    }

    //Print the Noble's current status
    ostream& operator<<(ostream& os, const Noble& noble) {
        return noble.print(os);
    }

    //Construct a new Lord object
    Lord::Lord(const string& name): Noble(name) {}

    bool Lord::hires(Protector& protector) {
        if (isAlive() && protector.getLord() == nullptr) {
            army.push_back(&protector);
            protector.setLord(this);
            setStrength(getStrength() + protector.getStrength());
            return true;
        }
        else{
            cout<<getName()<<" failed to hire "<< protector.getName()<<endl;
            return false; // protector already has a lord
        }
    }

    //Fire a Protector from the Lord's army
    bool Lord::fires(Protector& protector, bool runaway) {
        for (size_t i = 0; i < army.size(); ++i) {
            if (army[i] == &protector) {
                if (!runaway)
                    cout << protector.getName() << ", you don't work for me anymore ! -- " << getName() << endl;
                setStrength(getStrength() - protector.getStrength());
                protector.setLord(nullptr);
                for (size_t j = i; j < army.size() - 1; ++j) {
                    army[j] = army[j + 1];
                }
                army.pop_back();
                return true;
            }
        }
        cout << "Couldn't find " << protector.getName() << " in " << getName() << "'s army!" << endl;
        return false;
    }

    //Display the Lord's battle cry
    void Lord::battleCry() const {
        for (size_t i = 0; i < army.size(); ++i) {
            army[i]->battleCry();
        }
    }

    //Update the Lord's army after a battle
    void Lord::postBattle(double ratio) {
        Noble::postBattle(ratio);
        for (size_t i = 0; i < army.size(); ++i) {
            if (ratio >= 1) // if lord is dead, all his army dies
                army[i]->setStrength(0);
            else
                army[i]->setStrength(army[i]->getStrength() * (1 - ratio));
        }
    }

    //Output the Lord's current status
     ostream& Lord::print(ostream& os) const {
        os << getName() << " has an army of size: " << army.size();
        for (size_t i = 0; i < army.size(); ++i) {
            os << "\n\t" << *army[i];
        }
        return os;
    }

    //Construct a new PersonWithStrengthToFight object  
    PersonWithStrengthToFight::PersonWithStrengthToFight(const string& name, double strength): Noble(name, strength) {}

    void PersonWithStrengthToFight::battleCry() const {
        cout << "Ugh!" << endl;
    }

    //Output the PersonWithStrengthToFight's current status
    ostream& PersonWithStrengthToFight::print(ostream& os) const {
        os << getName() << " has strength: " << getStrength();
        return os;
    }
}