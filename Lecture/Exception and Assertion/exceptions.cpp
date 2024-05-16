/*
  CS2124
  Exceptions and Assertions
  Inclass Sec B
*/

#include <iostream>
#include <vector>
#include <cstdlib>

#include <exception>
#include <stdexcept>
#include <cassert>

using namespace std;


void bar(int n) {
    if (n > 200) {
        // What to do?
	//throw n;
	throw out_of_range("bar");
    }
}
void foo(int n) { bar(n); }

int main() {
    try {
	foo(150);
    }
    // catch(out_of_range ex) {
    // 	cout << "Caught out_of_range exception: " << ex.what() << endl;;
    // }
    catch(const exception& ex) {
	cout << "Caught an exception: " << ex.what() << endl;;
    }
}
