/*
  bounds checking
  CS2124
  Inclass Sec A
*/

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void somefunc() {


    vector<int> v;

    v.push_back(49);

    // What happens heere?
    v[17] = 42;

    cout << v[17] << endl;
    cout << v.at(17) << endl;
}


int main() {

    // vector<int> v;

    // v.push_back(49);

    // // What happens heere?
    // v[17] = 42;

    // cout << v[17] << endl;
    // cout << v.at(17) << endl;

    try {
	somefunc();
    }
    catch (out_of_range ex) {
	cout << "cought an out_of_range exception\n";
    }

    cout << "Still running\n";
}
