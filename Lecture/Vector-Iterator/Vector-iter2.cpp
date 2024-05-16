/*
  Vector-iter.cpp
  Vector of ints
  Ranged-for support with Iterator
  Sec B - 24S
 */
#include <iostream>
using namespace std;


class Vector {
public:
    class Iterator {
        // op!=
        friend bool operator!=(const Iterator& lhs,
                               const Iterator& rhs) {
            return lhs.where != rhs.where;
        }
    public:
        Iterator(int* where) : where(where) {}

        // op++
        Iterator& operator++() {
            ++where;
            return *this;
        }

        // op*
        int& operator*() { 
            return *where;
        }
    private:
        int* where;
    };

    class Const_Iterator {
        // op!=
        friend bool operator!=(const Const_Iterator& lhs,
                               const Const_Iterator& rhs) {
            return lhs.where != rhs.where;
        }
    public:
        Const_Iterator(int* where) : where(where) {}

        // op++
        Const_Iterator& operator++() {
            ++where;
            return *this;
        }

        // op*
        int operator*() const { 
            return *where;
        }
    private:
        //int* where;
        const int* where;
    };
    
    explicit Vector(size_t howMany=0, int val=0)
    {
        theSize = howMany;
        theCapacity = howMany;
        data = new int[howMany];
        for (size_t i = 0; i < theSize; ++i) {
            data[i] = val;
        }
    } // Vector(howMany, val)

    // Copy control
    //   Destructor
    ~Vector()
    {
        delete [] data;
    } // ~Vector

    //   Copy Constructor
    Vector(const Vector& rhs)
    {
        theSize = rhs.theSize;
        theCapacity = rhs.theCapacity;
        data = new int[theCapacity];
        for (size_t i = 0; i < theSize; ++i) {
            data[i] = rhs.data[i];
        }
    } // Vector(Vector)

    //   Assignment Operator
    Vector& operator=(const Vector& rhs)
    {
        if (this != &rhs) {
            // Free up the old (destructor)
            delete [] data;
            // Allocate new
            data = new int[rhs.theCapacity];
            // Copy all the stuff
            theSize = rhs.theSize;
            theCapacity = rhs.theCapacity;
            for (size_t i = 0; i < theSize; ++i) {
                data[i] = rhs.data[i];
            }
        }
        // Return ourselves
        return *this;
    } // op=


    void push_back(int val)
    {
        if (theSize == theCapacity) {
            if (theCapacity == 0) {
                delete [] data;
                data = new int[1];
                theCapacity = 1;
            } else {
                int* oldData = data;
                theCapacity *= 2;
                data = new int[theCapacity];
                for (size_t i = 0; i < theSize; ++i) {
                    data[i] = oldData[i];
                }
                delete [] oldData;
            }
        }
        data[theSize++] = val;
    } // push_back

    size_t size() const { return theSize; }
    void pop_back() { --theSize; }

    void clear() { theSize = 0; };


    // Square brackets?
    int operator[](size_t index) const
    {
        return data[index];
    }
    int& operator[](size_t index)
    {
        return data[index];
    }
    
    // int* begin() { return data; }
    // int* end() { return data + theSize; } 
    Iterator begin() { return Iterator(data); }
    Iterator end() { return Iterator(data + theSize); } 

    // const int* begin() const { return data; }
    // const int* end() const { return data + theSize; } 
    Const_Iterator begin() const { return Const_Iterator(data); }
    Const_Iterator end() const { return Const_Iterator(data + theSize); } 


private:
    int* data;
    size_t theSize;
    size_t theCapacity;
};

void printVector(const Vector& v)
{
    // for (size_t i = 0; i < v.size(); ++i) {
    //     cout << v[i] << ' ';
    // }
    for (int val : v) {
        cout << val << ' ';
    }
    cout << endl;
    // for (int& val : v) {
    //     ++val;
    // }
} // printVector

int main() {

    // Not templated.  Our Vector class can only hold ints.
    Vector v;  

    v.push_back(17);
    v.push_back(42);
    v.push_back(6);
    v.push_back(28);
    printVector(v);
    
    v[0] = 100;

    Vector v2 = v;
    // printVector(v2);

    Vector v3;
    v3 = v;
    // printVector(v3);

    // v3 = Vector(17);
    // printVector(v2);

    // for (int val : v2) {
    //     cout << val << ' ';
    // }
    cout << endl;

    // for (int* p = v2.begin(); p != v2.end(); ++p) {
    //     int val = *p;
    //     cout << val << ' ';
    // }
    // for (Vector::Iterator iter = v2.begin(); iter != v2.end(); ++iter) {
    //     int val = *iter;
    //     cout << val << ' ';
    // }
    cout << endl;

    for (int& val : v2) {
        val *= 10;
    }
    for (Vector::Iterator iter = v2.begin(); iter != v2.end(); ++iter) {
        int& val = *iter;
        val *= 10;
    }
    for (Vector::Iterator iter = v2.begin(); iter != v2.end(); ++iter) {
        int val = *iter;
        cout << val << ' ';
    }
} // main

