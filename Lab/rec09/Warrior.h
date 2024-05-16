#include <string>
#include <iostream>

#ifndef WARRIOR_H
#define WARRIOR_H
namespace WarriorCraft {
    class Noble; 
    class Warrior {
    public:
        Warrior(const std::string& name, double strength);
        const std::string& getName() const;
        const double getStrength() const;
        void setStrength(double strength);
        const Noble* getEmployer() const;
        void setEmployer(Noble* employer);
        bool isHired() const;
        bool runaway();
        friend std::ostream& operator<<(std::ostream& os, const Warrior& warrior);
    private:
        std::string name;
        double strength;
        Noble* employer;
    };
}
#endif