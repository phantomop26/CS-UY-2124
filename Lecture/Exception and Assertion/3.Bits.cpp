/*
  3.Bits
  - What is the recursion involved in splitting a non-negative integer
    "apart" into its digits?
  - What about into its bits?

  - jbs
 */

#include <iostream>
using namespace std;

void printDigits(int n) {
}

void printDigitsReverse(int n) {
    if (n < 10) {
	cout << n << ' ';
    } else {
	cout << n % 10 << ' ';
	printDigitsReverse(n/10);
    }
}

void printBitsReverse(int n) {
    if (n < 2) {
	cout << n << ' ';
    } else {
    // cout<<n<<" ";
	cout << n % 2 << ' ';
	printBitsReverse(n/2);
    }
}

int countOnes(int n) {
    if (n < 2) return n;
    int count = countOnes(n/2);
    if (n % 2 == 1) ++count;
    return count;
}

int main() {
    // cout << "printDigits(314159);   ";
    // printDigitsReverse(314159);
    cout << endl;
    printBitsReverse(10);
    // cout<<countOnes(11);

    // cout << endl;
    // cout << "printDigitsR1(314159); ";
    // // printDigitsR1(314159);
    // cout << endl;
    // cout << "printDigitsR2(314159); ";
    // // printDigitsR2(314159);
    // cout << endl;


    // cout << "printBits(5): ";
    // // printBits(5);
    // cout << endl;

    // //cout << "countBits(5): " << countBits(5) << endl;

    // cout << "printBits(16): ";
    // // printBits(16);
    // cout << endl;

    // //cout << "countBits(16): " << countBits(16) << endl;    

}
// class Square {
// public:
//  Square(int side_length = 1) : length(side_length) {}
//  virtual double calc_area() const {
//  return length * length;
//  }
//  protected:
//  double get_length() const { return length; }
// private:
//  double length;
// };
// class Rectangle: public Square {
// public:
//  Rectangle(double width = 1) : width(width) {}
//  double calc_area() const {
//  return get_length() * width;
//  }
// private:
//  double width;
// };
// void display_area(Square sq) {
//  cout << sq.calc_area();
// }
// int main() {
//  Rectangle rect(4);
//  display_area(rect);
// }
