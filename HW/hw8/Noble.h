#include <string>
#include <vector>

#ifndef WARRIORCRAFT_NOBLE_H
#define WARRIORCRAFT_NOBLE_H
namespace WarriorCraft {
    class Protector; // forward declaration

    class Noble {
    public: // methods accessible to all
        Noble(const std::string& name, double strength = 0);
        const std::string& getName() const;
        double getStrength() const;
        bool isAlive() const;
        void battle(Noble& other);
        friend std::ostream& operator<<(std::ostream& os, const Noble& noble);
    protected: // methods only accessible to derived classes
        virtual std::ostream& print(std::ostream& os) const = 0;
        virtual void battleCry() const = 0;
        virtual void postBattle(double ratio);
        void setStrength(double strength);
    private: // fields only accessible to this class
        std::string name;
        double strength;
        bool alive;
    };

    class Lord: public Noble {
    public:
        Lord(const std::string& name);
        bool hires(Protector& protector);
        bool fires(Protector& protector, bool runaway = false);
    private: // methods only accessible to this class
        void battleCry() const;
        void postBattle(double ratio);
        std::ostream& print(std::ostream& os) const;
        std::vector<Protector*> army;
    };

    class PersonWithStrengthToFight: public Noble {
    public:
        PersonWithStrengthToFight(const std::string& name, double strength);
    private:
        void battleCry() const;
        std::ostream& print(std::ostream& os) const;
    };
}
#endif //WARRIORCRAFT_NOBLE_H