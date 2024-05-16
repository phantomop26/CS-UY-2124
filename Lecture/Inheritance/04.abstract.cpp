/*
  abstract.cpp
  Inclass Base
*/

#include <iostream>
using namespace std;

class Shape { // Abstract class
public:
    Shape(int x, int y) : x(x), y(y) {}
    void move(int x, int y) { this->x = x;  this->y = y; }
    //virtual void draw() { cout << "Default stuff... "; }
    virtual void draw() = 0; // Abstract method. Pure virtual
    //    void commonDrawingCode() { cout << "Drawing a "; }
private:
    int x, y;
};

void Shape::draw() { cout << "Drawing a "; }

class Triangle : public Shape {
public:
    Triangle(int x, int y) : Shape(x, y) {}
    //void draw() { cout << "Drawing a Triangle\n"; }
    void draw() {
        //        commoneDrawingCode();
        Shape::draw();
        cout << "Triangle\n"; 
    }
};

class Isosceles : public Triangle {
    using Triangle::Triangle;
};

class Circle : public Shape {
public:
    using Shape::Shape;
    //void draw() { cout << "Drawing a Circle\n"; }
    void draw() {
        //commoneDrawingCode();
        Shape::draw();
        cout << "Drawing a Circle\n";
    }
};

int main() {
    // Shape aShape(3,4);
    Triangle tri(3,4);
    tri.draw();
    Circle circ(10,10);
    circ.draw();

    Isosceles iso(7,12);
    iso.draw();
    
}
