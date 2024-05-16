#include <vector>
#include <string>
#include <iostream>

#ifndef NOBLE_H
#define NOBLE_H
namespace WarriorCraft {
    class Warrior;
    class Noble {
    public:
        Noble(const std::string& name);
        const std::string& getName() const;
        bool hire(Warrior& warrior);
        bool fire(Warrior& warrior);
        void battle(Noble& otherNoble);
        void uponDeath();
        friend std::ostream& operator<<(std::ostream& os, const Noble& otherNoble);
    private:
        std::string name;
        double strength;
        bool alive;
        std::vector<Warrior*> army;
    };
}
#endif