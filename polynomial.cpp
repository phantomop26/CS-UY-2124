#include <iostream>
#include <vector>
#include "polynomial.h"

using namespace std;
Polynomial::Polynomial(): degree(0), head(new Term(0, 0, nullptr)) {}

//Constructor for a Polynomial object
Polynomial::Polynomial(const vector<int>& coeffs) {
    int numZeroes = 0;
    for (size_t i = 0; i < coeffs.size(); ++i) {
        if (coeffs[i] == 0) {
            numZeroes++;
        }
        else {
            break;
        }
    }
    Term* curs = nullptr; // short for cursor
    for (size_t i = numZeroes; i < coeffs.size(); ++i) {
        curs = new Term(coeffs[i], (coeffs.size() - 1) - i, curs);
    }

    // reverse the order of the nodes so largest exponent is first
    Term* prev = nullptr;
    Term* curr = curs;
    while (curr != nullptr) {
        Term* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    degree = coeffs.size() - numZeroes - 1;
}

//Destructor for Polynomial object
Polynomial::~Polynomial() {
    Term* curs = head;
    while (curs != nullptr) {
        Term* next = curs->next;
        delete curs;
        curs = next;
    }
    head = nullptr;
}

//Copy constructor for a Polynomial object
Polynomial::Polynomial(const Polynomial& other): degree(other.degree) {
    Term* curs = nullptr;
    Term* otherCurs = other.head;
    while (otherCurs != nullptr) {
        curs = new Term(otherCurs->coeff, otherCurs->exp, curs);
        otherCurs = otherCurs->next;
    }
    head = curs;
    // reverse the order of the nodes so largest exponent is first
    Term* prev = nullptr;
    Term* curr = head;
    while (curr != nullptr) {
        Term* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

//Assignment operator for a Polynomial object
Polynomial& Polynomial::operator=(const Polynomial& other) {
    if (this != &other) {
        degree = other.degree;
        Term* curs = head;
        while (curs != nullptr) {
            Term* next = curs->next;
            delete curs;
            curs = next;
        }
        curs = nullptr;
        Term* otherCurs = other.head;
        while (otherCurs != nullptr) {
            curs = new Term(otherCurs->coeff, otherCurs->exp, curs);
            otherCurs = otherCurs->next;
        }
        head = curs;
        // reverse the order of the nodes so largest exponent is first
        Term* prev = nullptr;
        Term* curr = head;
        while (curr != nullptr) {
            Term* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    return *this;
}

//Overloaded addition operator for two Polynomial objects
Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs) {
    Polynomial result = lhs;
    result += rhs;
    return result;
}

//Overloaded addition assignment operator for a Polynomial object
Polynomial& Polynomial::operator+=(const Polynomial& other) {
    Term* curs = head;
    Term* otherCurs = other.head;
    // perform addition
    while (curs != nullptr && otherCurs != nullptr) {
        if (curs->exp == otherCurs->exp) {
            curs->coeff += otherCurs->coeff;
            curs = curs->next;
            otherCurs = otherCurs->next;
        }
        else if (curs->exp > otherCurs->exp) {
            curs = curs->next;
        }
        else {
            Term* newNode = new Term(otherCurs->coeff, otherCurs->exp, curs);
            if (curs == head) {
                head = newNode;
            }
            else {
                Term* prev = head;
                while (prev->next != curs) {
                    prev = prev->next;
                }
                prev->next = newNode;
            }
            otherCurs = otherCurs->next;
        }
    }
    // add remaining terms
    while (otherCurs != nullptr) {
        Term* newTerm = new Term(otherCurs->coeff, otherCurs->exp, curs);
        if (curs == head) {
            head = newTerm;
        }
        else {
            Term* prev = head;
            while (prev->next != curs) {
                prev = prev->next;
            }
            prev->next = newTerm;
        }
        otherCurs = otherCurs->next;
    }
    // remove leading 0 coefficients
    curs = head;
    Term* prev = nullptr;
    while (curs != nullptr) {
        if (curs->coeff == 0) {
            Term* next = curs->next;
            delete curs;
            curs = next;
            if (prev == nullptr) {
                head = curs;
            }
            else {
                prev->next = curs;
            }
        }
        else {
            prev = curs;
            curs = curs->next;
        }
    }
    degree = head->exp;
    return *this;
}

//Checks if two Polynomial objects are equal
bool operator==(const Polynomial& lhs, const Polynomial& rhs) {
    if (lhs.degree != rhs.degree) {
        return false;
    }
    Polynomial::Term* lhsCurs = lhs.head;
    Polynomial::Term* rhsCurs = rhs.head;
    while (lhsCurs != nullptr && rhsCurs != nullptr) {
        if (lhsCurs->coeff != rhsCurs->coeff || lhsCurs->exp != rhsCurs->exp) {
            return false;
        }
        lhsCurs = lhsCurs->next;
        rhsCurs = rhsCurs->next;
    }
    return true;
}

//Checks if two Polynomial objects are not equal
bool operator!=(const Polynomial& lhs, const Polynomial& rhs) {
    return !(lhs == rhs);
}

//Evaluates this polynomial using Horner's method
double Polynomial::evaluate(double x) const {
    double result = 0;
    Term* curs = head;
    while (curs != nullptr) {
        result = result * x + curs->coeff;
        curs = curs->next;
    }
    return result;
}

//Overloaded output operator for a Polynomial object
ostream& operator<<(ostream& os, const Polynomial& poly) {
    for (Polynomial::Term* curs = poly.head; curs != nullptr; curs = curs->next) {
        if (curs->coeff != 0 || curs->exp == 0) {
            if (curs->coeff > 0 && curs != poly.head && curs->coeff > 0) {
                os << "+";
            }
            if (curs->coeff == -1 && curs->exp != 0) {
                os << "-";
            }
            else if (curs->coeff != 1 || curs->exp == 0) {
                os << curs->coeff;
            }
            if (curs->exp != 0) {
                os << "x";
                if (curs->exp != 1) {
                    os << "^" << (*curs).exp;
                }
            }
        }
    }
    return os;
}
