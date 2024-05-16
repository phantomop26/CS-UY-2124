/*
  commas.cpp
  Yes, there is a comma operator
  But it does not mean the same thing as in Python
 */

#include <utility>
#include <iostream>
#include <string>
using namespace std;

//pair<int, bool> foo() {
auto foo() { // c++14
    //return 6, true;
    // pair<int, bool> result { 6, true };
    // return result;

    return make_pair(6, true);

}

void bar(auto val) {
    cout <<< val << endl;
}


int main() {
    int a = 17, b = 42;
    cout << a << ' ' << b << endl;
    a, b = b, a;

    cout << a << ' ' << b << endl;

    a, (b = b), a;    

    int tmp = a;
    a = b;
    b = tmp;

    swap(a, b);

    //pair<int, bool> val = foo();
    auto val = foo();
    cout << val.first << ' ' << val.second << endl;

    // "Structured Unbinding"
    auto [who, what] = foo(); // c++17
}
