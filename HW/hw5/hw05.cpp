
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BigUnsigned {
     private:
          vector<int> digits;
     public:
          BigUnsigned() {
          digits = {0};
     }

     BigUnsigned(int num) {
          if(num == 0) {
          digits = {0};
          }
          else {
               while(num > 0) {
                    digits.insert(digits.begin(), num % 10);
                    num /= 10;
               }
          }
     }

     BigUnsigned(string str) {
          digits.clear();
          size_t i = 0;
          while(i < str.length() && !isdigit(str[i])) {
               i++;
          }
          while(i < str.length()) {
               if(isdigit(str[i])) {
                    digits.push_back(str[i] - '0'); // add digit to back
               }
               else{
                    break;
               }
               i++;
          }
     }

     friend ostream& operator<<(ostream& os, const BigUnsigned& num);
    
     BigUnsigned operator+(const BigUnsigned& rhs) const{
          BigUnsigned result;
          result.digits.clear();
          int carry = 0;
          int i = 0;
          for(size_t i = 0; i < digits.size() || i < rhs.digits.size(); i++) {
               int x = 0;
               if(i < digits.size()){
                    x = digits[i];
               } 
               if(i < rhs.digits.size()){
                    x += rhs.digits[i];
               } 
               x += carry;

               result.digits.push_back(x % 10);
               carry = x / 10;
          }

          if(carry > 0) {
               result.digits.push_back(carry); 
          }

          vector<int> trimmed;
          i = 0;
          while(i < result.digits.size() && result.digits[i] == 0) {
               i++;
          }
  
          for(size_t i =0; i < result.digits.size(); i++) {
               trimmed.push_back(result.digits[i]);
          }
          result.digits = trimmed;
          return result;
     }
     BigUnsigned& operator+=(const BigUnsigned& rhs){
          *this = *this + rhs;
          return *this;
     }
     bool operator==(const BigUnsigned& rhs) const{
          return digits == rhs.digits;
     }
     bool operator!=(const BigUnsigned& rhs) const{
          return !(*this == rhs); 
     }
     bool operator<(const BigUnsigned& rhs) const{
          if(digits.size() != rhs.digits.size())
               return digits.size() < rhs.digits.size();
          for(int i = digits.size()-1; i >= 0; i--) {
               if(digits[i] != rhs.digits[i]){
                    return digits[i] < rhs.digits[i];
               }
                    
          }
          return false;
     }
    
     bool operator<=(const BigUnsigned& rhs) const{
          return (*this < rhs) || (*this == rhs);
     }

     bool operator>(const BigUnsigned& rhs) const{
          return !(*this <= rhs);
     }
    
     bool operator>=(const BigUnsigned& rhs) const{
          return !(*this < rhs);
     }
    
     BigUnsigned& operator++(){
          int carry = 1;
          for(int i = 0; i < digits.size(); i++) {
               digits[i] += carry;
               if(digits[i] <= 9) {
                    carry = 0;
                    break;
               }
               digits[i] = 0;
          }
          if(carry) {
               digits.insert(digits.begin(), 1);
          }
          return *this;
     }
    
     BigUnsigned operator++(int){
          BigUnsigned temp = *this;
          ++*this;
          return temp; 
     }

     operator bool() const {
          return digits.size() > 0; 
     }

     bool operator==(const int& rhs) const {
          return *this == BigUnsigned(rhs);
     }
    
};



int main() {
    BigUnsigned zero;
    BigUnsigned one = {1};

    cout << "zero: " << zero << endl;
    cout << "one: " << one << endl;

    BigUnsigned val = 1;
    cout << "val: " << val << endl;
    cout << "++val: " << ++val << endl;
    cout << "val: " << val << endl;
    cout << "val++: " << val++ << endl;
    cout << "val: " << val << endl;
    
    cout << "(one + zero): " << (one + zero) << endl;
    cout << "(one + one): " <<  (one + BigUnsigned(1)) << endl;

    cout << boolalpha;
    cout << "one < one: " << (one < one) << endl;
    cout << "zero < one: " << (zero < one) << endl;

    BigUnsigned a = 123;
    BigUnsigned b = 1234;
    BigUnsigned c = 124;
    BigUnsigned d = 12345;

    cout << "a: " << a << ", b: " << b 
         << ", c: " << c << ", d: " << d << endl;
    cout << "a + d: " << (a + d) << endl;
    cout << "d + d: " << (d + BigUnsigned(12345)) << endl;
    cout << "a < d: " << (a < d) << endl;
    cout << "d < a: " << (d < a) << endl;
    cout << "zero == zero: " << (zero == zero) << endl
         << "zero == one: " << (zero == one) << endl
         << "a == a: " << (a == a) << endl
         << "a == d: " << (a == d) << endl
         << "d == a: " << (d == a) << endl;

    cout << "(zero == 0): " << (zero == 0) << endl
         << "(one == 0): " << (one == 0) << endl
         << "(1 == one): " << (1 == one) << endl;

    // +=
    cout << "b: " << b << ", c: " << c << endl;
    cout << "(c += b): " << (c += b) << endl;
    cout << "b: " << b << ", c: " << c << endl;


    BigUnsigned x = a;
    cout << "x: " << x << ", a: " << a << endl
         << "x == a: " << (x == a) << endl
         << "a == x: " << (a == x) << endl
         << "a < x: " << (a < x) << endl
         << "a > x: " << (a > x) << endl;
    
    cout << "x > a: " << (x > a) << endl
         << "x >= a: " << (x >= a) << endl
         << "x <= a: " << (x <= a) << endl
         << "x != a: " << (x != a) << endl;
         
    
    BigUnsigned big("987654321");
    BigUnsigned big2(" ");
    BigUnsigned big3("felix");
    BigUnsigned big4("00987654321");

    cout << "big: " << big << endl
         << "big2: " << big2 << endl
         << "big3: " << big3 << endl
         << "big4: " << big4 << endl;

    BigUnsigned big5(98765);
    BigUnsigned big6(2457);
    cout << "big5: " << big5  << ", big6: " <<  big6 << endl
         << "(big5 + big6): " << (big5 + big6) << endl
         << "(big6 + big5): " << (big6 + big5) << endl;


    cout << zero << " is " << (zero ? "true" : "false") << endl;
    cout << one << " is " << (one ? "true" : "false") << endl;
    cout << big4 << " is " << (big4 ? "true" : "false") << endl;
}

ostream& operator<<(ostream& os, const BigUnsigned& num) {
  for(int i = 0; i < num.digits.size(); i++) {
    os << num.digits[i];
  }
  return os;
}