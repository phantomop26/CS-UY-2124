/*
  03.protected.cpp
  Inclass Base
*/

#include <iostream>
using namespace std;

class Base {
    friend ostream& operator<<(ostream& os, const Base& base) {
        return os <<  "x: " << base.x; 
    }
public:
    Base(int x) : x(x) {}
    //int getX() const { return x; }

protected:   
    void setX(int val) { x = val; }
    // // void setX(int x) { this->x = x; }

private:
    int x;
};

class Derived : public Base {
public:

    Derived(int x) : Base(x) {}
    void derivedSettingX() {
        // x = 42;  
        setX(42);
    }
};

int main() {
    Derived d(10);
    d.derivedSettingX();
    cout << d << endl;
}
