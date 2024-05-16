#include <string>
#include <vector>

#ifndef WARRIORCRAFT_PROTECTOR_H
#define WARRIORCRAFT_PROTECTOR_H
namespace WarriorCraft {
    class Lord; // forward declaration

    class Protector {
    public:
        Protector(const std::string& name, double strength);
        const std::string& getName() const;
        double getStrength() const;
        void setStrength(double strength);
        Lord* const getLord() const;
        void setLord(Lord* lord);
        bool runaway();
        virtual void battleCry() const = 0;
        friend std::ostream& operator<<(std::ostream& os, const Protector& protector);
    private:
        std::string name;
        double strength;
        bool alive;
        Lord* lord;
    };

    class Wizard: public Protector {
    public:
        Wizard(const std::string& name, double strength);
        void battleCry() const;
    };

    class Warrior: public Protector {
    public:
        Warrior(const std::string& name, double strength);
    };

    class Archer: public Warrior {
    public:
        Archer(const std::string& name, double strength);
        void battleCry() const;
    };

    class Swordsman: public Warrior {
    public:
        Swordsman(const std::string& name, double strength);
        void battleCry() const;
    };
}
#endif //WARRIORCRAFT_PROTECTOR_H